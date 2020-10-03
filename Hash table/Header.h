#ifndef HEADER_H 
#define HEADER_H

#include "stdint.h"
#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <iterator>


class registration { // Описание структуры в соответствии с вариантом
public:
	registration(int32_t number, std::string title, std::string founder); // конструктор
	int32_t number; // номер
	std::string title; // название
	std::string founder; // основатель
	/*
		Перегрузка необходимых операторов
	*/
	friend bool operator== (const registration& c1, const int& c2);
	friend bool operator== (const int& c2, const registration& c1);
	friend std::ostream& operator<< (std::ostream& out, const registration& obj);
	operator int();
};

template <class T = registration>
class HashTable {
	int32_t size; // размер массива
	int32_t actual_size; // актуальное кол-во элементов
	std::vector<std::list<T>> array; // размер
public:
	HashTable(int32_t size) { // конструктор таблицы
		this->actual_size = 0;
		this->size = size;
		array = std::vector<std::list<T>>(size);
	};

	uint32_t hash(int32_t value) { // функция хеширования 
		std::string s = std::to_string(value); 
		uint32_t hash_result = 0;
		for (int i = 0; s[i] != 0; ++i)
		{
			hash_result = ((this->size-1) * hash_result + s[i]) % this->size;
		}
		hash_result = (hash_result * 2 + 1) % this->size;
		return hash_result;
	};
	

	void add(T obj, int32_t value) {
		if (this->actual_size > this->size)this->rehash(); // проверка на необходимость рехеширования
		int32_t hash_value = this->hash(value); // вычисление хэш суммы
		std::cout << "Hash value = " << hash_value << '\n'; // вывод вот этой строки
		array[hash_value].push_back(obj); // добавление нового объекта в таблицу
		this->actual_size += 1; // увеличение актуального размера
	};
	

	void delete_(int32_t value) { // метод удаления
		int32_t hash_value = this->hash(value); // вычисление хэш суммы
		auto iter = array[hash_value].begin(); //  инициализация итератора
		for (iter; iter != array[hash_value].end(); ++iter)  // цикл поиска нужного значения в списке
			if (*iter == value) {
				array[hash_value].erase(iter);
				std::cout << "Deleted!\n";
				this->actual_size -= 1; // уменьшение актуального размера
				return;
			}
		std::cout << "Not found!";
	};
	

	void search(int32_t value) { // функция поиска аналогичная функции удаления
		int32_t hash_value = this->hash(value);
		auto iter = array[hash_value].begin();
		for (iter; iter != array[hash_value].end(); ++iter)
			if (*iter == value) {
				std::cout << "Found!\n";
				std::cout << *iter;
				return;
			}
		std::cout << "Not found.\n";
	};


	void rehash() { // функция рехеширования 
		std::vector<std::list<T>> new_array(this->size * 2); // создание нового массива
		this->size *= 2; // увеличение размера на 2
		for (auto x : this->array) // заполнение нового массива
			for (auto obj : x) {
				int value = obj;
				int32_t hash_value = this->hash(value);
				std::cout << "Hash value = " << hash_value << '\n';
				new_array[hash_value].push_back(obj);
			}
		this->array = new_array; // сохранение нового массива
	};
	

	void outputTable() { 
		/*
			Вывод хеш таблицы
		*/
		for (auto x: array)
			for (auto i : x) {
				std::cout << i << '\n';
			}
	}
};

#endif