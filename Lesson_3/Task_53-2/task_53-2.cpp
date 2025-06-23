// Занятие 3. Шаблоны и функторы. Задание 2. Таблица
#include <iostream>

// Шаблонный класс для двумерного динамического массива
template <class T>
class DynamicArray
{
	private:
		T** arr{nullptr};
		int n{}, m{};

	public:
		DynamicArray(int n_row, int n_col) : n{ n_row }, m{ n_col }
		{
			arr = new T*[n_row]{};
			for (int i{}; i < n_row; ++i)
				arr[i] = new T[n_col]{};
		}
		
		// Константная версия оператора [] для вывода данных массива
		const T* operator[](int i) const
		{
			return arr[i];
		}
		
		// Неконстантная версия оператора [] для задания значений элементам массива
		T* operator[](int i)
		{
			return arr[i];
		}
		
		// Функция определения размера массива
		const int Size() const
		{
			return n * m * sizeof(T);
		}

		~DynamicArray()
		{
			for (int i{}; i < n; ++i)
				delete[] arr[i];
			delete[] arr;
			std::cout << "Вызов деструктора" << std::endl;
		}
};

int main()
{
	setlocale(LC_ALL,"Russian");
	auto test = DynamicArray<double>(2, 5);
	test[0][0] = 4.15;
	std::cout << test[0][0] << std::endl;
	std::cout <<"Размер таблицы - "<< test.Size() <<" байт "<< std::endl;
	return EXIT_SUCCESS;
}