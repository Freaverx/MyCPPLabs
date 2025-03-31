#include <iostream>
#include "task1-9.h"  // Подключение пользовательского заголовочного файла

using namespace std;

// Функция демонстрации сортировки массивов
void sort_arr() {
    // Создание и вывод целочисленного массива
    int arr[] = {5, 2, 7, 10, -2, -5};
    for (int i: arr)
        cout << i << ' ';
    cout << endl;

    // Сортировка целочисленного массива (функция sort() должна быть определена в task1-9.h)
    sort(arr, sizeof(arr) / sizeof(int));

    // Вывод отсортированного массива
    for (int i: arr)
        cout << i << ' ';
    cout << endl;

    // Создание и вывод массива чисел с плавающей точкой
    double arr_double[] = {5.2, 2.1, 7.2, -1.9, 7.3};
    for (double i: arr_double)
        cout << i << ' ';
    cout << endl;

    // Сортировка массива double
    sort(arr_double, sizeof(arr_double) / sizeof(double));

    // Вывод отсортированного массива
    for (double i: arr_double)
        cout << i << ' ';
    cout << endl;
}

// Функция поиска максимального значения
void max() {
    int i1 = 3, i2 = 5;
    int arr[] = {3, 9, 5, 8};
    
    // Использование перегруженной функции getmax() для двух чисел
    cout << "max int = " << getmax(i1, i2) << endl;
    
    // Использование перегруженной функции getmax() для массива
    cout << "max int = " << getmax(arr, sizeof(arr) / sizeof(int)) << endl;
}

// Функция сравнения строк
void max_str() {
    char *s1 = "строка1";  // Небезопасно - лучше использовать const char*
    char *s2 = "строка2";  // или std::string
    
    // Использование перегруженной функции getmax() для строк
    cout << "max str = " << getmax(s1, s2) << endl;
}

// Функция демонстрации работы стека
void train_sort() {
    int train[] = {5, 3, 1};
    Tstack<int> stack;  // Создание стека (шаблонный класс из task1-9.h)
    
    // Заполнение стека
    for (int i: train) {
        stack.push(i);
    }

    // Извлечение и вывод элементов стека (порядок LIFO)
    for (int i = 0; i < sizeof(train) / sizeof(int); i++) {
        cout << stack.pop() << ' ';
    }
    cout << endl;
}

int main() {
    sort_arr();    // Демонстрация сортировки
    max();         // Демонстрация поиска максимума
    max_str();     // Демонстрация сравнения строк
    train_sort();  // Демонстрация работы стека

    return 0;
}