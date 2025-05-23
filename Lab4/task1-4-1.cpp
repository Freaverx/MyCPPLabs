#include <iostream>
#include <cstring>
#include "task1-4.h"  // Подключает заголовочный файл с пользовательскими функциями для работы со строками

using namespace std;

// Функция для вывода информации о строках и результатах различных операций
void printInfo(char* str1, char* str2) {
    cout << endl << endl << "str1 = " << str1 << ", str2 = " << str2 << endl;
    
    // Сравнение трех способов вычисления длины строки
    cout << "длина str1 = " << dlina1(str1) << ", str2 = " << dlina1(str2) << endl;
    cout << "длина str1 = " << dlina2(str1) << ", str2 = " << dlina2(str2) << endl;
    cout << "длина str1 = " << dlina3(str1) << ", str2 = " << dlina3(str2) << endl;

    // Копирование строк и вывод результата
    copystr(str1, str2);
    cout << "результат копирования: str1 = " << str1 << ", str2 = " << str2 << endl;

    // Сравнение строк стандартной и пользовательской функцией
    int scmp = strcmp(str1, str2);
    int cmp = sravn(str1, str2);
    cout << "результат сравнения: strcmp = " << scmp << ", cmp = " << cmp << endl;

    // Конкатенация строк стандартной и пользовательской функцией
    char* scon = strcat(str1, str2);
    cout << "результат сцепления: scon = " << scon << endl;
    char* con = concat(str1, str2);
    cout << "результат сцепления: con = " << con << endl;
}

// Функция для демонстрации работы с массивом строк
void withArray() {
    char str1[] = "abc";
    char str2[] = "defghi";
    char str3[] = "defghi";
    char* strs1[] = {str1, str2, str3};  // Массив указателей на строки

    // Перебор пар строк и вывод информации о них
    for (int i = 0; i < 2; i++) {
        printInfo(strs1[i], strs1[i+1]);
    }
}

int main() {
    // Выделение памяти под строки с использованием calloc (инициализирует память нулями)
    char *str1, *str2;
    str1 = (char*) calloc(6, 8);  // Выделяет память под 6 элементов по 8 байт каждый
    // Ручная инициализация строки str1
    str1[0] = 'q', str1[1] = 'w', str1[2] = 'e', str1[3] = 'r', str1[4] = 't', str1[5] = '\0';
    
    str2 = (char*) calloc(6, 8);
    // Ручная инициализация строки str2
    str2[0] = '1', str2[1] = '2', str2[2] = '3', str2[3] = '4', str2[4] = '5', str2[5] = '\0';

    // Вывод информации о строках
    printInfo(str1, str2);

    // Освобождение выделенной памяти
    free(str1);
    free(str2);

    // Демонстрация работы с массивом строк
    withArray();
    return 0;
}