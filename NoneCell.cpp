#include "NoneCell.h"

NoneCell::NoneCell(const std::string value) : inputValue{value} {}
void NoneCell::evaluate()
{
	outputValue = inputValue;
};
NoneCell::~NoneCell() {};
