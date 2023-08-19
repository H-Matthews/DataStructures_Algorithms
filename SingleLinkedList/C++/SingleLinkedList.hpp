
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

		bool insertPosition(int value, int position);

		bool insertEnd(int value);

		bool isEmpty();

		void print();
};
