#include <iostream>
#include "SplayTree.h"
#include "University.h"

using namespace std;

int main()
{
	SplayTree<Subject> tree;
	Subject a;
	a.hours = 2;
	tree.Insert(a);
	a.hours = 12;
	tree.Insert(a);
	a.hours = 5;
	tree.Insert(a);
	a.hours = 42;
	tree.Insert(a);
	a.hours = 1;
	tree.Insert(a);
	a.hours = 37;
	tree.Insert(a);
	tree.print();
	return 0;
}