#include <string>
#include <stack>
#include <vector>
#include <memory>
#include <cstdlib>
#include <regex>
#include "ReversePolandNotation.h"
#include "usrlib.h"

#pragma once

class Parser
{
public:
    Parser();
    std::string parseLine(std::string &line, const std::vector<std::vector<std::string>> &inputvalues) const;
    ~Parser();
private:
	std::unique_ptr<ReversePolandNotation> rpnAdapter;
    std::string findNextLink(const std::string &line) const;
    std::string getLinkValue(const std::string &link, const std::vector<std::vector<std::string>> &inputvalues) const;
    void translateLink(const std::string &link, size_t &x, size_t &y) const;
};

