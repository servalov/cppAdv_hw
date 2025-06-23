// Зантие 3. Шаблоны и функторы. Задание 1. Возведение в квадрат.
#include <iostream>
#include <vector>

// Шаблонная функция возведения в квадрат
template<typename Type>
Type squreData(Type a)
{
	return a * a;
}

// Шаблонная функция возведения в квадрат элементов вектора
template <typename Type>
std::vector<Type> squreData(std::vector<Type>& a)
{
	std::vector<Type> c;
	for (int i:a)
	{
		c.push_back(squreData(i));
	}
	return c;
}

int main()
{
	setlocale(LC_ALL,"Russian");
	int a{ 4 };
	std::cout << a << " в квадрате равно " << squreData(a) << std::endl;

	std::vector<int> b {-1, 4, 8};
	std::vector<int> c=squreData(b);

	std::cout << "Массив, возведенный в квадрат:" << std::endl;
	for (int i : c)
	{
		std::cout << i << " ";
	}
	return EXIT_SUCCESS;
}