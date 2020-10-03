#include "Header.h"
#include <iostream>
void input_list(node* temp, int N) {
    for (int i = 0; i < N; i++) { // цикл ввода списка 
        std::cin >> temp->value;
        if (i != N - 1) {
            temp->pointer = new node;
            temp = temp->pointer;
        }
        else {
            temp->pointer = nullptr;
        }
    }
}
int update_list(node* list) {
    node* temp;

    bool incr = false; // по неубыванию
    bool decr = false; // по невозрастанию
    bool flag = false; // упорядоченность

    temp = list;
    int current_value = temp->value;

    while (temp->pointer != nullptr) { // цикл для проверки упорядоченности
        temp = temp->pointer;

        if (((temp->value < current_value && incr == true) || (temp->value > current_value && decr == true))) {
            flag = true;
            break;
        }
        if (temp->value < current_value) {
            decr = true;
        }

        if (temp->value > current_value) {
            incr = true;
        }
        current_value = temp->value;
    }


    if (flag == true) { // цикл удаления элементов кратных четырем
        std::cout << "Список после удаления элементов кратных четырем\n";
        temp = list;
        int i = 1;
        while (temp != nullptr)
        {
            if (i % 4 == 3)
            {
                if (temp->pointer != nullptr) {
                    node* t = temp->pointer;
                    temp->pointer = temp->pointer->pointer;
                    delete t;
                    i++;
                }
            }
            temp = temp->pointer;
            i++;
        }
        temp = list;
        while (temp != nullptr)
        {
            std::cout << temp->value << " ";
            temp = temp->pointer;
        }
        return 0;
    }
    else {
        if (incr == true) {
            std::cout << "Последовательность упорядочена по неубыванию\n";
        }
        else {
            std::cout << "Последовательность упоряочена по невозрастанию\n";
        }
        temp = list;
        while (temp != nullptr) {
            std::cout << temp->value << " ";
            temp = temp->pointer;
        }
    }
    return 0;
}
