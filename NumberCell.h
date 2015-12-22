#pragma once

#include "Cell.h"

class NumberCell : public Cell
{
public:
	NumberCell(const std::string value);
	virtual void evaluate();
    virtual std::string & getOutput() {return outputValue;}
	virtual ~NumberCell();
private:
    std::string inputValue;
    std::string outputValue;
};
