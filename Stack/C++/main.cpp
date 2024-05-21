#include "Stack.hpp"
#include <iostream>


int main()
{
    Stack s1;

    s1.push(5);
    s1.push(7);
    s1.push(8);

    int value = s1.pop();

    std::cout << "Value from Pop: " << value << std::endl;

    s1.print();

    int peek = s1.peek();

    std::cout << "Value from peek: " << peek << std::endl;

    s1.print();

    return 0;
}