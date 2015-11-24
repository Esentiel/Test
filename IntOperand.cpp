#include "IntOperand.h"



IntOperand::IntOperand()
{
}

IntOperand::IntOperand(std::string value) : Operand(value)
{
}

std::string IntOperand::getValue() const
{
	return std::to_string(intValue);
}

void IntOperand::setValue(std::string value)
{
	intValue = std::atoi(value.c_str());
}

IntOperand IntOperand::operator+(IntOperand const &b) const
{
	IntOperand integ(*this);
	integ.setValue(std::to_string(std::atoi(integ.getValue().c_str()) + std::atoi(b.getValue().c_str())));
	return integ;
}

IntOperand IntOperand::operator-(IntOperand const &b) const
{
	IntOperand integ(*this);
	integ.setValue(std::to_string(std::atoi(integ.getValue().c_str()) - std::atoi(b.getValue().c_str())));
	return integ;
}

IntOperand IntOperand::operator/(IntOperand const &b) const
{
	IntOperand integ(*this);
	integ.setValue(std::to_string(std::atoi(integ.getValue().c_str()) / std::atoi(b.getValue().c_str())));
	return integ;
}

StringOperand IntOperand::operator+(StringOperand const &b) const
{
	StringOperand str(this->getValue());
	str.setValue(str.getValue() + b.getValue());
	return str;
}

IntOperand IntOperand::operator*(IntOperand const &b) const
{
	IntOperand integ(*this);
	integ.setValue(std::to_string(std::atoi(integ.getValue().c_str()) * std::atoi(b.getValue().c_str())));
	return integ;
}

StringOperand IntOperand::operator*(StringOperand const &b) const
{
	StringOperand str(this->getValue());
	int n = std::atoi(str.getValue().c_str());
	std::string strPart = b.getValue();

	while (n--)
	{
		str.setValue(str.getValue() + strPart);
	}

	return str;
}

IntOperand::~IntOperand()
{
}
