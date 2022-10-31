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
    // static char *scpy(const char *src, char *dest);
    // static int slen(const char *str);
    int length();
    string &operator=(const string &s);
    // static char *scat(char *dest, const char *src);
};