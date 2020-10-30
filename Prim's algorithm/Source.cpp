#include "Header.h"

std::vector<std::vector<std::pair<int32_t, int32_t>>> graph_input() {
	std::cout << "Введите начальное кол-во вершин: ";

	int32_t N;
	bool flag;
	std::cin >> N;
	
	std::vector<std::vector<std::pair<int, int>>> graph;
	graph = std::vector<std::vector<std::pair<int, int>>>(N + 1);

	std::cout << "Введите связи в формате \"вершина вершина вес\" (одинаковые вершины - конец ввода):\n";
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

	std::cout << "Input graph:\n";
	for (int i = 1; i < graph.size(); i++)
	{	
		std::cout << i << " : ";
		for (auto item : graph[i])
			std::cout << item.first << " ";
		std::cout << '\n';
	}
	std::cout << '\n';
	std::cout << "Total cost: " << 3 + 2 + 4 + 3 + 3 + 2 + 4 + 4;
	std::cout << '\n';
	std::cout << '\n';
	return graph;
}

std::vector<std::vector<int32_t>> mst_search(std::vector<std::vector<std::pair<int32_t, int32_t>>> graph)
{
	int32_t size = graph.size() - 1; // вершины нумеруются с единицы
	int32_t total_cost = 0;
	std::vector<std::vector<int32_t>> Tree(size + 1);
	std::vector<int32_t> mst(size + 1); 
	std::vector<int32_t> min_distance_to(size + 1, 999999); // хранит вес наименьшего допустимого ребра из вершины
	std::vector<int32_t> to(size + 1, -1); // содержит конец этого наименьшего ребра 
	/*
		Начинаем поиск с первой вершины => расстояние до которой 0
	*/

	min_distance_to[1] = 0;

	std::set<std::pair<int32_t, int32_t> > q;
	q.insert({ 0, 1 }); // { min_to, to } 
	std::vector<bool> used(size + 1, false);

	for (int i = 1; i <= size; i++) 
	{

		if (q.empty()) // => граф не связный
		{
			std::cout << "граф не связный!";
			exit(0);
		}

		int v = q.begin()->second;
		q.erase(q.begin());
		used[v] = true;

		if (to[v] != -1)
		{
			std::cout << "from " << to[v] << " to " << v << " with value = " << min_distance_to[v] << '\n';
			//Tree[v].push_back(to[v]);
			Tree[to[v]].push_back(v);
			total_cost += min_distance_to[v];
		}

		for (auto item : graph[v]) {
			int32_t U = item.first,
				value = item.second;
			if (value < min_distance_to[U] && !used[U]) {
				q.erase({ min_distance_to[U], U });
				min_distance_to[U] = value;
				to[U] = v;
				q.insert({ min_distance_to[U], U });
			}
		}
	}
	
	std::cout << "\nTotal cost: " << total_cost << '\n' << '\n';
	
	return Tree;
}
void print_mst_tree(std::vector<std::vector<int32_t>> Tree)
{
	print_level(Tree, 1, 0);
}

void print_level(std::vector<std::vector<int32_t>> Tree, int32_t element, int32_t level)
{
	for (int i = 0; i < level; i++)
		std::cout << " ";
	std::cout << element << '\n';
	for (auto item: Tree[element])
		print_level(Tree, item, level+1);
};
