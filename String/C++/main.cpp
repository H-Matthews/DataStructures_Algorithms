#include "MyString.hpp"
#include <iostream>

int main()
{
    MyString s1("Test");

    std::cout << "Printing MyString Length: " << s1.length() << std::endl;
    std::cout << "Printing MyString Buffer: " << s1.buffer() << std::endl;

    s1 = "Harrison";

    std::cout << "Printing MyString Length: " << s1.length() << std::endl;
    std::cout << "Printing MyString Buffer: " << s1.buffer() << std::endl;

    return 0;
}