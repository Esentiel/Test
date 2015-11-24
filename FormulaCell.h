#pragma once

#include"Cell.h"

class FormulaCell : public Cell
{
public:
	FormulaCell(std::string const value);
	virtual void evaluate();
	virtual ~FormulaCell();
};