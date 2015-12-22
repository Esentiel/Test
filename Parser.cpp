#include "Parser.h"

Parser::Parser()
{
	rpnAdapter = std::make_unique<ReversePolandNotation>();
}

std::string Parser::parseLine(std::string &line, const std::vector<std::vector<std::string>> &inputvalues) const
{
	line.replace(0, 1, "");
	while (!(findNextLink(line).empty()))
	{
        usrlib::replace(line, findNextLink(line), getLinkValue(findNextLink(line), inputvalues));
	}
    if (line.find("/0") != std::string::npos)
        return "#Division by zero";
	return
		line.find('#') == std::string::npos ? rpnAdapter->performCalculation(line) : "#Wrong Link!";
}

std::string Parser::findNextLink(std::string const &line) const
{
    std::smatch m;
    std::regex e("[A-Z]+[0-9]+");
    if (std::regex_search (line,m,e))
    {
        return m[0];
    }else
    {
        return "";
    }
}

std::string Parser::getLinkValue(const std::string &link, const std::vector<std::vector<std::string>> &inputvalues) const
{
	size_t x = 0;
	size_t y = 0;
	translateLink(link, x, y);

	if (((y - 1) >= inputvalues.size()) || (((x - 1) >= inputvalues.at(y - 1).size()) && x > 1))
	{
		return "#Wrong link";
	}
	std::string linkResult = inputvalues.at(y - 1).at(x - 1);
    if ((linkResult.at(0) == '=') || (linkResult.at(0) == '\''))
	{
		linkResult.at(0) = '(';
		linkResult.push_back(')');
	}
    return std::move(linkResult);
}

void Parser::translateLink(const std::string &link, size_t &x, size_t &y) const
{
	size_t idx = 0;
	std::string stringX = "";
	while (isalpha(link.at(idx)))
	{
        x = 26 * idx + (link.at(idx) - 64);
		idx++;
	}
	for (size_t j = idx; j < link.size(); j++)
	{
		stringX += link.at(j);
	}
    y = atoi(stringX.c_str());
}
