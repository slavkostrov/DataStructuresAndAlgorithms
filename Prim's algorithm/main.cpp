#include "Header.h"

int main() {
	setlocale(LC_ALL, "Russian");
	std::vector<std::vector<std::pair<int, int>>> graph;
	std::vector<std::vector<int32_t>> Tree;
	std::cout << "1 - ¬вод произвольного графа\n2 - »спользование тестового графа на 6 вершинах\n";
	int key;
	std::cin >> key;
	system("cls");
	graph = key == 1 ? graph_input() : test_input();
	Tree = mst_search(graph);
	std::cout << "Tree with root in 1 element:\n";
	print_mst_tree(Tree);
	system("pause");
}