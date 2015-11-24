#include "Cell.h"

//Cell
Cell::Cell(std::string const value) { inputValue = value; };
Cell::~Cell() {};
std::string Cell::getOutput() const
{
	return outputValue;
};
