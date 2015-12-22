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
#include "usrlib.h"

class Factory
{
public:
    void passValues(const size_t &sizeX, const size_t &sizeY, std::shared_ptr<usrlib::StringVector2D> inputValues, std::shared_ptr<usrlib::CellVector2D> spreadsheet);
private:
    inline std::shared_ptr<Cell> getCell(const std::string cellValue, std::shared_ptr<usrlib::StringVector2D> inputValues) const;
};

