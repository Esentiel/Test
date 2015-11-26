#include "Factory.h"

Factory::Factory()
{
};

bool Factory::isDigit(const std::string &str) const
{
	for (auto element : str)
	{
		if (!isdigit(element))
			return false;
	}
	return true;
}



inline std::shared_ptr<Cell> Factory::getCell(const std::string cellValue, std::shared_ptr<StringVector2D> inputValues) const
{
	char indicator = cellValue.at(0);
	if (isDigit(cellValue))
        return std::make_shared<NumberCell>(cellValue);
	switch (indicator)
	{
	case '\'':
        return std::make_shared<StringCell>(cellValue);
	case '=':
        return std::make_shared<FormulaCell>(cellValue, inputValues);
	case '\0':
        return std::make_shared<NoneCell>(cellValue);
	default:
        return std::make_shared<NoneCell>("#Wrong input");
	}
};


void Factory::passValues(const size_t &sizeX, const size_t &sizeY, std::shared_ptr<StringVector2D> inputValues, std::shared_ptr<CellVector2D> spreadsheet)
{
    spreadsheet->resize(sizeY);
    for (size_t i = 0; i < (sizeY); i++)
    {
        spreadsheet->at(i).resize(sizeX);
	}
    for (size_t i = 0; i < spreadsheet->size(); i++)
	{
        for (size_t j = 0; j < spreadsheet->at(i).size(); j++)
		{
            spreadsheet->at(i)[j] = getCell(inputValues->at(i)[j], inputValues);
		}
	}
};

Factory::~Factory()
{
};
