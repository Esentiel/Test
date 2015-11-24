#pragma once
#include "Cell.h"
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

typedef std::vector<std::string> StringVector;
typedef std::vector<StringVector> StringVector2D;
typedef std::vector<Cell*> CellVector;
typedef std::vector<CellVector> CellVector2D;


class UserInterface
{
private:
	StringVector split(std::string line, StringVector row);
	int calcMaxColumnSize(int const colNum, CellVector2D spreadsheet);
public:
	UserInterface();
	void getInput(size_t &sizeX, size_t &sizeY, StringVector2D &inputValues);
	void printOutput(CellVector2D spreadsheet);
	~UserInterface();
};

