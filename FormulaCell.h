#pragma once
#include <memory>
#include"Cell.h"
#include "Parser.h"

typedef std::vector<std::string> StringVector;
typedef std::vector<StringVector> StringVector2D;

class FormulaCell : public Cell
{
public:
    FormulaCell(const std::string value, std::shared_ptr<StringVector2D> inputValues);
	virtual void evaluate();
	virtual ~FormulaCell();
private:
    std::shared_ptr<Parser> parser;
    std::shared_ptr<StringVector2D> values;
};
