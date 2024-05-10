
struct Node
{
	int data;
	Node* pNext;
};


class SingleLinkedList
{	
	private:
		Node* head;
		Node* tail;
	public:
		SingleLinkedList();

		bool insertBeginning(int value);

		bool insertPosition(int value, int index);

		bool insertEnd(int value);

		int getSizeOfList();

		bool isEmpty();

		void print();
};
