#include <SFML/Graphics.hpp>  // Основная графическая библиотека
#include <cmath>              // Математические функции
#include <cstdlib>            // Для работы с rand()
#include <ctime>              // Для инициализации генератора случайных чисел

// Базовый класс для графической точки
class Point {
public:
    int X, Y;            // Координаты точки
    sf::Color Cvet;      // Цвет точки (название переменной на русском - не лучшая практика)

    // Метод инициализации точки
    void Init(int XN, int YN, sf::Color Color) {
        X = XN;
        Y = YN;
        Cvet = Color;
    }

    // Виртуальные методы для отображения/скрытия точки (реализация в дочерних классах)
    virtual void Show(sf::RenderWindow& window) {}
    virtual void Hide(sf::RenderWindow& window) {}

    // Получение текущих координат точки
    void Locat(int& XL, int& YL) {
        XL = X;
        YL = Y;
    }

    // Метод "полета" точки - случайное перемещение по экрану
    void Fly(int Cost, sf::RenderWindow& window) {
        Show(window);
        srand(static_cast<unsigned>(time(nullptr)));  // Инициализация генератора случайных чисел
                                                      // Проблема: инициализация происходит многократно
        
        do {
            int XX, YY;
            Locat(XX, YY);
            
            // Генерация новых координат X с проверкой границ окна
            do {
                XX = XX + static_cast<int>(round((rand() / static_cast<double>(RAND_MAX) - 0.5) * Cost);
            } while (XX <= 0 || XX >= window.getSize().x);
            
            // Генерация новых координат Y с проверкой границ окна
            do {
                YY = YY + static_cast<int>(round((rand() / static_cast<double>(RAND_MAX) - 0.5) * Cost);
            } while (YY <= 0 || YY >= window.getSize().y);
            
            // Анимация перемещения
            Hide(window);      // Скрыть в старой позиции
            X = XX; Y = YY;   // Обновить координаты
            Show(window);      // Показать в новой позиции
            window.display();  // Обновить отображение
            
            sf::sleep(sf::milliseconds(300));  // Задержка для анимации
            
        } while (!sf::Keyboard::isKeyPressed(sf::Keyboard::Escape));  // Выход по Escape
    }
};

// Класс круга, наследуется от Point
class Cirle : public Point {
public:
    unsigned short Radius;  // Радиус круга
    sf::CircleShape shape;  // SFML-объект круга

    // Конструктор круга
    Cirle(int XN, int YN, unsigned short R, sf::Color Color) : shape(R) {
        Init(XN, YN, Color);
        Radius = R;
        shape.setFillColor(Cvet);  // Установка цвета
        shape.setPosition(static_cast<float>(X), static_cast<float>(Y));  // Позиция
    }

    // Переопределение метода отображения
    void Show(sf::RenderWindow& window) override {
        shape.setFillColor(Cvet);  // Восстановление цвета
        shape.setPosition(static_cast<float>(X), static_cast<float>(Y));
        window.draw(shape);
    }

    // Переопределение метода скрытия (закрашивание черным)
    void Hide(sf::RenderWindow& window) override {
        shape.setFillColor(sf::Color::Black);  // Черный = "стирание"
        window.draw(shape);
    }
};

int main() {
    // Создание окна 800x600 с заголовком
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");

    // Создание красного круга с центром в (150,40) и радиусом 50
    Cirle TestCirle(150, 40, 50, sf::Color::Red);

    // Основной цикл приложения
    while (window.isOpen()) {
        sf::Event event;
        // Обработка событий
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();             // Очистка буфера
        TestCirle.Fly(100, window);  // Запуск "полета" круга
        window.display();           // Отображение буфера
    }

    return 0;
}