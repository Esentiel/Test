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
    for (auto const &row : *spreadsheet)
	{
        for (auto const &cell : row)
		{
            cell->evaluate();
		}
	}
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
