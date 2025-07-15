// Занятие 5. STL. Часть первая. Задание 3. Аналог std::vector
#include <iostream>

template <class T>
class vector
{
	private:
		T* arr;
		int v_size{};
		int v_capacity{};
		int v_end{};
	
	public:
	
		// Конструктор для контейнера
		vector(int size)
		{
			if (size <= 0)
			{
				throw std::exception("Ошибка в размере контейнера");
			}
			
			arr = new T[size];
			v_size = size;
			v_capacity = size;
			v_end = 0;
		}
		
		// Функция доступа к элементу контейнера
		T at(int index)
		{
			if (index > v_end)
			{
				throw std::exception("Ошибка в индексе элемента контейнера");
			}
			return arr[index];
		}

		// Количество элементов в контейнере
		int size()
		{
			return v_size;
		}
		
		// Количество элементов, которое может вместить контейнер до нового выделения памяти.
		int capacity()
		{
			return v_capacity;
		}

		// Добавление элемента в конец контейнера
		void pushback(T value)
		{
			
			if (v_end < v_size) // заполнение элементов контейнера
			{
				arr[v_end] = value;
				++v_end;
			}
			else if (v_size == v_capacity)  // необходимо увеличить размер памяти
			{
				v_capacity *= 2;
				T* arrNew = new T[v_capacity];
				for (int i{}; i < v_size; ++i)
				{
					arrNew[i] = arr[i];
				}
				if (v_capacity>v_size) arrNew[v_size] = value;
				++v_size;
				++v_end;

				delete[] arr;
				arr = arrNew;
			}
			else
			{
				arr[v_size] = value;
				++v_size;
				++v_end;
			}
		}

		// Деструктор для освобождения памяти
		~vector()
		{
			delete[] arr;
		}
};

int main()
{
	setlocale(LC_ALL,"Russian");
	vector<int> v1(2);

	std::cout << "Создание контейнера:" << std::endl;
	std::cout <<"Size vector: "<< v1.size() << " , Capacity vector: " << v1.capacity() << std::endl;

	v1.pushback(1);
	v1.pushback(2);
	v1.pushback(3);
	v1.pushback(4);
	v1.pushback(5);
	
	std::cout << "\nПосле добавления элементов:" << std::endl;
	for (int i{}; i<v1.size();++i)
	{ 
		std::cout <<v1.at(i) << " ";
	}
	std::cout << std::endl;
	std::cout << "Size vector: " << v1.size() <<" , Capacity vector: " << v1.capacity() << std::endl;
	
	return EXIT_SUCCESS;
}