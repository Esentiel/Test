#include "usrlib.h"

namespace usrlib {
//check is all string contains only digits
bool isDigit(const std::string &str)
{
    for (auto element : str)
    {
        if (!isdigit(element))
            return false;
    }
    return true;
}

//check is string contains only alpha and num chars
bool isAlphaNum(const std::string &str)
{
    for (auto element : str)
    {
        if (!isalnum(element))
            return false;
    }
    return true;
}

//replace part of a string
bool replace(std::string& str, const std::string& from, const std::string& to)
{
    size_t start_pos = str.find(from);
    if (start_pos == std::string::npos)
        return false;
    str.replace(start_pos, from.length(), to);
    return true;
}

//split string to a vector by delimiter
std::vector<std::string> split(std::string str, const std::string &delim)
{
    std::vector<std::string> v;
    while (str.find(delim) != std::string::npos)
    {
        v.push_back(str.substr(0, str.find(delim)));
        str.erase(0, str.find(delim) + delim.length());//erase makes copy of string. TODO: maybe something better?..
    }
    v.push_back(str);
    return std::move(v);
}

}
