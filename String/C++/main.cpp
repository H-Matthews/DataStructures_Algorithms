#include "MyString.hpp"
#include <iostream>

int main()
{
    MyString s1("Harrison");
    MyString s2 = " Matthews";
    MyString s3;

    std::cout << "Printing s1 Length: " << s1.length() << std::endl;
    std::cout << "Printing s1 Buffer: " << s1.buffer() << std::endl;

    std::cout << "Printing s2 Length: " << s2.length() << std::endl;
    std::cout << "Printing s2 Buffer: " << s2.buffer() << std::endl;

    s3 = s1 + s2;

    std::cout << "Printing s3 Length: " << s3.length() << std::endl;
    std::cout << "Printing s3 Buffer: " << s3.buffer() << std::endl;

    return 0;
}