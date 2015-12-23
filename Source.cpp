#include <memory>
#include "Factory.h"
#include "UserInterface.h"

void bulkEval(std::shared_ptr<usrlib::CellVector2D> spreadsheet)
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
    std::shared_ptr<usrlib::StringVector2D> inputValues = std::make_shared<usrlib::StringVector2D>();
    std::shared_ptr<usrlib::CellVector2D> spreadsheet = std::make_shared<usrlib::CellVector2D>();
    size_t sizeX;
    size_t sizeY;

    std::unique_ptr<Factory> fac = std::make_unique<Factory>();
    std::unique_ptr<UserInterface> ui = std::make_unique<UserInterface>();

    ui->getInput(sizeX, sizeY, inputValues);
    fac->passValues(sizeX, sizeY, inputValues, spreadsheet);
    bulkEval(spreadsheet);
    ui->printOutput(spreadsheet);

	return 0;
}
