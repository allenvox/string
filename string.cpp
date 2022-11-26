#include "string.hpp"
#include <iostream>

// string
string::string(const char *val)
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
        chars::scpy(str, s.get());
    }
}

char *string::get() const
{
    return str;
}

string string::set(char *val)
{
    delete[] str;
    str = new char[chars::slen(val) + 1];
    chars::scpy(str, val);
    return *this;
}

size_t string::length() const
{
    return chars::slen(str);
}

string::~string()
{
    if (str != NULL)
    {
        delete[] str;
    }
}

string &string::operator=(const string &s)
{
    if (this == &s)
    {
        return *this;
    }
    delete[] str;
    str = new char[std::strlen(s.get()) + 1];
    chars::scpy(str, s.get());
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
    int length = chars::slen(s1.get()) + chars::slen(s2.get());
    char *buff = new char[length + 1];
    chars::scpy(buff, s1.get());
    chars::scat(buff, s2.get());
    buff[length] = '\0';
    string temp(buff);
    delete[] buff;
    return temp;
}

string operator+(const string &s1, const char *s2)
{
    int length = chars::slen(s1.get()) + chars::slen(s2);
    char *buff = new char[length + 1];
    chars::scpy(buff, s1.get());
    chars::scat(buff, s2);
    buff[length] = '\0';
    string temp(buff);
    delete[] buff;
    return temp;
}

string operator+(const char *s1, const string &s2)
{
    int length = chars::slen(s1) + chars::slen(s2.get());
    char *buff = new char[length + 1];
    chars::scpy(buff, s1);
    chars::scat(buff, s2.get());
    buff[length] = '\0';
    string temp(buff);
    delete[] buff;
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