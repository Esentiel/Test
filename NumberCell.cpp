#include "NumberCell.h"

NumberCell::NumberCell(const std::string value) : inputValue{value} {}
void NumberCell::evaluate()
{
	outputValue = inputValue;
};
NumberCell::~NumberCell() {}
