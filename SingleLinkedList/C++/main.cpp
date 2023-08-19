#include "SingleLinkedList.hpp"
#include <iostream>


int main(int argc, char* argv[])
{
	SingleLinkedList a;

	a.insertBeginning(10);
	a.insertBeginning(20);
	a.print();

	return 0;
}
