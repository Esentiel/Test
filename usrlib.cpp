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

}
