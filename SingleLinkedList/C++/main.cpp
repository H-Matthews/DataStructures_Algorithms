#include "SingleLinkedList.hpp"

int main(int argc, char* argv[])
{
	SingleLinkedList a;

	a.insertBeginning(30);
	a.insertBeginning(20);
	a.insertBeginning(15);
	a.insertBeginning(10);
	a.print();
	a.insertPosition(17, 2);
	a.print();
	a.insertPosition(1000, 100);
	a.print();
	a.insertPosition(2000, 6);
	a.print();
	a.insertPosition(5, 1);
	a.print();
	a.insertPosition(3, -1);
	a.insertPosition(3, 0);
	a.print();
	a.insertEnd(1);
	a.insertBeginning(100000);
	a.print();

	return 0;
}
