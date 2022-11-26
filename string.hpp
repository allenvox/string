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
    static int scmp(const char *s1, const char *s2)
    {
        char c1, c2;
        while (1)
        {
            c1 = *s1++;
            c2 = *s2++;
            if (c1 > c2)
            {
                return 1;
            }
            else if (!c1)
            {
                break;
            }
            else
            {
                return -1;
            }
        }
        return 0;
    }
};

class string
{
private:
    char *str;

public:
    string(const char *val = ""); // init by value
    string(size_t size = 1);      // init by size
    string(const string &str);    // init by copy another string
    char *get() const;
    string set(char *val);
    size_t length() const;
    ~string();
    string &operator=(const string &s); // equation
};

std::ostream &operator<<(std::ostream &os, const string &obj); // output
std::istream &operator>>(std::istream &is, string &obj);       // input
string operator+(const string &s1, const string &s2);          // concatenation
string operator+(const string &s1, const char &s2);
string operator+(const char &s1, const string &s2);
bool operator==(const string &s1, const string &s2); // equality