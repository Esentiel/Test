#pragma once
#include <memory>
#include <future>
#include"Cell.h"
#include "Parser.h"
#include "usrlib.h"

class FormulaCell : public Cell
{
public:
    FormulaCell(const std::string value, std::shared_ptr<usrlib::StringVector2D> inputValues);
    void evaluate();
    std::string & getOutput();
private:
    std::string inputValue;
    std::unique_ptr<Parser> parser;
    std::shared_ptr<usrlib::StringVector2D> values;
    std::future<std::string> theFuture;
    bool wasExecuted;
    std::string outputValue;
};
