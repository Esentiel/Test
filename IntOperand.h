#pragma once
#include "Operand.h"
#include "StringOperand.h"

class IntOperand :
	public Operand
{
public:
	IntOperand();
	IntOperand(std::string value);
	virtual std::string getValue() const;
	virtual void setValue(std::string value);
	IntOperand operator*(IntOperand const &b) const;
	StringOperand operator*(StringOperand const &b) const;
	IntOperand operator+(IntOperand const &b) const;
	StringOperand operator+(StringOperand const &b) const;
	IntOperand operator/(IntOperand const &b) const;
	IntOperand operator-(IntOperand const &b) const;
	~IntOperand();
};

