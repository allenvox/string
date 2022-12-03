#include "string.hpp"
#include <iostream>

int main()
{
    string s1("");
    std::cout << "s1 = " << s1 << std::endl;

    s1.set("hello");
    std::cout << "s1 = " << s1 << std::endl;

    string s2("world");
    std::cout << "s2 = " << s2 << std::endl;

    string s3("!!!");
    std::cout << "s3 = " << s3 << std::endl;

    s3 = "...";
    std::cout << "s3 = " << s3 << std::endl;

    std::cout << "(s1 == s2) = " << std::noboolalpha << (s1 == s2) << std::boolalpha << " (not equal)" << std::endl;

    std::cout << "s1 + s2 + s3 = " << s1 + " " + s2 + s3 << std::endl;

    s2.append(" is ");
    std::cout << "s2.append(' is ').append('great!') = " << s2.append("great!") << std::endl;
    exit(0);
}