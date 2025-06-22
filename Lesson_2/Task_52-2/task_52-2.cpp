// Занятие 2. Жизненный цикл объекта. RAII. Задание 2. Копирование умных массивов.
#include <iostream>

// Класс для умного массива целого типа
class smart_array
{
private:
	int* arr{nullptr};
	int num{}, count{};
public:
	smart_array(int aSize) : num{ aSize }
	{
		
		if (aSize > 0)
		{
			arr = new int[aSize] {};
			std::cout << "Вызов конструктора smart_array:" << std::endl;
			std::cout << "Создан массив размерностью " << aSize << " элементов" << std::endl;
		}
		else
		{
			throw std::exception(" Неправильный размер массива");
		}
	}

	void add_element(int aValue)
	{
		if (count < num)
		{
			arr[count] = aValue;
			std::cout << " В массив добавлен элемент со значением " << arr[count] << ": arr[" << count << "]=" << arr[count] << std::endl;
			++count;
		}
		else
		{
			throw std::exception("\n!!! Для добавления элемента превышена размерность массива");
		}
	}

	int get_element(int ind)
	{
		if ((ind >= 0) && (ind <= count))
		{
			return arr[ind];
		}
		else
		{
			throw std::exception("\n!!! Введен неправильный индекс для массива");
		}
	}

	// Перегрузка оператора = для копирования массивов
	smart_array& operator=(const smart_array& other)
	{
		if (this == &other)
		{
			return *this;
		}
		else
		{
			delete[] arr;
			num = other.num;
			count = other.count;
			arr = new int[num] {};
			for (int i{}; i < num; ++i)
			{
				arr[i] = other.arr[i];
			}
		}
		return *this;
	}

	void print_data()
	{
		for (int i{}; i < count; ++i)
		{
			std::cout << arr[i] << " ";
		}
		std::cout << std::endl;
	}

	~smart_array()
	{
		delete[] arr;
		std::cout << "\nВыход из области действия. Вызов деструктора smart_array. Память под массив освобождена." << std::endl;
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");
	try {
		smart_array arr(5);
		arr.add_element(1);
		arr.add_element(4);
		arr.add_element(155);
		
		smart_array new_array(2);
		new_array.add_element(44);
		new_array.add_element(34);

		std::cout << "Исходный первый массив:" << std::endl;
		arr.print_data();
		std::cout << "Исходный второй массив:" << std::endl;
		new_array.print_data();
		arr = new_array;    // Копирование массивов
		std::cout << "Копирование второго массива в первый:" << std::endl;
		arr.print_data();
		
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}

	return EXIT_SUCCESS;
}