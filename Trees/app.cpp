#include "app.h"

int32_t exec_app()
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

	std::cout << "Print function realisation with names:\n";
	print(Tree, false);
	std::cout << '\n';
	std::cout << "Print function realisation with colors:\n";
	print(Tree);
	std::cout << '\n';
	std::cout << "Backward pass realisation:\n";
	backward_pass(Tree);
	std::cout << "\n\nSymmetric pass realisation:\n";
	symmetric_pass(Tree);
	std::cout << "\n\nPath length realisation: ";
	path_length(Tree, "7");
	std::cout << "\n\nTree depth is " << depth(Tree) << "\n";
	return 0;
}
