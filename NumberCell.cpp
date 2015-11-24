#include "NumberCell.h"

NumberCell::NumberCell(std::string const value) : Cell(value) {};
void NumberCell::evaluate()
{
	outputValue = inputValue;
};
NumberCell::~NumberCell() {};