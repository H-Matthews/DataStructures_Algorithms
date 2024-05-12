#include "DoubleLinkedList.hpp"

int main()
{
    DoubleLinkedList a;
    DoubleLinkedList b;

    b.print();
    b.printBackwards();

    a.insertBeginning(1);
    a.insertEnd(3);

    a.insertAtPosition(2, 1);

    a.print();
    a.printBackwards();
    
    return 0;
}