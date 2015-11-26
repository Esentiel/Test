#pragma once
#include "Cell.h"
#include "NumberCell.h"
#include "StringCell.h"
#include "FormulaCell.h"
#include "NoneCell.h"
#include "UserInterface.h"
#include <string>
#include <cstdlib>
#include <memory>


class Factory
{
public:
	Factory();
    void passValues(const size_t &sizeX, const size_t &sizeY, std::shared_ptr<StringVector2D> inputValues, std::shared_ptr<CellVector2D> spreadsheet);
	~Factory();
private:
	bool isDigit(const std::string &str) const;
    inline std::shared_ptr<Cell> getCell(const std::string cellValue, std::shared_ptr<StringVector2D> inputValues) const;
};

