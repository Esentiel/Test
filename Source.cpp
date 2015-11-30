#include <memory>
#include "Factory.h"
#include "UserInterface.h"

using namespace std;

static std::shared_ptr<usrlib::StringVector2D> inputValues = std::make_shared<usrlib::StringVector2D>();
static std::shared_ptr<usrlib::CellVector2D> spreadsheet = std::make_shared<usrlib::CellVector2D>();
static size_t sizeX;
static size_t sizeY;

void bulkEval()
{
    for (auto row : *spreadsheet)
	{
        for (auto cell : row)
		{
            cell->evaluate();
		}
	}
}

void clean()
{
    for (size_t i = 0; i < spreadsheet->size(); i++)
    {
        spreadsheet->at(i).clear();
        spreadsheet->at(i).shrink_to_fit();
        inputValues->at(i).clear();
        inputValues->at(i).shrink_to_fit();
    }
    spreadsheet->clear();
    spreadsheet->shrink_to_fit();
    inputValues->clear();
    inputValues->shrink_to_fit();
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
