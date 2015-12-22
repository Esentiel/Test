#pragma once
#include <string>
#include <memory>
#include <vector>
#include <stack>
#include "Variant.h"
#include "usrlib.h"

class ReversePolandNotation
{
public:
    std::string performCalculation(const std::string &formula)  const;
private:
    int getPriority(const char character) const;
    std::vector<std::string> parseFormula(const std::string &formula) const;
    std::string evaluateFormula(const std::vector<std::string> &rpFormula) const;
};

