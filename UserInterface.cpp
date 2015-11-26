#include "UserInterface.h"



UserInterface::UserInterface()
{
}

inline StringVector UserInterface::split(std::string line, StringVector row)
{
    for (size_t i = 0; i< row.size(); i++)
	{
        if (i + 1 == row.size())
		{
            row.at(i) = line;
		}
		else {
            row.at(i) = line.substr(0, line.find("\t"));
			line.erase(0, line.find("\t") + 1);
		}
	}
    return row;
};

inline int UserInterface::calcMaxColumnSize(int const colNum, std::shared_ptr<CellVector2D> spreadsheet)
{
	size_t maxSize = 0;
    for (size_t i = 0; i < spreadsheet->size(); i++)
	{
        if (spreadsheet->at(i).at(colNum)->getOutput().length() > maxSize)
            maxSize = spreadsheet->at(i).at(colNum)->getOutput().length();
	}
	return maxSize;
};


void UserInterface::getInput(size_t &sizeX, size_t &sizeY, std::shared_ptr<StringVector2D> inputValues) {
	std::cout << "Put a spreadsheet size: y\tx" << std::endl;
	std::cin >> sizeY >> sizeX;
	std::cin.ignore();
    inputValues->resize(sizeY);
	for (size_t i = 0; i < sizeY; i++)
	{
        inputValues->at(i).resize(sizeX);

	}
	std::cout << "Put spreadsheet data" << std::endl;
	std::string line;
	for (size_t i = 0; i < sizeY; i++)
	{
		getline(std::cin, line);
        inputValues->at(0) = split(line, inputValues->at(0));
		line.clear();
	}

};

void UserInterface::printOutput(std::shared_ptr<CellVector2D> spreadsheet) {
	std::cout << "Result table:" << std::endl;
	int colWidth = 0;
    for (size_t i = 0; i < spreadsheet->size(); i++)
	{

        for (size_t j = 0; j < spreadsheet->at(i).size(); j++)
		{
            colWidth = calcMaxColumnSize(j, spreadsheet);
            if (j + 1 == spreadsheet->at(i).size())
			{
                std::cout << std::setw(colWidth) << std::left << spreadsheet->at(i).at(j)->getOutput() << std::endl;
			}
			else {
                std::cout << std::setw(colWidth) << std::left << spreadsheet->at(i).at(j)->getOutput() << "\t";
			}
		}
	}
};

UserInterface::~UserInterface()
{
}
