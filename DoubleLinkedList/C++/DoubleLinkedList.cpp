#include "DoubleLinkedList.hpp"
#include <stdio.h>

DoubleLinkedList::DoubleLinkedList()
{
    head = NULL;
    tail = NULL;
    _len = 0;
}

Node* DoubleLinkedList::initializeNode(const int value)
{
    Node* newNode = new Node;
    newNode->data = value;
    newNode->pNext = NULL;
    newNode->pPrev = NULL;

    return newNode;
}

void DoubleLinkedList::insertBeginning(const int value)
{
    Node* newNode = initializeNode(value);

    if(isEmpty())
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        head->pPrev = newNode;
        newNode->pNext = head;
        head = newNode;
    }

    printf("Successful Insertion of value %d at HEAD\n", value);
    _len++;
}

bool DoubleLinkedList::insertAtPosition(const int value, const int position)
{
    if (position <= 0 || position > _len)
    {
        printf("Insert Failed - Invalid Position. The list is size %d, position given %d\n", _len, position);
        return false;
    }

    Node* newNode = initializeNode(value);

    if(position == 1)
    {
        newNode->pNext = head->pNext;
        newNode->pPrev = head;
        head->pNext->pPrev = newNode;
        head->pNext = newNode;

        _len++;
        printf("Successful Insertion of value %d at position %d\n", value, position);
    }
    else if(position == _len)
    {
        newNode->pNext = tail;
        newNode->pPrev = tail->pPrev;
        tail->pPrev->pNext = newNode;
        tail->pPrev = newNode;

        _len++;
        printf("Successful Insertion of value %d at position %d\n", value, position);
    }
    else
    {
        Node* current = head;
        int tempPosition = position - 1;

        while(current != NULL)
        {
            if(tempPosition-- == 0)
            {
                newNode->pNext = current;
                newNode->pPrev = current->pPrev;

                if(current->pPrev == head)
                    head->pNext = newNode;

                current->pPrev = newNode;
                
                _len++;
                printf("Successful Insertion of value %d at position %d\n", value, position);
                break;
            }

            current = current->pNext;
        }
    }

    return true;
}

void DoubleLinkedList::insertEnd(const int value)
{
    Node* newNode = initializeNode(value);

    if(isEmpty())
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        newNode->pPrev = tail;
        tail->pNext = newNode;
        tail = newNode;
    }

    printf("Successful Insertion of value %d at TAIL\n", value);
    _len++;
}

bool DoubleLinkedList::isEmpty()
{
    bool empty = false;
    if(head == NULL)
        empty = true;
    
    return empty;
}

void DoubleLinkedList::print()
{
    if(isEmpty())
        printf("Empty List\n");
    else
    {
        Node* current = head;

        while(current != NULL)
        {
            printf("%d ", current->data);

            current = current->pNext;
        }

        printf("\n");
    }
}

void DoubleLinkedList::printBackwards()
{
    if(isEmpty())
        printf("Empty List\n");
    else
    {
        Node* current = tail;

        while(current != NULL)
        {
            printf("%d ", current->data);

            current = current->pPrev;
        }

        printf("\n");
    }
}