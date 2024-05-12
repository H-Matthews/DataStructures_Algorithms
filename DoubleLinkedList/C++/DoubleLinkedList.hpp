

struct Node 
{
    int data;
    Node* pNext;
    Node* pPrev;
};


class DoubleLinkedList 
{
    private:
        Node* head;
        Node* tail;
        unsigned int _len;

        Node* initializeNode(const int value);

    public:
        DoubleLinkedList();

        void insertBeginning(const int value);

        bool insertAtPosition(const int value, const int position);

        void insertEnd(const int value);

        bool isEmpty();

        void print();

        void printBackwards();
};