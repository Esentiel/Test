#ifndef NONECELL_H
#define NONECELL_H

#include "Cell.h"

class NoneCell : public Cell
{
public:
	NoneCell(const std::string value);
	void evaluate();
	virtual ~NoneCell();
};
#endif //NONECELL_H
