#include <ciso646>
#include <iostream>
#include "Header.h"
int main()
{
    int N = 0;
    std::cout << "Введите размер списка: ";
    std::cin >> N;
    if (N < 2)
    {
        std::cout << "Неверный размер списка";
        return 0;
    }
    node* list = new node;
    input_list(list, N);
    return update_list(list);
}

