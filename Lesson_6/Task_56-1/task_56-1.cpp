// Занятие 6. STL. Часть 2. Задача 1. Уникальный вектор
#include <iostream>
#include <vector>
#include <algorithm>

void print(int val)
{
	std::cout << val << " ";
}

int main()
{
	std::vector<int> in = { 1,1,2,5,6,1,2,4 };
	std::cout << "[IN]: ";
	for_each(in.begin(), in.end(), print);
	std::sort(in.begin(), in.end());
	auto new_end = unique(in.begin(), in.end());
	in.erase(new_end, in.end());
	std::cout << "\n[OUT]: ";;
	for_each(in.begin(), in.end(), print);

	return EXIT_SUCCESS;
}