#pragma once

#include "Cell.h"

class StringCell : public Cell
{
public:
	StringCell(std::string const value);
	virtual void evaluate();
	virtual ~StringCell();
};