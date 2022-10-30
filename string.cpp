#include "string.hpp"

string::string() : str{nullptr}
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
        str = new char[strlen(val)];
        strcpy(val, str);
    }
}

string::~string()
{
    delete str;
}

static char *strcpy(const char *src, char *dest)
{
    int i;
    for (i = 0; src[i] != 0; i++)
    {
        dest[i] = src[i];
    }
    dest[i] = 0;
    return dest;
}

static int strlen(const char *str)
{
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        count++;
    }
    return ++count;
}

int string::length()
{
    return strlen(str);
}

string &string::operator=(const string &s)
{
    if (this == &s)
        return *this;
    delete[] str;
    str = new char[strlen(s.str)];
    strcpy(str, s.str);
    return *this;
}

string operator+(const string &s1, const string &s2)
{
    int length = strlen(s1.str) + strlen(s2.str);
    char *buff = new char[length + 1];
    strcpy(buff, s1.str);
    strcat(buff, s2.str);
    buff[length] = '\0';
    string temp{buff};
    delete[] buff;
    return temp;
}

static char *strcat(char *dest, const char *src)
{
    char *end = dest + strlen(dest) - 1;
    while (*src != '\0')
    {
        *end++ = *src++;
    }
    *end = '\0';
    return dest;
}
