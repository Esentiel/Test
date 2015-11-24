#include "Factory.h"
#include "UserInterface.h"
#include <conio.h>

using namespace std;

static StringVector2D inputValues;
static CellVector2D spreadsheet;
static size_t sizeX;
static size_t sizeY;

void bulkEval()
{
	for (size_t i = 0; i < spreadsheet.size(); i++)
	{
		for (size_t j = 0; j < spreadsheet[i].size(); j++)
		{
			spreadsheet[i][j]->evaluate();
		}
	}
};

void clean()
{
	for (size_t i = 0; i < spreadsheet.size(); i++)
	{
		for (size_t j = 0; j < spreadsheet[i].size(); j++)
		{
			delete spreadsheet[i][j];
		}
		spreadsheet[i].clear();
		spreadsheet[i].shrink_to_fit();
		inputValues[i].clear();
		inputValues[i].shrink_to_fit();
	}
	spreadsheet.clear();
	spreadsheet.shrink_to_fit();
	inputValues.clear();
	inputValues.shrink_to_fit();
}

/*
//////////////////
///REFACTORING////
//////////////////
//1. pass string as reference: (string &str) 
//2. Use constatnt where possible
//3.

*/

int main()
{
	Factory * fac;
	fac = new Factory;
	UserInterface * ui;
	ui = new UserInterface;

	ui->getInput(sizeX, sizeY, inputValues);
	fac->passValues(sizeX, sizeY, inputValues, spreadsheet);
	bulkEval();
	ui->printOutput(spreadsheet);
	delete fac;
	clean();

	_getch();
	return 0;
}