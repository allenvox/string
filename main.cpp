#include "string.hpp"
#include <iostream>

int main()
{
    string s1("hello");
    std::cout << s1 << std::endl;
    string s2("world");
    std::cout << s1 + " " + s2 << std::endl;
    exit(0);
}