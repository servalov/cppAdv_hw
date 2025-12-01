// Move семантика. Задача 2. Большие числа
#include <iostream>
#include <string>

class big_integer
{
	private:
		std::string num_str{};

	public:
		
		// 1. Конструктор
		big_integer(std::string a) : num_str{ a }
		{
		
		}
		
		// 2. Деструктор
		~big_integer()
		{
		
		}

		// 3. Конструктор копирования и оператор присваивания
		big_integer(std::string& a_other) = delete;
		big_integer& operator=(const std::string& a_other) = delete;

		// 4. Конструктор перемещения и оператор перемещения
		big_integer(big_integer&& a_other) noexcept
		{
			num_str = std::move(a_other.num_str);
		}
		big_integer& operator=(big_integer&& a_other) noexcept
		{
			if (this != &a_other)
			{
				num_str = std::move(a_other.num_str);
			}
			return *this;
		}

		// 5. Методы класса
		std::string get_num_str()
		{
			return num_str;
		}

		// 6. Операторы сложения двух чисел и умножения на число
		big_integer operator+(big_integer& other)
		{
			big_integer result{""};

			int num1 = static_cast<int>(num_str.length() - 1);
			int num2 = static_cast<int>(other.num_str.length() - 1);

			int max_length=std::max(num1,num2);
			
			int unit = 0;
			for (int i{}; i <= max_length; ++i)
			{
				int a = (i <= num1) ? num_str[num1-i] - '0' : 0;
				int b = (i <= num2) ? other.num_str[num2-i] - '0' : 0;

				int c = a + b + unit;

				unit = c / 10;
				result.num_str += std::to_string(c % 10);
			}

			if (unit > 0)
			{
				result.num_str += std::to_string(unit);
			}
			
			std::reverse(result.num_str.begin(), result.num_str.end());
			return result;
		}

		big_integer operator*(big_integer& other)
		{
			big_integer result{"0"};
			big_integer new_number{""};

			int num1 = static_cast<int>(num_str.length() - 1);
			int num2 = static_cast<int>(other.num_str.length() - 1);
			
			std::string c_str, str{};
			for (int i = num2; i >= 0; --i)
			{			
				str += (i == num2) ? "" : "0";
				c_str = str;
				int a = other.num_str[i] - '0';
				int unit = 0;

				for (int j = num1; j >= 0; --j)
				{
					int b = num_str[j] - '0';
					int c = a * b + unit;
					
					unit = c / 10;
					c_str += std::to_string(c % 10);
				}

				if (unit > 0)
				{
					c_str += std::to_string(unit);
				}

				std::reverse(c_str.begin(), c_str.end());

				new_number.num_str=c_str;
				result.num_str = (result + new_number).num_str;
			}
			return result;
		}

		big_integer operator*(int num)
		{
			big_integer result{ "0" };
			big_integer new_number{ "" };
			if (num == 0)
			{
				return result;
			}

			int num1 = static_cast<int>(num_str.length() - 1);
			int num2 = static_cast<int>(std::floor(std::log10(std::abs(num)))) + 1;

			std::string c_str, str{};
			int _num = num;
			for (int i = num2; i >= 0; --i)
			{
				str += (i == num2) ? "" : "0";
				c_str = str;
				int a = _num % 10;
				int unit = 0;
				
				for (int j = num1; j >= 0; --j)
				{
					int b = num_str[j] - '0';
					int c = a * b + unit;

					unit = c / 10;
					c_str += std::to_string(c % 10);
				}

				if (unit > 0)
				{
					c_str += std::to_string(unit);
				}

				std::reverse(c_str.begin(), c_str.end());

				new_number.num_str = c_str;
				result.num_str = (result + new_number).num_str;

				_num /= 10;
			}
			return result;
		}

		friend std::ostream& operator<<(std::ostream& ostream, const big_integer& num)
		{
			return (ostream<<num.num_str);
		}
};

int main()
{
	setlocale(LC_ALL,"Russian");
	auto number1 = big_integer("854575");
	auto number2 = big_integer("28524");

	std::cout <<"Число 1: "<<number1.get_num_str() << std::endl;
	std::cout <<"Число 2: "<< number2.get_num_str() << std::endl;

	auto result_sum = number1 + number2;
	std::cout << "Сумма чисел 1 и 2 равна " << result_sum.get_num_str() << std::endl;

	auto result_multiply = number1 * number2;
	std::cout << "Произведение чисел 1 и 2 равно " << result_multiply.get_num_str() << std::endl;

	auto result_multiply_2 = number1 * 12;
	std::cout << "Произведение "<< number1.get_num_str()<<" на 12"<<" равно " << result_multiply_2 << std::endl;

	int num{ 125 };
	auto result_multiply_3 = number1 * num;
	std::cout << "Произведение " << number1.get_num_str() << " на " <<num<< " равно " << result_multiply_3 << std::endl;

	return EXIT_SUCCESS;
}