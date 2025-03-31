#ifndef CPPLABS_1_9_H  // Защита от повторного включения заголовочного файла
#define CPPLABS_1_9_H

#include <cstdio>
#include <cstring>  // Для работы со строками в стиле C

using namespace std;

// Шаблонная функция сортировки пузырьком
template<class T>
void sort(T array[], size_t size) {
    for (int i = 0; i < size - 1; i++)
        for (int j = size - 1; i < j; j--)
            if (array[i] > array[j]) {  // Сравнение элементов
                T tmp = array[j];       // Обмен элементов
                array[j] = array[j - 1];
                array[j - 1] = tmp;
            }
}

// Шаблонная функция для сравнения двух значений
template<class T>
T getmax(T t1, T t2) {
    return t1 > t2 ? t1 : t2;  // Возвращает большее из двух значений
}

// Специализация для C-строк (указателей на char)
char *getmax(char *s1, char *s2) {
    return strcmp(s1, s2) > 0 ? s1 : s2;  // Сравнение строк через strcmp
}

// Шаблонная функция для поиска максимума в массиве
template<class T>
T getmax(T t[], size_t size) {
    T retval = t[0];  // Инициализация первым элементом
    for (int i = 0; i < size; i++)
        if (t[i] > retval)  // Поиск максимального элемента
            retval = t[i];
    return retval;
}

// Шаблонный класс стека
template<class T>
class Tstack {
protected:
    int numItem;  // Количество элементов в стеке
    T *item;      // Динамический массив для хранения элементов
public:
    // Конструктор с параметром по умолчанию
    Tstack(size_t size = 10) {
        numItem = 0;
        item = new T[size];  // Выделение памяти
    }

    // Деструктор
    ~Tstack() {
        delete[] item;  // Освобождение памяти
    }

    void push(T t);  // Добавление элемента
    T pop();         // Извлечение элемента
};

// Реализация метода push (добавление элемента)
template<class T>
void Tstack<T>::push(T t) {
    item[numItem++] = t;  // Добавление и увеличение счетчика
}

// Реализация метода pop (извлечение элемента)
template<class T>
T Tstack<T>::pop() {
    return item[--numItem];  // Уменьшение счетчика и возврат элемента
}

#endif //CPP_LABS_9_1_H