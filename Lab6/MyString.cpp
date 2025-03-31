#include <iostream>
#include "MyString.h"    // Заголовочный файл класса MyString
#include "strFoo.h"      // Заголовочный файл с функциями для работы со строками
#include "strFoo.cpp"    // Подключение реализации функций (обычно так не делают)

// Реализация методов класса MyString

// Конструктор по умолчанию - создает пустую строку
MyString::MyString() {}

// Конструктор из C-строки (const char*)
MyString::MyString(const char* s) {
    strCopy(this->str, s);  // Копирование переданной C-строки в поле str объекта
}

// Конструктор копирования (создает копию существующего объекта MyString)
MyString::MyString(const MyString& s) {
    strCopy(this->str, s.str);  // Копирование строки из объекта s в текущий объект
}

// Перегрузка оператора присваивания
MyString& MyString::operator=(const MyString& s) {
    strCopy(this->str, s.str);  // Копирование строки
    return *this;               // Возврат ссылки на текущий объект (для цепочки присваиваний)
}

// Перегрузка оператора сложения (конкатенация строк)
MyString& MyString::operator+(const MyString& s) {
    strConcat(this->str, s.str);  // Добавление строки s к текущей строке
    return *this;                 // Возврат измененного объекта
}

// Перегрузка оператора сравнения (==)
int MyString::operator==(const MyString& s) {
    if (strEquals(this->str, s.str) == 0)  // Сравнение строк
        return 1;                         // Равны (возвращает 1 в стиле C)
    else 
        return 0;                         // Не равны
}

// Метод возвращающий длину строки
int MyString::strLen() {
    return strLengthOne(this->str);  // Вызов внешней функции для определения длины
}

// Метод для ввода строки с клавиатуры
void MyString::input() {
    std::cin >> this->str;  // Простое чтение из стандартного ввода
}

// Метод для вывода строки
void MyString::print() {
    std::cout << this->str << std::endl;  // Простой вывод с переводом строки
}