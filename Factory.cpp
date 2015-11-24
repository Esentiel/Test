#include "Factory.h"

Factory::Factory()
{
	parser = std::make_shared<Parser>();
};


inline Cell * Factory::getCell(std::string cellValue, StringVector2D const &inputValues)
{
	char indicator = cellValue[0];
	if (isdigit(indicator))
		return new NumberCell(cellValue);
	switch (indicator)
	{
	case '\'':
		return new StringCell(cellValue);
	case '=':
		return new FormulaCell(parser->parseLine(cellValue, inputValues));
	case '\0':
		return new NoneCell(cellValue);
	default:
		return new NoneCell("#Wrong input");
	}
};


void Factory::passValues(size_t const &sizeX, size_t const &sizeY, StringVector2D const &inputValues, CellVector2D &spreadsheet)
{
	spreadsheet.resize(sizeY);
	for (size_t i = 0; i < (sizeY); i++)
	{
		spreadsheet[i].resize(sizeX);
	}
	for (size_t i = 0; i < spreadsheet.size(); i++)
	{
		for (size_t j = 0; j < spreadsheet[i].size(); j++)
		{
			spreadsheet[i][j] = Factory::getCell(inputValues[i][j], inputValues);
		}
	}
};

Factory::~Factory()
{
};