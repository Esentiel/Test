#include "Parser.h"

Parser::Parser()
{
	rpnAdapter = std::make_unique<ReversePolandNotation>();
}

bool Parser::replace(std::string& str, const std::string& from, const std::string& to) {
	size_t start_pos = str.find(from);
	if (start_pos == std::string::npos)
		return false;
	str.replace(start_pos, from.length(), to);
	return true;
}

std::string Parser::parseLine(std::string &line, std::vector<std::vector<std::string>> const inputvalues)
{
	//check it before calculation too
	if (line.find("/0") != std::string::npos)
		return "#Division by zero";
	line.replace(0, 1, "");
	while (!(findNextLink(line).empty()))
	{
		replace(line, findNextLink(line), getLinkValue(findNextLink(line), inputvalues));
	}
	return
		line.find('#') == std::string::npos ? rpnAdapter->performCalculation(line) : "#Wrong Link!";
}

std::string Parser::findNextLink(std::string const &line)
{
	std::string charPart = "";
	std::string numberPart = "";
	for (size_t i = 0; i < line.size(); i++)
	{
		if (isalpha(line.at(i)))
		{
			charPart.append(1, line.at(i));
		}
		else if (isdigit(line.at(i)) && !(charPart.empty()))
		{
			numberPart.append(1, line.at(i));
		}
		else if (!isalnum(line.at(i)))
		{
			break;
		}
	}
	if ((numberPart.size() > 0) && (charPart.size() > 0)) {
		std::cout<<numberPart.size();
		return charPart.append(numberPart); 
	}else{
		return "";
	}
}

std::string Parser::getLinkValue(std::string const &link, std::vector<std::vector<std::string>> inputvalues)
{
	size_t x = 0;
	size_t y = 0;
	translateLink(link, x, y);

	if (((y - 1) >= inputvalues.size()) || (((x - 1) >= inputvalues.at(y - 1).size()) && x > 1))
	{
		return "#Wrong link";
	}
	std::string linkResult = inputvalues.at(y - 1).at(x - 1);
	if (linkResult.at(0) == '=')
	{
		linkResult.at(0) = '(';
		linkResult.push_back(')');
	}
	return linkResult;
};

void Parser::translateLink(std::string const &link, size_t &x, size_t &y)
{
	size_t idx = 0;
	std::string stringX = "";
	while (isalpha(link.at(idx)))
	{
		y = 26 * idx + (link.at(idx) - 64);
		idx++;
	}
	for (size_t j = idx; j < link.size(); j++)
	{
		stringX += link.at(j);
	}
	x = atoi(stringX.c_str());
};

Parser::~Parser()
{
}
