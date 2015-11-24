#include "StringCell.h"

StringCell::StringCell(std::string const value) : Cell(value) {};
void StringCell::evaluate()
{
	outputValue = inputValue.replace(0, 1, "");
};
StringCell::~StringCell() {};
