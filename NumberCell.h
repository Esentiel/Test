#pragma once

#include "Cell.h"

class NumberCell : public Cell
{
public:
	NumberCell(std::string const value);
	virtual void evaluate();
	virtual ~NumberCell();
};