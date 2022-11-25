#pragma once
#include <iostream>

class string
{
private:
    char *str;
    friend std::ostream &operator<<(std::ostream &os, const string &obj);
    friend std::istream &operator>>(std::istream &is, string &obj);
    friend string operator+(const string &s1, const string &s2);

public:
    string(char *val = "");
    ~string();
    int length();
    string &operator=(const string &s);
    static char *scpy(char *dest, const char *src)
    {
        assert(dest != NULL && src != NULL);
        char *temp = dest;
        while ((*dest++ = *src++) != '\0')
        {
        }
        return temp;
    }
    static unsigned int slen(const char *str)
    {
        unsigned int count = 0;
        while (*str != '\0')
        {
            count++;
            str++;
        }
        return count;
    }
    static char *scat(char *dest, const char *src)
    {
        char *rdest = dest;
        while (*dest)
        {
            dest++;
        }
        while ((*dest++ = *src++))
        {
        }
        return rdest;
    }
};