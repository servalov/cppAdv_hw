// Занятие 7. Умные указатели. Задание 3.std::unique_ptr своими руками.
#include <iostream>

template <typename T>
class my_Unique_poiner
{
private:
	T* data{ nullptr };

public:
	// Конструктор
	my_Unique_poiner(T* m_data) :data{ m_data }
	{
		std::cout << "\nВызван конструктор my_Unique_poiner!!!" << std::endl;
	}

	// Деструктор
	~my_Unique_poiner()
	{
		delete data;
		std::cout << "\nВызван деструктор my_Unique_poiner!!!" << std::endl;
	}

	// Перегрузка оператора *
	T& operator*()
	{
		if (!data)
		{
			throw std::runtime_error("Разыменование пустого указателя");
		}
		else
		{
			return *data;
		}
	}

	// Запрещены оператор присваивания и конструктор копирования
	my_Unique_poiner& operator=(const my_Unique_poiner& other) = delete;
	my_Unique_poiner(const my_Unique_poiner& other) = delete;

	// Метод release, который освобождает владение и возвращает сырой указатель
	T* release()
	{
		T* old_data = data;
		data = nullptr;              // Освобождение владения;
		std::cout << "Владение объектом освобождено!!!" << std::endl;
		return old_data;
	}

};

int main()
{
	setlocale(LC_ALL, "Russian");
	my_Unique_poiner<int> my_ptr(new int(15));
	std::cout << "Значение указателя объекта my_ptr равно " << *my_ptr << std::endl;


	my_Unique_poiner<double> my_ptr2(new double(3.14f));
	std::cout << "Значение указателя объекта my_ptr2 равно " << *my_ptr2 << std::endl;
	double* ptr = my_ptr2.release();
	std::cout << "Значение указателя ptr равно " << *ptr << std::endl;

	delete ptr;   // Освобождение памяти для сырого указателя

	return EXIT_SUCCESS;
}