#pragma once
#include <iostream>

class string
{
    friend std::ostream &operator<<(std::ostream &os, const string &obj);
    friend std::istream &operator>>(std::istream &is, string &obj);
    friend string operator+(const string &s1, const string &s2);
    char *str;

public:
    string();
    string(char *val);
    ~string();
    int length();
    string &operator=(const string &s);
    static char *scpy(const char *src, char *dest)
    {
        int i;
        for (i = 0; src[i] != 0; i++)
        {
            dest[i] = src[i];
        }
        dest[i] = 0;
        return dest;
    }
    static int slen(const char *str)
    {
        int count = 0;
        for (int i = 0; str[i] != '\0'; i++)
        {
            count++;
        }
        return count;
    }
    static char *scat(char *dest, const char *src)
    {
        char *end = dest + slen(dest) - 1;
        while (*src != '\0')
        {
            *end++ = *src++;
        }
        *end = '\0';
        return dest;
    }
};