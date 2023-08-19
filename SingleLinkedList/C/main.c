#include "LinkedList.h"


int main()
{
	linkedlist_t* l1 = CreateLinkedList();
	
	insert(l1, 10);
	insert(l1, 20);
	PrintLinkedList(l1);
	DeleteLinkedList(l1);
	

	return 0;
}
