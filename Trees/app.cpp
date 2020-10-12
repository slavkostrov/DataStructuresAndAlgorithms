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

int32_t interactive_app()
{
	std::cout << "Enter first element value: ";
	std::string name;
	uint16_t command;
	getline(std::cin, name);
	node* Tree = new node(name, true);
	std::cout << "Root is created !\n";
	while (true)
	{
		std::cout << "0 - Exit\n1 - Add new element\n2 - Print tree (elements)\n3 - Print tree colors\n4 - Backward pass\n5 - Symmetric pass";
		std::cout << "\n6 - Tree's depth\n7 - Length of path to element\nCommand: ";
		std::cin >> command;
		system("cls");
		if (command == 0)
			break;
		if (command == 1)
		{
			std::cout << "Input value to push: ";
			std::cin >> name;
			if (push(&Tree, name) == 0)
				std::cout << "Added.\n";
			else
				std::cout << "Error\n";
			system("pause");
			system("cls");
		}
		if (command == 2)
		{
			std::cout << "Tree struct:\n";
			print(Tree, false);
			std::cout << '\n';
			system("pause");
			system("cls");
		}
		if (command == 3)
		{
			std::cout << "Tree struct (colors):\n";
			print(Tree, true);
			std::cout << '\n';
			system("pause");
			system("cls");
		}
		if (command == 4)
		{
			std::cout << "Backward pass realisation:\n";
			backward_pass(Tree);
			std::cout << '\n';
			system("pause");
			system("cls");
		}
		if (command == 5)
		{
			std::cout << "Symmetric pass realisation:\n";
			symmetric_pass(Tree);
			std::cout << '\n';
			system("pause");
			system("cls");
		}
		if (command == 6)
		{
			std::cout << "Tree depth is " << depth(Tree) << "\n";
			system("pause");
			system("cls");
		}
		if (command == 7)
		{
			std::cout << "Input value for search: ";
			std::cin >> name;
			std::cout << "Path length to " << name << " :\n";
			path_length(Tree, name);
			std::cout << '\n';
			system("pause");
			system("cls");
		}
	}
	system("cls");
	return 0;
}
