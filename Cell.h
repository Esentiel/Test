#pragma once

#include <string>

class Cell
{
public:
    virtual std::string & getOutput() = 0;
	virtual void evaluate() = 0;
    virtual ~Cell(){}
};

