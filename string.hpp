#pragma once
#include <iostream>

class chars
{
public:
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

class string : chars, operators
{
private:
    char *str;

public:
    string(char *val = "");
    string(size_t size = 1);
    char *get();
    string set(char *val);
    ~string();
    int length();
};

class operators
{
private:
    friend std::ostream &operator<<(std::ostream &os, const string &obj); // output
    friend std::istream &operator>>(std::istream &is, string &obj);       // input
    friend string operator+(const string &s1, const string &s2);          // concatenation
    string &operator=(const string &s);                                   // equation
};