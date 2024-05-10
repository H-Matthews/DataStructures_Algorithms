#include "SingleLinkedList.hpp"
#include "cstdio"

SingleLinkedList::SingleLinkedList()
{
	head = NULL;
	tail = NULL;
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

bool SingleLinkedList::insertPosition(int value, int index)
{
	Node* newNode = new Node();
	newNode->data = value;
	newNode->pNext = NULL;

	if(index <= 0 )
	{
		printf("Failed. Cannot use index: %d\n", index);
		return 0;
	}

	int currentIndexCounter = 0;
	index = index - 1;				// Account for 0 indexing

	if(isEmpty())
	{
		head = newNode;
		tail = newNode;
	}
	else if(getSizeOfList() <= index)
	{
		tail->pNext = newNode;
		tail = newNode;

		currentIndexCounter = getSizeOfList() - 1;	// Very Inefficient
	}
	else if(index == 0)
	{
		newNode->pNext = head;
		head = head->pNext;
		head = newNode;
	}
	else
	{
		Node* it = head;
		Node* next = head->pNext;

		while(next != NULL)
		{
			if (currentIndexCounter++ == index)
			{
				it->pNext = newNode;
				newNode->pNext = next;
				break;
			}

			if(next == tail && currentIndexCounter == index)
			{
				it->pNext = newNode;
				newNode->pNext = next;
				break;
			}

			it = it->pNext;
			next = next->pNext;
		}
	}
	printf("Successfully inserted value:%d at position:%d\n", value, currentIndexCounter + 1);
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

int SingleLinkedList::getSizeOfList()
{
	Node* it = head;
	int size = 0;
	while( it != NULL)
	{
		size++;
		it = it->pNext;
	}

	return size;
}

bool SingleLinkedList::isEmpty()
{
	bool isEmpty = false;
	if(head == NULL)
		isEmpty = true;
		
	return isEmpty;
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
