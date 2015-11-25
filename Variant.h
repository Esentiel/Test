#pragma once
#include <string>
#include <iostream>

enum Type {string, integ};
class Variant
{
	public:
		Variant();
		Variant(int value);
		Variant(std::string value);
		Type getType() const;
		std::string getString() const;
		int getInt() const;
		void setInt(int value);
		void setString(std::string);
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
