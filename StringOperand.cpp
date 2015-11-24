#include "StringOperand.h"



StringOperand::StringOperand() : Operand()
{
}

StringOperand::StringOperand(std::string value) : Operand(value)
{
}

std::string StringOperand::getValue() const
{
	return strValue;
}

void StringOperand::setValue(std::string value)
{
	strValue = value;
}

StringOperand StringOperand::operator+(StringOperand const &b) const
{
	StringOperand str(*this);
	str.setValue(str.getValue() + b.getValue());
	return str;
}

StringOperand StringOperand::operator+(IntOperand const &b) const
{
	StringOperand str(*this);
	str.setValue(str.getValue() + b.getValue());
	return str;
}

StringOperand StringOperand::operator*(IntOperand const &b) const
{
	StringOperand str(*this);
	int n = std::atoi(b.getValue().c_str());
	std::string strPart = str.getValue();

	while (n--)
	{
		str.setValue(str.getValue() + strPart);
	}

	return str;
}

StringOperand::~StringOperand()
{
}
