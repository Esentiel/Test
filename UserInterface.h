#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <memory>
#include <fstream>
#include <stdexcept>
#include "usrlib.h"

class UserInterface
{
public:
    void getInput(std::shared_ptr<usrlib::StringVector2D> inputValues) const;
    void printOutput(std::shared_ptr<usrlib::CellVector2D> spreadsheet) const;
private:
    int calcMaxColumnSize(const int colNum, const std::shared_ptr<usrlib::CellVector2D> spreadsheet) const;
    void manualInput(std::shared_ptr<usrlib::StringVector2D> inputValues) const;
    void loadFromFile(std::shared_ptr<usrlib::StringVector2D> inputValues) const;
    const std::string fileName = "data.csv";
    const std::string delimiter = ",";
    mutable size_t sizeX;
    mutable size_t sizeY;
};

