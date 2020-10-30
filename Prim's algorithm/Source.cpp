#include "Header.h"

std::vector<std::vector<std::pair<int32_t, int32_t>>> graph_input() {
	std::cout << "������� ��������� ���-�� ������: ";

	int32_t N;
	bool flag;
	std::cin >> N;
	
	std::vector<std::vector<std::pair<int, int>>> graph;
	graph = std::vector<std::vector<std::pair<int, int>>>(N + 1);

	std::cout << "������� ����� � ������� \"������� ������� ���\" (���������� ������� - ����� �����):\n";
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
std::vector<int> mst_search(std::vector<std::vector<std::pair<int32_t, int32_t>>> graph)
{
	int32_t size = graph.size() - 1; // ������� ���������� � �������

	std::vector<int32_t> mst(size + 1); 
	std::vector<int32_t> min_distance_from(size + 1, 999999); // ������ ��� ����������� ����������� ����� �� �������
	std::vector<int32_t> to(size + 1, -1); // �������� ����� ����� ����������� ����� 
	/*
		�������� ����� � ������ ������� => ���������� �� ������� 0
	*/

	min_distance_from[1] = 0;

	std::set<std::pair<int32_t, int32_t> > q;
	q.insert({ 0, 1 }); // { min_to, to } 
	std::vector<bool> used(size + 1, false);

	for (int i = 1; i <= size; i++) 
	{
		


		if (q.empty()) // => ���� �� �������
		{
			std::cout << "���� �� �������!";
			exit(0);
		}

		int v = q.begin()->second;
		q.erase(q.begin());
		used[v] = true;

		if (to[v] != -1)
			std::cout << "from " << to[v] << " to " << v << '\n';

		for (auto item : graph[v]) {
			int32_t U = item.first,
				value = item.second;
			if (value < min_distance_from[U] && !used[U]) {
				q.erase({ min_distance_from[U], U });
				min_distance_from[U] = value;
				to[U] = v;
				q.insert({ min_distance_from[U], U });
			}
		}
	}
	return std::vector<int>();
}
;
