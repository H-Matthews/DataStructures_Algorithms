struct Node 
{
    Node* pNext;
    int data;
};


class Stack
{
    private:   
        Node* _top;
        int _len;

    public:
        Stack();

        void push(int value);

        int pop();

        int peek();

        void print();
};