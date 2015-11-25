#pragma once
#include <string>
#include <memory>
#include <vector>
#include <stack>
#include <iostream>
#include "Variant.h"

class ReversePolandNotation
{
private:
	int getPriority(char const character) const;
	bool isAlphaNum(std::string const &str) const;
	bool isDigit(std::string const &str) const;
	bool isAlpha(std::string const &str) const;
	std::vector<std::string> parseFormula(std::string const &formula);
	std::string evaluateFormula(std::vector<std::string> rpFormula);
	//std::string makeCalculations(std::string const &operand1, std::string const &operand2, char const sign) const;
public:
	ReversePolandNotation();
	std::string performCalculation(std::string &formula);
	~ReversePolandNotation();
};

