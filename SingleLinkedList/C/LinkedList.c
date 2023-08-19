#include "LinkedList.h"
#include <stdlib.h> //malloc/free and NULL
#include <stdio.h> // printf

linkedlist_t* CreateLinkedList()
{
	linkedlist_t* newList = (linkedlist_t*)malloc(sizeof(linkedlist_t));
	newList->head = NULL;
	return newList;
}

void insert(linkedlist_t* list, int data)
{
	// Create new node and initialize Data
	node_t* newNode = (node_t*)malloc(sizeof(node_t));
	newNode->data = data;

	if(list->head == NULL)
		list->head = newNode;
	else
	{
		newNode->pNext = list->head;
		list->head = newNode;
	}
	
	return;
}

void PrintLinkedList(linkedlist_t* list)
{
	node_t* current = list->head;
	
	if(current == NULL)
		printf("List is Empty\n");
	else
	{
		while(current != NULL)
		{	
			printf("%d ", current->data);
			current = current->pNext;
		}
		printf("\n");
	}
}

void DeleteLinkedList(linkedlist_t* list)
{
	node_t* current = list->head;

	if(current == NULL)
			printf("List is empty\n");
	else
	{
		node_t* temp = NULL;

		while(current != NULL)
		{
			// Store the next node into temp
			temp = current->pNext;
			
			printf("Deleting Node: %d\n", current->data);

			// Free the current node that is pointing to head
			free(current);

			// Point the new current to look at temp
			current = temp;
		}
		// Now that all nodes have been destroyed, we must delete the actual list itself
		printf("Deleting the actual List!\n");
		free(list);

	}
}
