#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Прототипы функций (объявлены внутри main, что необычно для C++)
void printText(ifstream&, string);
void countSymbols(ifstream&, string);
void findSubStr(ifstream&, string, string);

int main()
{
    setlocale(LC_ALL, "rus"); // Установка русской локали для корректного вывода
    char ch[50]; // Неиспользуемый массив символов (возможно, остаток от предыдущих версий кода)
    string fileName = "myFile.txt"; // Имя файла для работы
    
    ifstream in; // Создание объекта для чтения файла
    
    // Вызов трех функций для работы с файлом:
    printText(in, fileName);    // 1. Печать содержимого файла
    countSymbols(in, fileName); // 2. Подсчет символов в файле
    string subStr = "hell";     // Подстрока для поиска
    findSubStr(in, subStr, fileName); // 3. Поиск подстроки в файле
    
    in.close(); // Закрытие файла (избыточно, так как файл закрывается в каждой функции)
}

// Функция для печати содержимого файла
void printText(ifstream& in, string fileName) {
    in.open(fileName); // Открытие файла
    if (in.is_open())  // Проверка успешного открытия
    {
        string s;
        // Чтение файла построчно до конца
        while (!in.eof()) // Примечание: проверка eof() после чтения была бы надежнее
        {
            getline(in, s); // Чтение строки
            cout << s << endl; // Вывод строки
        }
        in.close(); // Закрытие файла
    }
    else cout << "Ошибка чтения файла" << endl; // Сообщение об ошибке
}

// Функция для подсчета символов в файле
void countSymbols(ifstream& in, string fileName) {
    in.open(fileName);
    if (in.is_open())
    {
        char ch;
        int blank = 0, symb = 0; // Счетчики пробельных и обычных символов
        
        // Чтение файла посимвольно
        while (in.get(ch))
        {
            if (isspace(ch)) blank++; // Увеличение счетчика пробелов
            else symb++;              // Увеличение счетчика символов
        }
        
        // Вывод результатов подсчета
        cout << "Количество пустых символов в файле: " << blank << endl;
        cout << "Количество непустых символов в файле: " << symb << endl;
        in.close();
    }
    else cout << "Ошибка чтения файла" << endl;
}

// Функция для поиска подстроки в файле
void findSubStr(ifstream& in, string str, string fileName) {
    in.open(fileName);
    if (in.is_open())
    {
        int countLine = 1, i; // countLine - номер строки, i - позиция в строке
        string s;
        
        // Построчный поиск подстроки
        while (!in.eof())
        {
            getline(in, s);
            // Поиск подстроки в текущей строке
            if ((i = s.find(str)) != string::npos) { // Если подстрока найдена
                cout << "Строка найдена в тексте: " << countLine 
                     << " строка, " << i << " символ." << endl;
                in.close();
                return; // Выход после первого найденного вхождения
            }
            countLine++; // Увеличение счетчика строк
        }
        
        // Если подстрока не найдена
        cout << "Строка не найдена" << endl;
        in.close();
    }
    else cout << "Ошибка чтения файла" << endl;
}