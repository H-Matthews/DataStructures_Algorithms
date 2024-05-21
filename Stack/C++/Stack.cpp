#include "Stack.hpp"
#include "stdio.h"
#include <cstdlib>


Stack::Stack()
{
    _top = NULL;
    _len = 0;
}

void Stack::push(int value)
{
    Node* item = new Node;
    item->data = value;
    item->pNext = _top;

    _top = item;
    _len++;
}

int Stack::pop()
{
    Node* temp = _top;
    _top = _top->pNext;

    int value = temp->data;
    delete temp;
    _len--;
    
    return value;
}

int Stack::peek()
{
    if(_top != NULL)
        return _top->data;

    return -1;
}

void Stack::print()
{
    Node* curr = _top;

    while(curr != NULL)
    {
        printf("%d ", curr->data);

        curr = curr->pNext;
    }
    printf("\n");
}