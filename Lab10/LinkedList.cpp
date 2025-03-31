#include "LinkedList.h"  // Подключение пользовательской реализации связного списка

using namespace std;

// Добавление автобуса в парк
void Park::addBus(Bus bus) {  // Принимает объект Bus по значению (может быть неэффективно для больших объектов)
    inPark->add(bus.number, bus);  // Добавляет автобус в список inPark, используя номер как ключ
}

// Перемещение автобуса на маршрут
void Park::goOnRoute(Bus bus) {
    inPark->remove(bus.number);  // Удаление из парка
    onRoute->add(bus.number, bus);  // Добавление на маршрут
    // Проблема: нет проверки существования автобуса в парке перед удалением
}

// Возврат автобуса в парк
void Park::goInPark(Bus bus) {
    onRoute->remove(bus.number);  // Удаление с маршрута
    inPark->add(bus.number, bus);  // Добавление в парк
    // Проблема: нет проверки существования автобуса на маршруте перед удалением
}

// Вывод информации о состоянии парка
void Park::print() {
    cout << "Автобусы в парке: " << endl;
    auto pvp = inPark->pBeg;  // Получение указателя на начало списка парка
    while (pvp != nullptr) {  // Итерация по списку
        cout << "Номер: " << pvp->data.number 
             << ", маршрут: " << pvp->data.route 
             << ", водитель: " << pvp->data.driver << endl;
        pvp = pvp->next;  // Переход к следующему элементу
    }

    cout << "Автобусы на маршруте: " << endl;
    auto pvr = onRoute->pBeg;  // Получение указателя на начало списка маршрута
    while (pvr != nullptr) {  // Итерация по списку
        cout << "Номер: " << pvr->data.number 
             << ", маршрут: " << pvr->data.route 
             << ", водитель: " << pvr->data.driver << endl;
        pvr = pvr->next;  // Переход к следующему элементу
    }
    // Проблема: дублирование кода вывода - можно вынести в отдельный метод
}