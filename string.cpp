#include "string.hpp"
#include <iostream>

string::string(char *val)
{
    if (*val == 0 || val == nullptr)
    {
        str = new char[1];
        str[0] = '\0';
    }
    else
    {
        str = new char[chars::slen(val) + 1];
        chars::scpy(str, val);
        str[chars::slen(val)] = '\0';
    }
}

string::~string()
{
    delete str;
}

int string::length()
{
    return string::slen(str);
}

string &string::operator=(const string &s)
{
    if (this == &s)
    {
        return *this;
    }
    delete[] str;
    str = new char[std::strlen(s.str) + 1];
    chars::scpy(str, s.str);
    return *this;
}

string operator+(const string &s1, const string &s2)
{
    int length = chars::slen(s1.str) + chars::slen(s2.str);
    char *buff = new char[length + 1];
    chars::scpy(buff, s1.str);
    chars::scat(buff, s2.str);
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