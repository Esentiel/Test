#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <memory>
#include "usrlib.h"

class UserInterface
{
public:
	UserInterface();
    void getInput(size_t &sizeX, size_t &sizeY, std::shared_ptr<usrlib::StringVector2D> inputValues) const;
    void printOutput(std::shared_ptr<usrlib::CellVector2D> spreadsheet) const;
	~UserInterface();
private:
    usrlib::StringVector split(std::string line, usrlib::StringVector row) const;
    int calcMaxColumnSize(const int colNum, const std::shared_ptr<usrlib::CellVector2D> spreadsheet) const;
};

