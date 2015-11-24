#include "NoneCell.h"

NoneCell::NoneCell(std::string const value) : Cell(value) {};
void NoneCell::evaluate()
{
	outputValue = inputValue;
};
NoneCell::~NoneCell() {};
