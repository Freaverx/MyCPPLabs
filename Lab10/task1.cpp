#include <iostream>
#include <conio.h>  // Для getch() (нестандартная, зависит от платформы)
#include "LinkedList.h"  // Пользовательский заголовочный файл

using namespace std;

void buses() {
    // Создание объекта парка автобусов
    auto *park = new Park();  // Динамическое выделение памяти (нужен ли здесь new?)

    // Создание и добавление автобусов в парк (проблемный код!)
    auto bus1 = *new Bus(1, (char *) "Иванов И.И.", 15);  // 1. Утечка памяти
    park->addBus(bus1);                                   // 2. Небезопасное приведение типа
    auto bus2 = *new Bus(2, (char *) "Петров П.П.", 20);  // 3. Лучше использовать std::string
    park->addBus(bus2);
    auto bus3 = *new Bus(3, (char *) "Смирнов С.С.", 33);
    park->addBus(bus3);

    park->print();  // Вывод информации о парке

    cout << endl;
    park->goOnRoute(bus2);  // Отправка автобуса на маршрут
    park->print();          // Вывод измененного состояния

    cout << endl;
    park->goInPark(bus2);  // Возврат автобуса в парк
    park->print();         // Вывод измененного состояния

    getch();  // Ожидание нажатия клавиши (непереносимый способ)
}

int main() {
    buses();  // Вызов функции работы с автобусами
    return 0;
}