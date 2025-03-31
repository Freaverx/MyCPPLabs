#ifndef CPPLABS_LINKEDLIST_H  // Защита от повторного включения
#define CPPLABS_LINKEDLIST_H

#include <iostream>

using namespace std;

// Узел списка (шаблонный класс)
template<class T>
struct Node {
    int key;        // Ключ для поиска
    T data;         // Полезные данные
    Node *next = nullptr;  // Указатель на следующий узел

    // Конструктор узла
    Node(int key, T data, Node *next) : key(key), data(data), next(next) {}
};

// Шаблонный класс связного списка
template<class T>
struct LinkedList {
    Node<T> *pBeg = nullptr;  // Указатель на начало списка
    Node<T> *pEnd = nullptr;  // Указатель на конец списка

public:
    // Основные методы:
    void add(int key, T data);    // Добавление в конец
    void first(int key, T data);  // Добавление первого элемента
    Node<T> *find(int key);       // Поиск по ключу
    Node<T> *findPrev(int key);   // Поиск предыдущего узла
    Node<T> *remove(int key);    // Удаление узла
};

// Реализация методов:

// Добавление элемента в конец списка
template<class T>
void LinkedList<T>::add(int key, T data) {
    if (pBeg == nullptr) {  // Если список пуст
        first(key, data);    // Создаем первый элемент
        return;
    }
    // Создаем новый узел
    auto *pv = new Node<T>(key, data, nullptr);
    pEnd->next = pv;  // Привязываем к последнему элементу
    pEnd = pv;        // Обновляем указатель на конец
}

// Создание первого элемента списка
template<class T>
void LinkedList<T>::first(int key, T data) {
    pBeg = new Node<T>(key, data, nullptr);
    pEnd = pBeg;  // Для первого элемента начало и конец совпадают
}

// Поиск узла по ключу
template<class T>
Node<T> *LinkedList<T>::find(int key) {
    Node<T> *cur = pBeg;
    while (cur->key != key) {  // Проблема: нет проверки на nullptr!
        cur = cur->next;
    }
    return cur;  // Опасность: может вернуть nullptr или мусорный указатель
}

// Поиск предыдущего узла
template<class T>
Node<T> *LinkedList<T>::findPrev(int key) {
    Node<T> *prev = nullptr;
    Node<T> *cur = pBeg;
    while (cur->key != key) {  // Та же проблема с проверкой nullptr
        prev = cur;
        cur = cur->next;
    }
    return cur->key == key ? prev : nullptr;  // Единственная проверка
}

// Удаление узла по ключу
template<class T>
Node<T> *LinkedList<T>::remove(int key) {
    Node<T> *prev = findPrev(key);  // Находим предыдущий
    Node<T> *cur = find(key);       // Находим текущий
    
    if (cur == pBeg) {     // Особый случай: удаление первого элемента
        pBeg = nullptr;    // Проблема: некорректно обрабатывается!
        return cur;
    }
    prev->next = cur->next;  // Стандартный случай: перелинковка
    return cur;              // Возвращаем удаленный узел (но не удаляем из памяти!)
}

// Структура автобуса
struct Bus {
    int number;          // Номер автобуса
    const char *driver;  // Имя водителя (лучше использовать string)
    int route;           // Номер маршрута

    // Конструктор
    Bus(int _number, const char *_driver, int _route) {
        number = _number;
        driver = _driver;  // Проблема: сохраняется указатель на переданную строку
        route = _route;
    }
};

// Структура автобусного парка
struct Park {
    LinkedList<Bus> *inPark = new LinkedList<Bus>;   // Автобусы в парке
    LinkedList<Bus> *onRoute = new LinkedList<Bus>;  // Автобусы на маршруте

    // Методы управления:
    void addBus(Bus bus);      // Добавление автобуса
    void goOnRoute(Bus bus);   // Отправка на маршрут
    void goInPark(Bus bus);    // Возврат в парк
    void print();              // Вывод информации
};

#endif //CPP_LABS_LINKEDLIST_H