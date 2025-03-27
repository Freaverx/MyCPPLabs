#include <iostream>

// Объявление функции power
int power(int x, int n);

int main()
{
    int i, k;
    int base;

    // Ввод основания степени
    std::cout << "Введите основание степени: ";
    std::cin >> base;

    // Вычисление и вывод степеней
    for(i = 0; i < 10; i++)
    {
        k = power(base, i);
        std::cout << base << " в степени " << i << " = " << k << std::endl;
    }

    return 0;
}

// Определение функции power
int power(int x, int n)
{
    int p = 1;
    for (int i = 0; i < n; i++) 
    {
        p *= x;
    }
    return p;
}