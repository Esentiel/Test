#include "NoneCell.h"

NoneCell::NoneCell(const std::string value) : Cell(value) {};
void NoneCell::evaluate()
{
	outputValue = inputValue;
};
NoneCell::~NoneCell() {};
