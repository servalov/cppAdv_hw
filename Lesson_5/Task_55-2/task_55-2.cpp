// Занятие 5. STL. Часть первая. Задание 1. Удаление дубликатов
#include <iostream>
#include <set>

int main()
{
	setlocale(LC_ALL, "Russian");
	std::set<int, std::greater<int>> res_set;
	int count{}, num{};
	
	std::cout<< "Ведите количество значений: ";
	std::cin >> count;
	std::cout <<"[IN]:"<< std::endl;
	for (int i{}; i < count; ++i)
	{
		std::cin >> num;
		res_set.insert(num);
	}
	std::cout << std::endl;
	
	std::cout << "[OUT]:" << std::endl;
	std::cout << "Массив без дубликатов в порядке убывания: " << std::endl;
	for (const auto& el : res_set)
	{
		std::cout << el << std::endl;
	}
		
	return EXIT_SUCCESS;
}