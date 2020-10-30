#include <iostream>
#include <vector>
#include <queue>
#include <set>


int main() {
	setlocale(LC_ALL, "Russian");
	std::vector<std::vector<std::pair<int, int>>> graph;
	std::cout << "¬ведите начальное кол-во вершин: ";
	
	int32_t N, total = 0;
	bool flag;
	std::cin >> N;

	graph = std::vector<std::vector<std::pair<int, int>>>(N + 1);

	std::cout << "¬ведите св€зи в формате \"вершина вершина вес\" (одинаковые вершины - конец ввода):\n";
	for (int i = 0; i < N * N; i++) {
		int32_t x, y, value;
		flag = true;
		std::cin >> x >> y;
		if (x == y)
			break;
		total += 1;
		std::cin >> value;

		for (auto item: graph[x]) { 
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

	std::vector<bool> U(N+1, false); // вершины в остовном дереве
	std::vector<int> D(N + 1, 1000000);
	std::vector<int> to(N + 1, -1);
	std::set<std::pair<int, int>> q;
	D[1] = 0;
	U[1] = true;

	q.insert({ 0, 0 });

	for (int i = 1; i<= N; i++)
		if (q.empty()) {
			std::cout << "Error";
			exit(0);
		}

	int current = q.begin()->first;
	q.erase(q.begin());

	if (to[current] != -1) {
		std::cout << "from " << current << " to " << to[current] << '\n';
	}

	for (auto item : graph[current]) {
		int t = item.first, value = item.second;
		if (value < D[t]) {
			q.erase({ t, D[t] });
			D[t] = value;
			to[t] = current;
			q.insert({ t, D[t] });
		}
	}


	system("pause");
}