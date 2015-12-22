#include "ReversePolandNotation.h"

int ReversePolandNotation::getPriority(const char character) const
{
	return
		character == '+' || character == '-' ? 2 :
		character == '*' || character == '/' ? 3 :
		character == '(' ? 1 :
		character == ')' ? 0 :
		-1;
}

std::vector<std::string> ReversePolandNotation::parseFormula(const std::string &formula)  const
{
	std::vector<std::string> output;
    std::unique_ptr <std::stack <char>> signs = std::make_unique<std::stack <char>>();
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
            }else {
				output.back().append(1, element);
			}
        }else
        {
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
            }else if (priority == 1)
			{
				//add '(' to the stack
				signs->push(element);
            }else if (priority == 0)
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
    //move all signs to a vector
	while (signs->size() != 0)
	{
		output.push_back(std::string(1, signs->top()));
		signs->pop();
	}
    return std::move(output);
}

std::string ReversePolandNotation::evaluateFormula(const std::vector<std::string> &rpFormula)  const
{
	Variant val1;
	Variant val2;
	Variant result; 
	std::unique_ptr <std::stack <Variant>> numbers = std::make_unique<std::stack <Variant>>();

    for (auto const &element : rpFormula)
	{
        if (usrlib::isAlphaNum(element))
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
    return std::move(result.asString());
}

std::string ReversePolandNotation::performCalculation(const std::string &formula) const
{
	return evaluateFormula(parseFormula(formula));
}

