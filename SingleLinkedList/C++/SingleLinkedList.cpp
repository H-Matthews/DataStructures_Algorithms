#include "SingleLinkedList.hpp"
#include "cstdio"

SingleLinkedList::SingleLinkedList()
{
	head = NULL;
	tail = NULL;
}

bool SingleLinkedList::isEmpty()
{
	bool isEmpty = false;
	if(head == NULL)
		isEmpty = true;
		
	return isEmpty;
}

bool SingleLinkedList::insertBeginning(int value)
{
	Node* newNode = new Node();
	newNode->data = value;
	newNode->pNext = NULL;
	
	if(isEmpty())
	{
		head = newNode;
		tail = newNode;
	}
	else
	{
		newNode->pNext = head;
		head = newNode;
	}
	printf("Successfully inserted value:%d\n", head->data);
	return 1;
}

bool SingleLinkedList::insertEnd(int value)
{
	Node* newNode = new Node();
	newNode->data = value;
	newNode->pNext = NULL;

	if(isEmpty())
	{	
		head = newNode;
		tail = newNode;
	}
	else
	{
		tail->pNext = newNode;
		tail = newNode;
	}
	printf("Successfully inserted value:%d\n", tail->data);
	return 1;
}

void SingleLinkedList::print()
{
	Node* current = head;

	while(current != NULL)
	{
		printf("%d ", current->data);

		current = current->pNext;
	}
	printf("\n");
}
