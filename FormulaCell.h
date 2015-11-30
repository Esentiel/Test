#pragma once
#include <memory>
#include"Cell.h"
#include "Parser.h"
#include "usrlib.h"

class FormulaCell : public Cell
{
public:
    FormulaCell(const std::string value, std::shared_ptr<usrlib::StringVector2D> inputValues);
	virtual void evaluate();
	virtual ~FormulaCell();
private:
    std::shared_ptr<Parser> parser;
    std::shared_ptr<usrlib::StringVector2D> values;
};
