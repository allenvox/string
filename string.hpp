#pragma once
#include <iostream>

class abstract
{
protected:
    char *str;

public:
    virtual char *get() const = 0;
    virtual void set(char *val) = 0;
    virtual size_t length() const = 0;
};

class chars : public abstract
{
public:
    char *get() const
    {
        return str;
    }
    void set(char *val)
    {
        delete[] str;
        str = new char[slen(val) + 1];
        scpy(str, val);
    }
    size_t length() const
    {
        return slen(str);
    }
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

class string : public chars
{
public:
    string(const char *val = "");
    string(size_t size = 1);
    string(const string &s);
    ~string()
    {
        if (str != NULL)
        {
            delete[] str;
        }
    }
    string &operator=(const string &s);
};

std::ostream &operator<<(std::ostream &os, const string &obj);
std::istream &operator>>(std::istream &is, string &obj);
string operator+(const string &s1, const string &s2);
bool operator==(const string &s1, const string &s2);