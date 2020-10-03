#include <ciso646>
#include <iostream>
#include "Header.h"

using namespace std;


int main()
{
    std::cout << "Enter num. of elements to input: ";
    uint16_t size;
    std::cin >> size; // Ввод кол-ва элементов
    HashTable<registration> Table(size * 2); // создание хеш таблицы размера 2*size
    std::cout << "Input example: number title founder\nInput " << size << " strings\n";
    for (int i = 0; i < size; ++i) {
        int32_t num; // номер
        std::string title; // название 
        std::string founder; // учредитель 
        cin >> num >> title >> founder; // ввод информации об объекте
        Table.add(registration(num, title, founder), num); // добавление элемента в таблицу
    }
    system("pause");
    while (1) {
        system("cls");
        /*
            Тест программы
        */
        std::cout << "0 - Break\n1 - Search\n2 - Delete\n3 - Rehash\n4 - Print table\n";
        uint16_t input;
        cin >> input; // Ввод команды
        if (input == 0)break; // Выход из цикла теста
        if (input == 1) {
            /*
                Поиск элемента в таблице
            */
            system("cls");
            std::cout << "Ener num.: ";
            int32_t temp;
            cin >> temp;
            std::cout << '\n';
            Table.search(temp);
            std::cout << '\n';

        }
        else if (input == 2) {
            /*
                Удаление элемента из таблицы
            */
            system("cls");
            std::cout << "Ener num.: ";
            int32_t temp;
            cin >> temp;
            std::cout << '\n';
            Table.delete_(temp);
            std::cout << '\n';

        }
        else if (input == 3)
            /*
                Выполнение рехеширования
            */
            Table.rehash();
        else
            /*
                Вывод всех элементов таблицы
            */
            Table.outputTable();
        system("pause");
    }
    return 0;
}

