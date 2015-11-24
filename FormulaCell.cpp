#include "FormulaCell.h"

FormulaCell::FormulaCell(std::string const value) : Cell(value) {};
void FormulaCell::evaluate()
{
	outputValue = inputValue;
};
FormulaCell::~FormulaCell() {};
