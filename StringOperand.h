#pragma once
#include "Operand.h"
#include "IntOperand.h"


class StringOperand :
	public Operand
{
public:
	StringOperand();
	StringOperand(std::string value);
	virtual std::string getValue() const;
	virtual void setValue(std::string value);
	StringOperand operator*(IntOperand const &b) const;
	StringOperand operator+(StringOperand const &b) const;
	StringOperand operator+(IntOperand const &b) const;
	~StringOperand();
};

