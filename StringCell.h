#pragma once

#include "Cell.h"

class StringCell : public Cell
{
public:
	StringCell(const std::string value);
	virtual void evaluate();
	virtual ~StringCell();
};
