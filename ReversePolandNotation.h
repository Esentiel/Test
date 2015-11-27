#pragma once
#include <string>
#include <memory>
#include <vector>
#include <stack>
#include "Variant.h"

class ReversePolandNotation
{
public:
    ReversePolandNotation();
    std::string performCalculation(const std::string &formula)  const;
    ~ReversePolandNotation();
private:
    int getPriority(const char character) const;
    bool isAlphaNum(const std::string &str) const;
    bool isDigit(const std::string &str) const;
    bool isAlpha(const std::string &str) const;
    std::vector<std::string> parseFormula(const std::string &formula) const;
    std::string evaluateFormula(const std::vector<std::string> &rpFormula) const;
};

