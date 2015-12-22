#pragma once

#include "Cell.h"

class StringCell : public Cell
{
public:
	StringCell(const std::string value);
	virtual void evaluate();
    virtual std::string & getOutput() {return outputValue;}
	virtual ~StringCell();
private:
    std::string inputValue;
    std::string outputValue;
};
