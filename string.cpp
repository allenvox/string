#include "string.hpp"
#include <iostream>

string::string()
{
    str = new char[1];
    str[0] = '\0';
}

string::string(char *val)
{
    if (val == nullptr)
    {
        str = new char[1];
        str[0] = '\0';
    }
    else
    {
        str = new char[std::strlen(val) + 1];
        std::strcpy(str, val);
        str[std::strlen(val)] = '\0';
    }
}

string::~string()
{
    delete str;
}

int string::length()
{
    return std::strlen(str);
}

string &string::operator=(const string &s)
{
    if (this == &s)
    {
        return *this;
    }
    delete[] str;
    str = new char[std::strlen(s.str) + 1];
    strcpy(str, s.str);
    return *this;
}

string operator+(const string &s1, const string &s2)
{
    int length = std::strlen(s1.str) + std::strlen(s2.str);
    char *buff = new char[length + 1];
    std::strcpy(buff, s1.str);
    std::strcat(buff, s2.str);
    buff[length] = '\0';
    string temp(buff);
    delete[] buff;
    return temp;
}

std::istream &operator>>(std::istream &is, string &obj)
{
    char *buff = new char[1000];
    memset(&buff[0], 0, sizeof(buff));
    is >> buff;
    obj = string(buff);
    delete[] buff;
    return is;
}

std::ostream &operator<<(std::ostream &os, const string &obj)
{
    os << obj.str;
    return os;
}