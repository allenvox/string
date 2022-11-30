#include "string.hpp"
#include <iostream>

string::string(const char *val)
{
    if (*val == 0 || val == nullptr)
    {
        str = new char[1];
        str[0] = '\0';
    }
    else
    {
        str = new char[slen(val) + 1];
        scpy(str, val);
        str[slen(val)] = '\0';
    }
}

string::string(size_t size)
{
    try
    {
        if (size <= 0)
        {
            throw "Size of a string must be more than zero.";
        }
        else
        {
            str = new char[size];
            if (str != NULL)
            {
                for (size_t i = 0; i < size; i++)
                {
                    str[i] = '\0';
                }
            }
        }
    }
    catch (const char *str)
    {
        std::cout << str << std::endl;
    }
}

string::string(const string &s)
{
    str = new char[s.length()];
    if (str != NULL)
    {
        scpy(str, s.get());
    }
}

string &string::operator=(const string &s)
{
    if (this == &s)
    {
        return *this;
    }
    delete[] str;
    str = new char[slen(s.get()) + 1];
    scpy(str, s.get());
    return *this;
}