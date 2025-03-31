#include <iostream>
#include <fstream>
#include "../Lab6/MyString.h"  // Подключение пользовательского класса строки

using namespace std;

// Демонстрация работы с пользовательским классом StringM
void stringM() {
    StringM str("asdasf");  // Создание строки с инициализацией
    cout << str << endl;    // Вывод строки

    cout << "Введите строку: ";
    cin >> str;             // Ввод строки с клавиатуры
    cout << str << endl;    // Вывод введенной строки
}

// Функция преобразования файла в верхний регистр
void open1() {
    char fname[15], c;  // Буфер для имени файла и символьный буфер
    
    // Ввод и открытие входного файла
    cout << "Введите имя входного файла";
    cin >> fname;
    ifstream ifs(fname);
    if (!ifs)
        cout << "Не открыт входной файл " << fname;

    // Ввод и открытие выходного файла
    cout << "Введите имя выходного файла";
    cin >> fname;
    ofstream ofs(fname);
    if (!ofs)
        cout << "Не открыт выходной файл " << fname;

    // Построчная обработка файлов
    while (ifs && ofs) {
        ifs.get(c);         // Чтение символа
        c = toupper(c);     // Преобразование в верхний регистр
        ofs.put(c);        // Запись символа
    }
    cout << '.';
    cout << endl << "Выходной файл является копией входного файла в верхнем регистре" << endl;
}

// Функция проверки существования файла
void open2() {
    char name[12];      // Буфер для имени файла
    fstream fin;
    
    cout << "Введите имя файла: ";
    cin >> name;

    // Попытка открытия файла в режиме чтения
    fin.open(name, ios::in);
    if (fin) {
        cout << "Файл открыт " << name << endl;
        fin.close();
    } else {
        cout << "Не открыт выходной файл " << name << endl;
    }
}

// Демонстрация различных режимов работы с файлами
void open3() {
    char *fname = "../Lab8/fname.txt";  // Фиксированное имя файла
    
    // Создание нового файла (если не существует)
    fstream ofs(fname, ios::out);
    if (!ofs) {
        cout << "Файл " << fname << " уже существует" << endl;
        return;
    }
    
    // Запись в файл
    ofs << "Эта строка записывается в новый файл. ";
    ofs.close();
    
    // Дописывание в конец файла
    fstream fs;
    fs.open(fname, ios::out | ios::app);  // Режим добавления
    fs << " Сейчас к ней сделано добавление";
    fs.close();
    
    // Чтение из файла
    fstream ifs;
    ifs.open(fname, ios::in);
    if (ifs) {
        cout << "В старом файле содержится ..." << endl;
        char line[80];
        ifs.getline(line, sizeof(line));  // Чтение строки
        cout << line;                     // Вывод строки
    } else {
        cout << "Ошибка при повторном открытии fname" << endl;
    }
}

int main() {
//    stringM();  // Демонстрация работы со строкой
//    open1();    // Преобразование регистра файла
//    open2();    // Проверка существования файла
    open3();      // Демонстрация различных режимов работы с файлом

    return 0;
}