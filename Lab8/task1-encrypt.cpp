#include <string>
#include <cstring>
#include <fstream>

using namespace std;

int main(int argc, char **argv) {
    // Получение параметров командной строки:
    char* inFileName = argv[1];    // Имя входного файла
    char* outFileName = argv[2];    // Имя выходного файла
    char* password = argv[3];       // Пароль для шифрования/дешифрования

    // Проверка количества переданных аргументов
    if (argc < 4) {
        printf("Параметров недостаточно");
    }
    else {
        // Открытие файлов:
        fstream fout(outFileName, ios::app);  // Выходной файл открывается в режиме добавления
        fstream fin(inFileName, ios::in);     // Входной файл открывается в режиме чтения

        char ch;  // Буфер для чтения символов
        int i = 0; // Индекс для перебора символов пароля

        // Чтение файла посимвольно
        while (fin) {
            ch = fin.get();  // Чтение одного символа
            
            // Шифрование/дешифрование с помощью XOR:
            ch = ch ^ password[i];  // Применение операции XOR с символом пароля
            
            fout.put(ch);  // Запись результата в выходной файл
            
            // Циклический перебор символов пароля:
            i = (i + 1) % strlen(password);  // Возврат к началу пароля при достижении конца
        }
    }

    return 0;
}