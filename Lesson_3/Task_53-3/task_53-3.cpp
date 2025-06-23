// Занятие 3. Шаблоны и функторы. Задание 3. Счетчик чисел.
#include <iostream>
#include <vector>

template <class T>
class functor_count
{
	private:
		int m_sum{};
		int m_counter{};
	
	public:
		functor_count()
		{

		}

		// Функтор состояния
		void operator()(std::vector<T> a)
		{
			for (int i : a)
			{
				m_sum += i;
				if (i % 3 == 0)
				{
					++m_counter;
				}
			}
		}

		int get_sum()
		{
			return m_sum;
		}

		int get_count()
		{
			return m_counter;
		}
};

int main()
{
	setlocale(LC_ALL,"Russian");
	std::vector<int> a{4, 1, 3, 6, 25, 54};
	functor_count<int> functor;
	functor(a);
	std::cout << "Сумма элементов массива равна " <<functor.get_sum()<< std::endl;
	std::cout << "Количество чисел, делящихся на 3 равно " << functor.get_count() << std::endl;

	return EXIT_SUCCESS;
}