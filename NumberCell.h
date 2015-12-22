#pragma once

#include "Cell.h"

class NumberCell : public Cell
{
public:
	NumberCell(const std::string value);
    void evaluate(){outputValue = inputValue;}
    std::string & getOutput() {return outputValue;}
private:
    std::string inputValue;
    std::string outputValue;
};
