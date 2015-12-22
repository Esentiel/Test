#pragma once

#include "Cell.h"

class StringCell : public Cell
{
public:
    explicit StringCell(const std::string value);
    void evaluate(){outputValue = inputValue.replace(0, 1, "");}
    std::string & getOutput() {return outputValue;}
private:
    std::string inputValue;
    std::string outputValue;
};
