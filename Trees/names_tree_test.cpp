#include <iostream>
#include <string>
#include "names_tree.h"

int main() 
{
	std::cout << "Enter first name: ";
	std::string name;
	getline(std::cin, name);
	node* Tree = new node(name, true);
	std::cout << "Now input next names (\"end\" = exit)\n";
	getline(std::cin, name);
	while (name != "end") {
		push(&Tree, name);
		getline(std::cin, name);
	}
	std::cout << '\n';
	print(Tree);
	return 0;
}