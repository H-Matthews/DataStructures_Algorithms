typedef struct node
{
	int data;
	struct node* pNext;
} node_t;

typedef struct linkedlist
{
	struct node* head;
} linkedlist_t;

// Linked List functions

// Createlist
linkedlist_t* CreateLinkedList();

void PrintLinkedList(linkedlist_t* list);

void DeleteLinkedList(linkedlist_t* list);

void insert(linkedlist_t* list, int data);
