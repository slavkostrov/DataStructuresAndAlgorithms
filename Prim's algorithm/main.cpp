#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include "Header.h"

int main() {
	setlocale(LC_ALL, "Russian");
	std::vector<std::vector<std::pair<int, int>>> graph;
	std::cout << "1 - ���� ������������� �����\n2 - ������������� ��������� ����� �� 6 ��������\n";
	int key;
	std::cin >> key;
	graph = key == 1 ? graph_input() : test_input();
	mst_search(graph);
	

	system("pause");
}