#include "UserInterface.h"

UserInterface::UserInterface()
{
}


inline int UserInterface::calcMaxColumnSize(const int colNum, const std::shared_ptr<usrlib::CellVector2D> spreadsheet) const
{
    size_t maxSize = 0;
    for (auto const &element : *spreadsheet)
    {
        if (element.at(colNum)->getOutput().length() > maxSize)
            maxSize = element.at(colNum)->getOutput().length();
    }
    return maxSize;
}

void UserInterface::manualInput(size_t &sizeX, size_t &sizeY, std::shared_ptr<usrlib::StringVector2D> inputValues) const
{
    std::cout << "Put a spreadsheet size: y\tx" << std::endl;
    std::cin >> sizeY >> sizeX;
    std::cin.ignore();
    inputValues->resize(sizeY);

    std::cout << "Put spreadsheet data" << std::endl;
    std::string line;
    for (size_t i = 0; i < sizeY; i++)
    {
        getline(std::cin, line);
        inputValues->at(i) = std::move(usrlib::split(line));
        line.clear();
    }
}

void UserInterface::loadFromFile(size_t &sizeX, size_t &sizeY, std::shared_ptr<usrlib::StringVector2D> inputValues) const
{
    std::string line;
    std::ifstream csvFile(fileName);
    if (!csvFile.is_open())
        throw std::invalid_argument(fileName+" doesn't exist.");

    while (getline(csvFile,line))
    {
        inputValues->push_back(std::move(usrlib::split(line, delimiter)));
    }
    sizeY = inputValues->size();
    sizeX = inputValues->at(0).size();
    csvFile.close();
}

void UserInterface::getInput(size_t &sizeX, size_t &sizeY, std::shared_ptr<usrlib::StringVector2D> inputValues) const
{
    char answer;
    std::cout << "Do you want to load data from "<<fileName<<"? [y,n]" << std::endl;
    std::cin >> answer;
    answer == 'y' ? loadFromFile(sizeX, sizeY, inputValues) : manualInput(sizeX, sizeY, inputValues);

}

void UserInterface::printOutput(const std::shared_ptr<usrlib::CellVector2D> spreadsheet) const
{
    std::cout << "Result table:" << std::endl;
    for (size_t i = 0; i < spreadsheet->size(); i++)
	{
        for (size_t j = 0; j < spreadsheet->at(i).size(); j++)
		{
            const int colWidth = calcMaxColumnSize(j, spreadsheet);
            if (j + 1 == spreadsheet->at(i).size())
            {
                std::cout << std::setw(colWidth) << std::left << spreadsheet->at(i).at(j)->getOutput() << std::endl;
			}
			else {
                std::cout << std::setw(colWidth) << std::left << spreadsheet->at(i).at(j)->getOutput() << "\t";
			}
		}
	}
}

UserInterface::~UserInterface()
{
}
