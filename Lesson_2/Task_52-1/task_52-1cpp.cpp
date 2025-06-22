// Занятие 2. Жизненный цикл объекта. RAII. Задание 1. Умный массив.
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
				std::cout << " В массив добавлен элемент со значением " << arr[count] <<": arr["<<count<<"]="<< arr[count] << std::endl;
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
		
		~smart_array()
		{
			delete[] arr;
			std::cout <<"\nВыход из области действия. Вызов деструктора smart_array. Память под массив освобождена." << std::endl;
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
		arr.add_element(14);
		arr.add_element(15);
		std::cout <<"Значение элемента с индексом 1 равно "<< arr.get_element(1) << std::endl;
		std::cout << "Значение элемента с индексом 10 равно " << arr.get_element(10) << std::endl;
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}

	return EXIT_SUCCESS;
}