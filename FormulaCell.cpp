#include "FormulaCell.h"

FormulaCell::FormulaCell(const std::string value, std::shared_ptr<usrlib::StringVector2D> inputValues) : Cell(value) {
    parser = std::make_shared<Parser>();
    values = inputValues;
    wasExecuted = false;
}

void FormulaCell::evaluate()
{
    if ((values->size() > 100) || (values->at(0).size() > 100))//to perform threading only with big data amount
    {
        theFuture = std::async(/*std::launch::async,*/ [&] () {return parser->parseLine(inputValue, *values);});
    }else{
        outputValue = parser->parseLine(inputValue, *values);
        wasExecuted = true;
    }
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
