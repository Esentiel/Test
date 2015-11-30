#pragma once
#include <string>
#include <iostream>
#include "usrlib.h"

enum class Type {String, Integer};
class Variant
{
	public:
		Variant();
		Variant(std::string value);
		Type getType() const;
		std::string asString() const;
		operator int() const;
		void setString(std::string);
		void setInt(int value);
		Variant operator+(const Variant &b) const;
		Variant operator-(const Variant &b) const;
		Variant operator*(const Variant &b) const;
		Variant operator/(const Variant &b) const;
		~Variant();
	private:
		Type type;
		std::string stringValue;
		int intValue;
};
