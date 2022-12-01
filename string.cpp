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

string string::append(const char *val)
{
    int l = slen(str) + slen(val);
    char *buff = new char[l + 1];
    scpy(buff, str);
    scat(buff, val);
    buff[l] = '\0';
    set(buff);
    delete[] buff;
    return *this;
}

string string::append(const string &s)
{
    append(s.get());
    return *this;
}

string &string::operator=(const string &s)
{
    if (this == &s)
    {
        return *this;
    }
    set(s.get());
    return *this;
}

std::ostream &operator<<(std::ostream &os, const string &obj)
{
    return (os << obj.get());
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

string operator+(const string &s1, const string &s2)
{
    string temp(s1);
    temp.append(s2);
    return temp;
}

bool operator==(const string &s1, const string &s2)
{
    if (chars::scmp(s1.get(), s2.get()) != 0)
    {
        return false;
    }
    return true;
}