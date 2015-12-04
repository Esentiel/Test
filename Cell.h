#pragma once

#include <string>

class Cell
{
public:
	Cell(const std::string value);
    std::string & getOutput() {return outputValue;}
	virtual void evaluate() = 0;
	virtual ~Cell();
protected:
	std::string inputValue;
	std::string outputValue;
};

