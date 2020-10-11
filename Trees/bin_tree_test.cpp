#include <iostream>
#include "tree.h"

int main() 
{
	BinaryTree<double>* mytree = new BinaryTree<double>;
	mytree->push(5);
	mytree->push(10);
	mytree->push(9);
	mytree->push(12);
	mytree->push(11);
	mytree->push(13);
	mytree->push(2);
	mytree->push(1);
	mytree->push(3);
	mytree->push(4);
	mytree->print();
	mytree->remove(10);
	std::cout << '\n' ;
	mytree->print();
	return 0;
}