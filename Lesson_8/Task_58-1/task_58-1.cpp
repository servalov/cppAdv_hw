//Move семантика. Задача 1. Перемещение объектов
#include <iostream>
#include <vector>
#include <algorithm>

template<typename T>
void move_vectors(std::vector<T>& a, std::vector<T>& b)
{
	b = std::move(a);
}

int main()
{
	setlocale(LC_ALL,"Russian");
	std::vector <std::string> one = { "test_string1", "test_string2" };
	std::vector <std::string> two;
	
	// Вывод на экран исходных массивов
	std::cout << "\nМассив one. Размер массива: " <<one.size()<<std::endl;
	std::for_each(one.begin(), one.end(), [](std::string i) {std::cout << i << " "; });
	std::cout << "\nМассив two. Размер массива: " << two.size() << std::endl;
	std::for_each(two.begin(), two.end(), [](std::string i) {std::cout << i << " "; });
	
	move_vectors(one, two);

	// Вывод на экран массивов после перемещения
	std::cout << "\nМассив one после перемещения.Размер массива: " << one.size() << std::endl;
	std::for_each(one.begin(), one.end(), [](std::string i) {std::cout << i << " "; });
	std::cout << "\nМассив two после перемещения. Размер массива: " << two.size() << std::endl;
	std::for_each(two.begin(), two.end(), [](std::string i) {std::cout << i << " "; });

	std::cout<<std::endl;
	return EXIT_SUCCESS;
}