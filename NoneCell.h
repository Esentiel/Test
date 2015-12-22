#ifndef NONECELL_H
#define NONECELL_H

#include "Cell.h"

class NoneCell : public Cell
{
public:
	NoneCell(const std::string value);
	void evaluate();
    virtual std::string & getOutput() {return outputValue;}
	virtual ~NoneCell();
private:
    std::string inputValue;
    std::string outputValue;
};
#endif //NONECELL_H
