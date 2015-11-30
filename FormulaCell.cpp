#include "FormulaCell.h"

FormulaCell::FormulaCell(const std::string value, std::shared_ptr<usrlib::StringVector2D> inputValues) : Cell(value) {
    parser = std::make_shared<Parser>();
    values = inputValues;
};

void FormulaCell::evaluate()
{
    outputValue = parser->parseLine(inputValue, *values);
};
FormulaCell::~FormulaCell() {};
