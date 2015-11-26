#pragma once

#include "Cell.h"

class NumberCell : public Cell
{
public:
	NumberCell(const std::string value);
	virtual void evaluate();
	virtual ~NumberCell();
};
