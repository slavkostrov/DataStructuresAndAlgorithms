#ifndef HEADER_H
#define HEADER_H

#include <vector>
#include <iostream>
#include <set>

std::vector<std::vector<std::pair<int32_t, int32_t>>> graph_input();
std::vector<std::vector<std::pair<int32_t, int32_t>>> test_input();
std::vector<int> mst_search(std::vector<std::vector<std::pair<int32_t, int32_t>>> graph);

#endif // !1
