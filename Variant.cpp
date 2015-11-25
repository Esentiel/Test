#include "Variant.h"

Variant::Variant()
{
}

Variant::Variant(int value)
{
	intValue = value;
	type = integ;
}

Variant::Variant(std::string value)
{
	stringValue = value;
	type = string;
}

Type Variant::getType() const
{
	return type;
}

int Variant::getInt() const
{
	return intValue;
}

std::string Variant::getString() const
{
	return stringValue;
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
	if (this->getType() == integ && b.getType() == integ)
	{
		Variant v(*this);	
		v.setInt(v.getInt()+b.getInt());
		return v;
	}else if (this->getType() == string && b.getType() == string) {
		Variant v(*this);
		v.setString(v.getString() + b.getString());
		return v;
	}else if (this->getType() == string && b.getType() == integ){
		Variant v(*this);
		v.setString(v.getString() + std::to_string(b.getInt()));
		return v;
	}else if (this->getType() == integ && b.getType() == string){
		Variant v(b);
		v.setString(std::to_string(this->getInt()) + b.getString());
		return v;
	}else{
		Variant v("#Calculation Error");
		return v;
	}
}

Variant Variant::operator-(const Variant &b) const
{
	Variant v(*this);
	if (v.getType() == integ && b.getType() == integ){
		v.setInt(v.getInt() - b.getInt());
	}
	//TODO:add exceptions handling here
	return v;
}

Variant Variant::operator*(const Variant &b) const
{
	if (this->getType() == integ && b.getType() == string){
		Variant v(b);
		int n = this->getInt();
		std::string strPart = v.getString();
		v.setString("");
		while (n--)
		{
			v.setString(v.getString() + strPart);
		}
		return v;
	}else if (this->getType() == string && b.getType() == integ){
		Variant v(*this);
		int n = b.getInt();
		std::string strPart = v.getString();
		v.setString("");
		while (n--)
		{
			v.setString(v.getString() + strPart);
		}
		return v;
	}else if (this->getType() == integ && b.getType() == integ){
		Variant v(*this);
		v.setInt(v.getInt() * b.getInt());
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
	if (v.getType() == integ && b.getType() == integ)
	{
		v.setInt(v.getInt() / b.getInt());
	}
	return v;
}

Variant::~Variant()
{
}
