#include "string.hpp"
#include <iostream>

int main()
{
    string s1("hello");
    std::cout << s1 << std::endl;
    string s2("world");
    std::cout << s2 << std::endl;
    string s3("damn!");
    std::cout << s3 << std::endl;
    std::cout << s1 + " " + s2 + " " + s3 << std::endl;
    exit(0);
}