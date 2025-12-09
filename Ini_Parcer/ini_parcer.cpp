// Курсовой проект «Парсер INI-файлов»
#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <algorithm>
#include <sstream>

// Функция на удаление пробелов в начале и конце строки
std::string erase_ispace(std::string& str)
{
	size_t pos_begin = str.find_first_not_of(' ');
	size_t pos_end = str.find_last_not_of(" \n");
	str = str.substr(pos_begin);
	str = str.substr(0, pos_end + 1);
	return str;
}

// Функция на проверку строки из пробелов
bool str_is_whitespace(const std::string& str)
{
	for (char c : str)
	{
		if (!std::isspace(c))
		{
			return false;
		}
	}
	return true;
}

// Класс ini_parcer для работы с ini файлами
class ini_parcer
{
	private:
		std::map<std::string, std::map<std::string, std::string>> config;
		std::string name_file{};
	
	public:
		
		ini_parcer(std::string n_file) : name_file{ n_file }
		{
			// Открываем файл для чтения и заносим данные в словарь
			std::ifstream file;
			file.open(name_file);

			std::string line{};
			std::string current_section{};
			
			if (file.is_open()) {
				while (std::getline(file, line))
				{
					if (line.empty() || line[0] == ';' || line[0]==' ') continue;
					if (str_is_whitespace(line)) continue;

					if (line[0] == '[' && line.back() == ']')
					{
						current_section = line.substr(1, line.length() - 2);
						line = erase_ispace(line);
						config[current_section];
					}
					else
					{
						line = erase_ispace(line);
						size_t position = line.find('=');
						std::string key = line.substr(0, position);
						std::string value = line.substr(position+1);

						size_t pos = line.find(';');
						value = value.substr(0, pos);

						config[current_section][key] = value;
					}
				}
			}
			std::cout << "Загружен ini-файл " << name_file << std::endl;
			file.close();
		}

		// Шаблонный метод для получения данных из ini файла
		template <typename T>
		T get_value(std::string section, std::string par)
		{
			// Проверяем есть ли данные в словаре
			for (const auto& section_pair: config)
			{
				if (section_pair.first == section)
				{
					for (const auto& key_value_pair : section_pair.second)
					{
						if (key_value_pair.first == par)
						{
							std::stringstream ss(key_value_pair.second);
							T value;
							ss >> value;
							if (ss.fail()) throw std::runtime_error("В файле нет значения для переменной данного типа !!!");
							return value;
						}
					}
				}
			}
			throw std::runtime_error("В файле нет значения для этой переменной!!!");
			T value_empty{};
			return  value_empty;
		}
};

int main()
{
	setlocale(LC_ALL,"Russian");
	ini_parcer parser("config_ini.txt");
	try
	{
		std::string section{}, par{};
		
		section = "Section1";
		par = "var1";
		std::cout << "Значение параметра " << par << " в разделе " << section ;
		auto value_1 = parser.get_value<double>(section, par);
		std::cout << " типа " << typeid(value_1).name() <<" равно "<< value_1 << std::endl;

		section = "Section1";
		par = "var1";
		std::cout << "Значение параметра " << par << " в разделе " << section ;
		auto value_2 = parser.get_value<std::string>(section, par);
		std::cout << " типа " << typeid(value_2).name() << " равно "<< value_2 << std::endl;

		section = "Section1";
		par = "var2";
		std::cout << "Значение параметра " << par << " в разделе " << section ;
		auto value_3 = parser.get_value<int>(section, par);
		std::cout << " типа " << typeid(value_3).name() << " равно "<< value_3 << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << " !!! Error: " << e.what() << std::endl;
	}
	return EXIT_SUCCESS;
}