#include <iostream>
#include <vector>
#include <algorithm>

class tridiagonal_matrix
{
public:
    std::vector<double> m_down;
    std::vector<double> m_upper;
    std::vector<double> m_middle;
    
    tridiagonal_matrix(
        const std::vector<double>& down,
        const std::vector<double>& upper,
        const std::vector<double>& middle) :
        m_down{ down }, m_upper{ upper }, m_middle{ middle }
    {};
    ~tridiagonal_matrix() { std::cout << "destructor called\n"; }

    // Функция клонирования объекта класса
    std::unique_ptr<tridiagonal_matrix> clone()
    {
        return std::make_unique<tridiagonal_matrix>(this->m_down,this->m_upper,this->m_middle);
    }
    // clone()
};

void print(double a)
{
    std::cout << a << " ";
}

int main()
{
    auto down = std::vector<double>{ -4.0, 5.0 };
    auto upper = std::vector<double>{ 14.0, 8.0 };
    auto middle = std::vector<double>{ 3.0, 1.0, 7.0 };
    auto matrix = std::make_unique<tridiagonal_matrix>(
        down,
        upper,
        middle
    );

    auto matrix_clone = matrix->clone();

    // Проверка. Вывод данных клонированного образа
    std::cout << "Data of clone tridiagonal_matrix:" << std::endl;
    std::for_each(matrix_clone->m_down.begin(), matrix_clone->m_down.end(), print);
    std::cout << std::endl;
    std::for_each(matrix_clone->m_upper.begin(), matrix_clone->m_upper.end(), print);
    std::cout << std::endl;
    std::for_each(matrix_clone->m_middle.begin(), matrix_clone->m_middle.end(), print);
    std::cout << std::endl;

};

