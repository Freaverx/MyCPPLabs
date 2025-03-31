#include <SFML/Graphics.hpp>
#include <ctime>
#include <cstdlib>
#include <cmath>

// Класс Point представляет точку в 2D пространстве
class Point {
public:
    int X, Y;

    // Конструктор с параметрами по умолчанию
    Point(int x = 0, int y = 0) : X(x), Y(y) {}

    // Метод для получения координат точки
    void Locat(int& x, int& y) {
        x = X;
        y = Y;
    }
};

// Класс Cirle (круг), наследуется от Point
class Cirle : public Point {
private:
    int Radius;         // Радиус круга
    sf::Color Cvet;     // Цвет круга
    sf::CircleShape shape;  // SFML объект для отрисовки круга

public:
    // Конструктор круга
    Cirle(int x, int y, int radius, sf::Color cvet) : Point(x, y), Radius(radius), Cvet(cvet) {
        // Настройка SFML круга
        shape.setRadius(static_cast<float>(Radius));
        shape.setFillColor(Cvet);
        shape.setOrigin(static_cast<float>(Radius), static_cast<float>(Radius)); // Установка центра круга
        shape.setPosition(static_cast<float>(X), static_cast<float>(Y));
    }

    // Метод для отображения круга в окне
    void Show(sf::RenderWindow& window) {
        window.draw(shape);
    }

    // Метод для скрытия круга (делает его прозрачным)
    void Hide(sf::RenderWindow& window) {
        shape.setFillColor(sf::Color::Transparent);
        window.draw(shape);
        shape.setFillColor(Cvet);  // Восстановление цвета после скрытия
    }

    // Изменение размера круга
    void ChangeSize(int delta) {
        Radius += delta;
        shape.setRadius(static_cast<float>(Radius));
        shape.setOrigin(static_cast<float>(Radius), static_cast<float>(Radius)); // Обновление центра
    }

    // Изменение цвета круга
    void ChangeColor(sf::Color newColor) {
        Cvet = newColor;
        shape.setFillColor(Cvet);
    }

    // Метод для анимации "полета" круга
    void Fly(int Cost, sf::RenderWindow& window) {
        Show(window);
        srand(static_cast<unsigned>(time(nullptr))); // Инициализация генератора случайных чисел
        
        do {
            int XX, YY;
            Locat(XX, YY); // Получаем текущие координаты
            
            // Генерация новых координат X с проверкой на выход за границы окна
            do {
                XX = XX + static_cast<int>(round((rand() / static_cast<double>(RAND_MAX) - 0.5) * Cost));
            } while (XX <= 0 || XX >= window.getSize().x);
            
            // Генерация новых координат Y с проверкой на выход за границы окна
            do {
                YY = YY + static_cast<int>(round((rand() / static_cast<double>(RAND_MAX) - 0.5) * Cost));
            } while (YY <= 0 || YY >= window.getSize().y);
            
            Hide(window); // Скрываем круг в старом положении
            X = XX;
            Y = YY;
            
            // Изменяем размер и цвет случайным образом
            ChangeSize(rand() % 20 - 10); // Изменение размера в диапазоне [-10, 10]
            ChangeColor(sf::Color(rand() % 255, rand() % 255, rand() % 255)); // Случайный цвет
            
            Show(window); // Показываем круг в новом положении
            window.display();
            sf::sleep(sf::milliseconds(300)); // Задержка для анимации
            
        } while (!sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)); // Цикл пока не нажата Escape
    }
};

int main() {
    // Создание окна 800x600 с заголовком "Cirle Program"
    sf::RenderWindow window(sf::VideoMode(800, 600), "Cirle Program");
    
    // Создание круга с начальными параметрами
    Cirle cirle(200, 300, 50, sf::Color::Red);

    // Главный цикл приложения
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close(); // Закрытие окна при нажатии на крестик
        }

        window.clear();
        krug.Fly(10, window); // Запуск анимации полета круга
        window.display();
    }

    return 0;
}