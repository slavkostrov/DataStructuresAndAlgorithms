#ifndef HEADER_H 
#define HEADER_H

#include "stdint.h"
#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <iterator>


class registration { // �������� ��������� � ������������ � ���������
public:
	registration(int32_t number, std::string title, std::string founder); // �����������
	int32_t number; // �����
	std::string title; // ��������
	std::string founder; // ����������
	/*
		���������� ����������� ����������
	*/
	friend bool operator== (const registration& c1, const int& c2);
	friend bool operator== (const int& c2, const registration& c1);
	friend std::ostream& operator<< (std::ostream& out, const registration& obj);
	operator int();
};

template <class T = registration>
class HashTable {
	int32_t size; // ������ �������
	int32_t actual_size; // ���������� ���-�� ���������
	std::vector<std::list<T>> array; // ������
public:
	HashTable(int32_t size) { // ����������� �������
		this->actual_size = 0;
		this->size = size;
		array = std::vector<std::list<T>>(size);
	};

	uint32_t hash(int32_t value) { // ������� ����������� 
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
		if (this->actual_size > this->size)this->rehash(); // �������� �� ������������� �������������
		int32_t hash_value = this->hash(value); // ���������� ��� �����
		std::cout << "Hash value = " << hash_value << '\n'; // ����� ��� ���� ������
		array[hash_value].push_back(obj); // ���������� ������ ������� � �������
		this->actual_size += 1; // ���������� ����������� �������
	};
	

	void delete_(int32_t value) { // ����� ��������
		int32_t hash_value = this->hash(value); // ���������� ��� �����
		auto iter = array[hash_value].begin(); //  ������������� ���������
		for (iter; iter != array[hash_value].end(); ++iter)  // ���� ������ ������� �������� � ������
			if (*iter == value) {
				array[hash_value].erase(iter);
				std::cout << "Deleted!\n";
				this->actual_size -= 1; // ���������� ����������� �������
				return;
			}
		std::cout << "Not found!";
	};
	

	void search(int32_t value) { // ������� ������ ����������� ������� ��������
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


	void rehash() { // ������� ������������� 
		std::vector<std::list<T>> new_array(this->size * 2); // �������� ������ �������
		this->size *= 2; // ���������� ������� �� 2
		for (auto x : this->array) // ���������� ������ �������
			for (auto obj : x) {
				int value = obj;
				int32_t hash_value = this->hash(value);
				std::cout << "Hash value = " << hash_value << '\n';
				new_array[hash_value].push_back(obj);
			}
		this->array = new_array; // ���������� ������ �������
	};
	

	void outputTable() { 
		/*
			����� ��� �������
		*/
		for (auto x: array)
			for (auto i : x) {
				std::cout << i << '\n';
			}
	}
};

#endif