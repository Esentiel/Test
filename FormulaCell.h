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
	virtual void evaluate();
    virtual std::string & getOutput();
	virtual ~FormulaCell();
private:
    std::shared_ptr<Parser> parser;
    std::shared_ptr<usrlib::StringVector2D> values;
    std::future<std::string> theFuture;
    bool wasExecuted;
    std::string inputValue;
    std::string outputValue;
};
