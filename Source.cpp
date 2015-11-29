#include <memory>
#include "Factory.h"
#include "UserInterface.h"

using namespace std;

static std::shared_ptr<StringVector2D> inputValues = std::make_shared<StringVector2D>();
static std::shared_ptr<CellVector2D> spreadsheet = std::make_shared<CellVector2D>();
static size_t sizeX;
static size_t sizeY;

void bulkEval()
{
    for (size_t i = 0; i < spreadsheet->size(); i++)
	{
        for (size_t j = 0; j < spreadsheet->at(i).size(); j++)
		{
            spreadsheet->at(i).at(j)->evaluate();
		}
	}
}

void clean()
{
    for (auto row : *spreadsheet)
    {
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

int main()
{
    std::unique_ptr<Factory> fac = std::make_unique<Factory>();
    std::unique_ptr<UserInterface> ui = std::make_unique<UserInterface>();

    ui->getInput(sizeX, sizeY, inputValues);
    fac->passValues(sizeX, sizeY, inputValues, spreadsheet);
	bulkEval();
    ui->printOutput(spreadsheet);

	return 0;
}
