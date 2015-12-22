#ifndef NONECELL_H
#define NONECELL_H

#include "Cell.h"

class NoneCell : public Cell
{
public:
	NoneCell(const std::string value);
    void evaluate(){outputValue = inputValue;}
    std::string & getOutput() {return outputValue;}
private:
    std::string inputValue;
    std::string outputValue;
};
#endif //NONECELL_H
