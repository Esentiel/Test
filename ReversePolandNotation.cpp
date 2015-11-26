#include "ReversePolandNotation.h"
/*
template <class T>
class Operand;

template <>
class Operand<std::string>
{
	std::string value;
public:
	Operand() {};
	Operand(std::string initValue)
	{
		value = initValue;
	};

	Operand <std::string> operator+(Operand<std::string> const &b) const
	{
		Operand<std::string> str(*this);
		str.setValue(str.getValue() + b.getValue());
		return str;
	}

	Operand <std::string> operator+(Operand<int> const &b) const;

	Operand <std::string> operator*(Operand<int> const &b) const;

	std::string getValue() const
	{
		return value;
	}

	void setValue(std::string initValue)
	{
		value = initValue;
	}
};

template <class T>
class Operand
{
	T value;
public:
	Operand() {};
	Operand(T initValue)
	{
		value = initValue;
	}

	Operand<T> operator-(Operand<T> const &b) const
	{
		Operand<T> integ(*this);
		integ.setValue(integ.getValue() - b.getValue());
		return integ;
	}
	
	Operand<T> operator/(Operand<T> const &b) const
	{
		Operand<T> integ(*this);
		integ.setValue(integ.getValue() / b.getValue());
		return integ;
	}

	Operand<T> operator+(Operand<T> const &b) const
	{
		Operand<T> integ(*this);
		integ.setValue(integ.getValue() + b.getValue());
		return integ;
	}

	Operand<std::string> operator+(Operand<std::string> const &b) const
	{
		Operand<std::string> str(std::to_string(this->getValue()));
		str.setValue(str.getValue() + b.getValue());
		return str;
	}

	Operand<T> operator*(Operand<T> const &b) const
	{
		Operand<T> integ(*this);
		integ.setValue(integ.getValue() * b.getValue());
		return integ;
	}

	Operand<std::string> operator*(Operand<std::string> const &b) const
	{
		Operand<std::string> str(b);
		int n = this->getValue();
		std::string strPart = str.getValue();

		while (n--)
		{
			str.setValue(str.getValue() + strPart);
		}

		return str;
	}

	T getValue() const
	{
		return value;
	}

	void setValue(T initValue)
	{
		value = initValue;
	}
};


Operand<std::string> Operand<std::string>::operator+(const Operand<int>& b) const
{
	Operand<std::string> str(*this);
	str.setValue(str.getValue() + std::to_string(b.getValue()));
	return str;
}

Operand<std::string> Operand<std::string>::operator*(const Operand<int>& b) const
{
	Operand<std::string> str(*this);
	int n = b.getValue();
	std::string strPart = str.getValue();

	while (n--)
	{
		str.setValue(str.getValue() + strPart);
	}

	return str;
}

*/

ReversePolandNotation::ReversePolandNotation()
{
}

int ReversePolandNotation::getPriority(char const character) const
{
	return
		character == '+' || character == '-' ? 2 :
		character == '*' || character == '/' ? 3 :
		character == '(' ? 1 :
		character == ')' ? 0 :
		-1;
}

bool ReversePolandNotation::isAlphaNum(std::string const &str) const
{
	for (auto element : str)
	{
		if (!isalnum(element))
			return false;
	}
	return true;
}

bool ReversePolandNotation::isDigit(std::string const &str) const
{
	for (auto element : str)
	{
		if (!isdigit(element))
			return false;
	}
	return true;
}

bool ReversePolandNotation::isAlpha(std::string const &str) const
{
	for (auto element : str)
	{
		if (!isalpha(element))
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
	Variant val1;
	Variant val2;
	Variant result; 
	//std::string result;
	std::unique_ptr <std::stack <Variant>> numbers = std::make_unique<std::stack <Variant>>();
	for (auto element : rpFormula)
	{
		if (isAlphaNum(element))
		{
			numbers->push(Variant (element));
		}
		else {
			val2 = numbers->top();
			numbers->pop();
			val1 = numbers->top();
			numbers->pop();
			switch(element.at(0))
			{
				case '+':
					numbers->push(val1 + val2);
					break;
				case '-':
					numbers->push(val1 - val2);
					break;
				case '*':
					numbers->push(val1 * val2);
					break;
				case '/':
					numbers->push(val1 / val2);
					break;
			}
		}
	}
	result = numbers->top();
	numbers->pop();
	return result.asString();
}

std::string ReversePolandNotation::performCalculation(std::string &formula)
{
	return evaluateFormula(parseFormula(formula));
}
/*
std::string ReversePolandNotation::makeCalculations(std::string const &val1, std::string const &val2, char const sign) const
{
	if (isDigit(val1) && isDigit(val2))
	{
		Operand<int> operand1(std::atoi(val1.c_str()));
		Operand<int> operand2(std::atoi(val2.c_str()));
		switch (sign)
		{
		case '*':
			return std::to_string((operand1 * operand2).getValue());
			break;
		case '-':
			return std::to_string((operand1 - operand2).getValue());
			break;
		case '/':
			return std::to_string((operand1 / operand2).getValue());
			break;
		case '+':
			return std::to_string((operand1 + operand2).getValue());
			break;
		}
	}
	else if(isDigit(val1) && isAlpha(val2))
	{
		Operand<int> operand1(std::atoi(val1.c_str()));
		Operand<std::string> operand2(val2);
		switch (sign)
		{
		case '*':
			return (operand1 * operand2).getValue();
			break;
		case '+':
			return (operand1 + operand2).getValue();
			break;
		}
	}
	else if (isAlpha(val1) && isAlpha(val2))
	{
		Operand<std::string> operand1(val1);
		Operand<std::string> operand2(val2);
		switch (sign)
		{
		case '+':
			return (operand1 + operand2).getValue();
			break;
		}
	}
	else if(isAlpha(val1) && isDigit(val2))
	{
		Operand<std::string> operand1(val1);
		Operand<int> operand2(std::atoi(val2.c_str()));
		switch (sign)
		{
		case '*':
			return (operand1 * operand2).getValue();
			break;
		case '+':
			return (operand1 + operand2).getValue();
			break;
		}
	}
	return "#Calculation Error";
}
*/

ReversePolandNotation::~ReversePolandNotation()
{
}
