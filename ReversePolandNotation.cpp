#include "ReversePolandNotation.h"
/*
template <class T>
class Operator
{
private:
	T value;
protected:
	T Operator::operator-(T const &a, T const &b) const
	{
		return a - b;
	}
	
	T Operator::operator/(T const &a, T const &b) const
	{
		return a / b;
	}

	T Operator::operator+(T const &a, T const &b) const
	{
		return a + b;
	}

	T Operator::operator*(T const &a, T const &b) const
	{
		return a * b;
	}

	T getValue() const
	{
		return value;
	}

	int getIntValue() const
	{
		return std::atoi(value);
	}
};

template <>
class Operator <std::string>
{
	std::string Operator::operator*(std::string const &a, std::string const &b) const
	{
		return a * b;
	}
};*/




ReversePolandNotation::ReversePolandNotation()
{
}

int ReversePolandNotation::getPriority(char const character)
{
	return
		character == '+' || character == '-' ? 2 :
		character == '*' || character == '/' ? 3 :
		character == '(' ? 1 :
		character == ')' ? 0 :
		-1;
}

bool ReversePolandNotation::isAlphaNum(std::string const &str)
{
	for (auto element : str)
	{
		if (!isalnum(element))
			return false;
	}
	return true;
}

bool ReversePolandNotation::isDigit(std::string const &str)
{
	for (auto element : str)
	{
		if (!isdigit(element))
			return false;
	}
	return true;
}

std::vector<std::string> ReversePolandNotation::parseFormula(std::string const &formula)
{
	std::vector<std::string> output;
	std::shared_ptr <std::stack <char>> signs = std::make_shared<std::stack <char>>();
	char previousChar = '_';
	//
	for (auto element: formula)
	{
		int const priority = getPriority(element);
		if (isalnum(element))
		{
			//check if current char is a part of a number
			if (!isalnum(previousChar))
			{
				output.push_back(std::string(1, element));
			}
			else {
				output.back().append(1, element);
			}
		}
		else
		{//todo: move all "else" to a distinct method
			if (priority >= 2)
			{
				//in case priority of signs in stack are equal or greater than current sign
				while ((signs->size() != 0) && (getPriority(signs->top()) >= priority))//signs may be empty!!!
				{
					output.push_back(std::string(1, signs->top()));//inline function?
					signs->pop();
				}
				//add current sign to the stack
				signs->push(element);
			}
			else if (priority == 1)
			{
				//add '(' to the stack
				signs->push(element);
			}
			else if (priority == 0)
			{
				//find '('
				while (getPriority(signs->top()) != 1)
				{
					output.push_back(std::string(1, signs->top()));
					signs->pop();
				}
				signs->pop();
			}

		}
		//get prev char
		previousChar = element;
	}
	//distinct method
	while (signs->size() != 0)
	{
		output.push_back(std::string(1, signs->top()));
		signs->pop();
	}
	return output;
}

//TODO: refactoring due to new implementation
std::string ReversePolandNotation::evaluateFormula(std::vector<std::string> rpFormula)
{
	int val1, val2;
	std::string result;
	std::unique_ptr <std::stack <int>> numbers = std::make_unique<std::stack <int>>();
	for (auto element : rpFormula)
	{
		if (isAlphaNum(element))
		{
			numbers->push(atoi(element.c_str()));
		}
		else {
			val2 = numbers->top();
			numbers->pop();
			val1 = numbers->top();
			numbers->pop();
			switch (element.at(0))
			{
			case '*':
				numbers->push(val1 * val2);
				break;
			case '-':
				numbers->push(val1 - val2);
				break;
			case '/':
				numbers->push(val1 / val2);
				break;
			case '+':
				numbers->push(val1 + val2);
				break;
			}
		}
	}
	result = std::to_string(numbers->top());
	numbers->pop();
	return result;
}

std::string ReversePolandNotation::performCalculation(std::string &formula)
{
	return evaluateFormula(parseFormula(formula));
}


ReversePolandNotation::~ReversePolandNotation()
{
}