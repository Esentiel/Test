#ifndef USRLIB
#define USRLIB
#include <string>
#include <vector>
#include <memory>
#include "Cell.h"

namespace usrlib
{
typedef std::vector<std::string> StringVector;
typedef std::vector<usrlib::StringVector> StringVector2D;
typedef std::vector<std::shared_ptr<Cell>> CellVector;
typedef std::vector<usrlib::CellVector> CellVector2D;

bool isDigit(const std::string &str);
bool isAlphaNum(const std::string &str);
bool replace(std::string& str, const std::string& from, const std::string& to);
std::vector<std::string> split(std::string str, const std::string &delim = "\t");
}

#endif // USRLIB

