#include <string>
#include <stack>
#include <vector>
#include <memory>
#include <cstdlib>
#include "ReversePolandNotation.h"
#include <regex>

#pragma once

class Parser
{
private:
	std::unique_ptr<ReversePolandNotation> rpnAdapter;
	std::string findNextLink(std::string const &line);
	std::string getLinkValue(std::string const &link, std::vector<std::vector<std::string>> inputvalues);
	void translateLink(std::string const &link, size_t &x, size_t &y);
	bool replace(std::string &str, std::string const &from, std::string const &to);
public:
	Parser();
	std::string parseLine(std::string &line, std::vector<std::vector<std::string>> const inputvalues);
	~Parser();
};

