#ifndef HEADER_H
#define HEADER_H

#include <vector>
#include <iostream>
#include <set>

std::vector<std::vector<std::pair<int32_t, int32_t>>> graph_input();
std::vector<std::vector<std::pair<int32_t, int32_t>>> test_input();
std::vector<std::vector<int32_t>> mst_search(std::vector<std::vector<std::pair<int32_t, int32_t>>> graph);
void print_mst_tree(std::vector<std::vector<int32_t>> Tree);
void print_level(std::vector<std::vector<int32_t>> Tree, int32_t element, int32_t level);

#endif // !1
