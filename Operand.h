#pragma once
#include <string>
class Operand
{
protected:
	std::string strValue;
	int intValue;
public:
	Operand();
	Operand(std::string value);
	Operand(int value);
	virtual std::string getValue() const = 0;
	virtual void setValue(std::string value) = 0;
	~Operand();
};

