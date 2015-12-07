#include "FormulaCell.h"

FormulaCell::FormulaCell(const std::string value, std::shared_ptr<usrlib::StringVector2D> inputValues) : Cell(value) {
    parser = std::make_shared<Parser>();
    values = inputValues;
    wasExecuted = false;
}

void FormulaCell::evaluate()
{
    theFuture = std::async(std::launch::async, [&] () {return parser->parseLine(inputValue, *values);});
}

std::string & FormulaCell::getOutput()
{
    if (wasExecuted)
        return outputValue;
    outputValue = theFuture.get();
    wasExecuted = true;
    return outputValue;
}

FormulaCell::~FormulaCell() {}
