#include "Variant.h"

Variant::Variant()
{
}

Variant::Variant(std::string value)
{
    if (usrlib::isDigit(value))
	{
		intValue = std::atoi(value.c_str());
		type = Type::Integer;
	}else{
		stringValue = value;
		type = Type::String;
	}
}

Type Variant::getType() const
{
	return type;
}

std::string Variant::asString() const
{
	if (type == Type::String)
	{
		return stringValue;
	}else{
		return std::to_string(intValue);
	}
}

Variant::operator int() const
{
	if (type == Type::Integer)
	{
		return intValue;
	}else{
		return -1;
	}
}

void Variant::setInt(int value)
{
	intValue = value;
}

void Variant::setString(std::string value)
{
	stringValue = value;
}

Variant Variant::operator+(const Variant &b) const
{
	if (this->getType() == Type::Integer && b.getType() == Type::Integer)
	{
		Variant v(*this);	
		v.setInt(static_cast<int>(v) + static_cast<int>(b));
		return v;
	}else if (this->getType() == Type::String && b.getType() == Type::String) {
		Variant v(*this);
		v.setString(v.asString() + b.asString());
		return v;
	}else if (this->getType() == Type::String && b.getType() == Type::Integer){
		Variant v(*this);
		v.setString(v.asString() + b.asString());
		return v;
	}else if (this->getType() == Type::Integer && b.getType() == Type::String){
		Variant v(b);
		v.setString(this->asString() + b.asString());
		return v;
	}else{
		Variant v("#Calculation Error");
		return v;
	}
}

Variant Variant::operator-(const Variant &b) const
{
	Variant v(*this);
	if (v.getType() == Type::Integer && b.getType() == Type::Integer){
		v.setInt(static_cast<int>(v) - static_cast<int>(b));
	}
	//TODO:add exceptions handling here
	return v;
}

Variant Variant::operator*(const Variant &b) const
{
	if (this->getType() == Type::Integer && b.getType() == Type::String){
		Variant v(b);
		int n = static_cast<int>(*this);
		std::string strPart = v.asString();
		v.setString("");
		while (n--)
		{
			v.setString(v.asString() + strPart);
		}
		return v;
	}else if (this->getType() == Type::String && b.getType() == Type::Integer){
		Variant v(*this);
		int n = static_cast<int>(b);
		std::string strPart = v.asString();
		v.setString("");
		while (n--)
		{
			v.setString(v.asString() + strPart);
		}
		return v;
	}else if (this->getType() == Type::Integer && b.getType() == Type::Integer){
		Variant v(*this);
		v.setInt(static_cast<int>(v) * static_cast<int>(b));
		return v;
	}else{
		Variant v("#Calculation Error");
		return v;
	}
	//TODO:add exceptions handling
}

Variant Variant::operator/(const Variant &b) const
{
	Variant v(*this);
	if (v.getType() == Type::Integer && b.getType() == Type::Integer)
	{
		v.setInt(static_cast<int>(v) / static_cast<int>(b));
	}
	return v;
}

Variant::~Variant()
{
}
