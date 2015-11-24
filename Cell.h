#pragma once

#include <string>

class Cell
{
protected:
	std::string inputValue;
	std::string outputValue;
public:
	Cell(std::string const value);
	std::string getOutput() const;
	virtual void evaluate() = 0;
	virtual ~Cell();
};

