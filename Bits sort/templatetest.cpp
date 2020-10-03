#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <bitset>
using namespace std;

int main()
{
	setlocale(0, "");
	srand(time(NULL));

	int const mil = 1000000,  temp = 8999999, const N = 1e6;
	ofstream file; // поток записи в файл
	vector <int> init_array; // массив для последующего заполнения файла
	for (int i = 1000 * 1000; i < 10 * 1000 * 1000; i++) // заполнение массива числами
	{
		init_array.push_back(i);
	}
	random_shuffle(init_array.begin(), init_array.end()); // перемешивание массива
	file.open("file.txt"); // открытие файла
	if (file)
	{
		for (int i = 0; i < N; i++)
		{
			file << init_array[i] << ' '; // запись в файл
		}

		cout << "file is ready!\n";
	}
	else
		return -1;
	file.close();
	system("pause");
	ifstream file_;
	// vector<bool> arr(temp, 0); // создание массива bool и инициализаци нулями
	bitset<temp> arr;
	int i = 0, t;
	file_.open("file.txt");
	double start = clock();
	if (file_)
	{
		for (int i = 0; i < N; i++)
		{
			/*
				Заполнение массива единицами
			*/
			file_ >> t;
			arr[t - mil] = 1;
		}

		cout << "sorted!\n";
	}
	else
		return -1;

	file_.close();
	std::cout << "Time: " << (clock() - start) / 1000 << '\n';
	system("pause");

	ofstream file_sorted;

	file_sorted.open("file.txt");

	if (file_sorted)
	{
		/*
			Запись в файл
		*/
		for (int i = 0; i < temp; i++)
		{
			if (arr[i])
			{
				file_sorted << i + mil << '\n';
			}
		}

		cout << "file is sorted!\n";
	}
	else
		return -1;
	
}
