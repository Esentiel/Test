#pragma once
#include "Cell.h"
#include "NumberCell.h"
#include "StringCell.h"
#include "FormulaCell.h"
#include "NoneCell.h"
#include "UserInterface.h"
#include "Parser.h"
#include <string>
#include <cstdlib>
#include <iostream>
#include <memory>


class Factory
{
private:
	std::shared_ptr<Parser> parser;
	inline Cell * getCell(std::string cellValue, StringVector2D const &inputValues);
public:
	Factory();
	void passValues(size_t const &sizeX, size_t const &sizeY, StringVector2D const &inputValues, CellVector2D &spreadsheet);
	~Factory();
};

