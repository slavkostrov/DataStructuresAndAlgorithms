#include "Header.h"

std::vector<std::vector<std::pair<int32_t, int32_t>>> graph_input() {
	std::cout << "¬ведите начальное кол-во вершин: ";

	int32_t N;
	bool flag;
	std::cin >> N;
	
	std::vector<std::vector<std::pair<int, int>>> graph;
	graph = std::vector<std::vector<std::pair<int, int>>>(N + 1);

	std::cout << "¬ведите св€зи в формате \"вершина вершина вес\" (одинаковые вершины - конец ввода):\n";
	for (int i = 0; i < N * N; i++) {
		int32_t x, y, value;
		flag = true;
		std::cin >> x >> y;
		if (x == y)
			break;
		std::cin >> value;
		for (auto item : graph[x]) {
			if (item.first == y) {
				i--;
				flag = false;
				break;
			}
		}
		if (flag) {
			graph[x].emplace_back(std::make_pair(y, value));
			graph[y].emplace_back(std::make_pair(x, value));
		}
	}

	return graph;
}
std::vector<std::vector<std::pair<int32_t, int32_t>>> test_input()
{
	std::vector<std::vector<std::pair<int, int>>> graph;
	graph = std::vector<std::vector<std::pair<int, int>>>(6 + 1);

	graph[1].emplace_back(std::make_pair(2, 4));
	graph[2].emplace_back(std::make_pair(1, 4));

	graph[1].emplace_back(std::make_pair(3, 4));
	graph[3].emplace_back(std::make_pair(1, 4));

	graph[2].emplace_back(std::make_pair(3, 2));
	graph[3].emplace_back(std::make_pair(2, 2));

	graph[3].emplace_back(std::make_pair(4, 3));
	graph[4].emplace_back(std::make_pair(3, 3));

	graph[4].emplace_back(std::make_pair(5, 3));
	graph[5].emplace_back(std::make_pair(4, 3));

	graph[3].emplace_back(std::make_pair(5, 4));
	graph[5].emplace_back(std::make_pair(3, 4));

	graph[3].emplace_back(std::make_pair(6, 2));
	graph[6].emplace_back(std::make_pair(3, 2));

	graph[6].emplace_back(std::make_pair(5, 3));
	graph[5].emplace_back(std::make_pair(6, 3));

	return graph;
}
;
