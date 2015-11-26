#include "StringCell.h"

StringCell::StringCell(const std::string value) : Cell(value) {};
void StringCell::evaluate()
{
	outputValue = inputValue.replace(0, 1, "");
};
StringCell::~StringCell() {};
