#pragma once
#include <iostream>

class abstract
{
protected:
    char *str;

public:
    abstract()
    {
        str = new char[1];
        str[0] = '\0';
    }
    ~abstract()
    {
        if (str != nullptr)
        {
            delete[] str;
        }
    }
    char *get() const
    {
        return str;
    }
    virtual void set(char *val);
    virtual size_t length() const;
};

class chars : public abstract
{
public:
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