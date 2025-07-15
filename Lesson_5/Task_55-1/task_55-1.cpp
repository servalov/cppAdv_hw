// Занятие 5. STL. Часть первая. Задание 1. Частота символов
#include <iostream>
#include <set>
#include <map>

int main()
{

	std::string str{"Hello World!!"};
	std::cout << "[IN]:" << str << std::endl;
	
	std::multiset<char> res_multiset;
	std::set<char> res_set;
	std::multimap<int, char, std::greater<int>> res_multimap;

	res_multiset.insert(str.begin(), str.end());
	res_set.insert(res_multiset.begin(), res_multiset.end());

	for (const auto& el : res_set)
	{
		res_multimap.insert(std::make_pair(res_multiset.count(el),el));
	}

	std::cout << "[OUT]:" << std::endl;
	for (const auto& el : res_multimap)
	{
		std::cout << el.second<<": "<<el.first<<std::endl;
	}

	std::cout << std::endl;

	return EXIT_SUCCESS;
}