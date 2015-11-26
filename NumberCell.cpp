#include "NumberCell.h"

NumberCell::NumberCell(const std::string value) : Cell(value) {};
void NumberCell::evaluate()
{
	outputValue = inputValue;
};
NumberCell::~NumberCell() {};
