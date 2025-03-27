#include <iostream> // Подключаем библиотеку для ввода-вывода

using namespace std; // Используем стандартное пространство имен для удобства

int main() {
    // Инициализация переменных a и b
    int a = 2, b = 5; 

    // Объявление функций для обмена значениями
    void obmen1(int, int); // Функция для обмена по значению
    void obmen2(int *, int *); // Функция для обмена по указателям
    void obmen3(int &, int &); // Функция для обмена по ссылкам

    // Вывод значений переменных до обмена
    cout << "     до обмена: a = " << a << " b = " << b << endl;

    // Вызов функции об обмене по значению (не изменит a и b)
    obmen1(a, b);
    cout << "после обмена 1: a = " << a << " b = " << b << endl; // Значения a и b остаются прежними

    // Вызов функции об обмене по указателям (изменит a и b)
    obmen2(&a, &b);
    cout << "после обмена 2: a = " << a << " b = " << b << endl; // Значения a и b обменяются

    // Вызов функции об обмене по ссылкам (изменит a и b)
    obmen3(a, b);
    cout << "после обмена 3: a = " << a << " b = " << b << endl; // Значения a и b снова обменяются

    return 0; // Завершение программы
}

// Функция для обмена значениями по значению
// Аргументы a и b копируются, поэтому изменения не влияют на оригинальные значения
void obmen1(int a, int b) {
    // Здесь ничего не происходит, так как изменения не сохраняются
}

// Функция для обмена значениями по указателям
// Аргументы a и b - указатели на целые числа
void obmen2(int *a, int *b) {
    // Сохраняем значение по адресу a во временной переменной
    int tmp = *a; 
    // Меняем значение по адресу a на значение по адресу b
    *a = *b; 
    // Меняем значение по адресу b на временное значение
    *b = tmp; 
}

// Функция для обмена значениями по ссылкам
// Аргументы a и b - ссылки на целые числа
void obmen3(int &a, int &b) {
    // Сохраняем значение a во временной переменной
    int tmp = a; 
    // Меняем значение a на значение b
    a = b; 
    // Меняем значение b на временное значение
    b = tmp; 
}
