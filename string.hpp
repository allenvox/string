#pragma once

class string
{
    friend string operator+(const string &s1, const string &s2);
    char *str;

public:
    string();
    string(char *val);
    ~string();
    static char *strcpy(const char *src, char *dest);
    static int strlen(const char *str);
    int length();
    string &operator=(const string &s);
    static char *strcat(char *dest, const char *src);
};