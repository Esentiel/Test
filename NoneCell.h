#ifndef NONECELL_H
#define NONECELL_H
#endif

#include "Cell.h"

class NoneCell : public Cell
{
public:
	NoneCell(std::string const value);
	void evaluate();
	virtual ~NoneCell();
};