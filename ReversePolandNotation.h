#pragma once
#include <string>
#include <memory>
#include <vector>
#include <stack>
#include "IntOperand.h"
#include "StringOperand.h"

class ReversePolandNotation
{
private:
	int getPriority(char const character);
	bool isAlphaNum(std::string const &str);
	bool isDigit(std::string const &str);
	std::vector<std::string> parseFormula(std::string const &formula);
	std::string evaluateFormula(std::vector<std::string> rpFormula);
public:
	ReversePolandNotation();
	std::string performCalculation(std::string &formula);
	~ReversePolandNotation();
};

