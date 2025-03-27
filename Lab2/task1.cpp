#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <limits>

#define N 5

using namespace std;

//minMax поиск минимума и максимума во всей матрице
tuple<float, float> minMax(float m[][N]) {
    float min = numeric_limits<float>::infinity();
    float max = -numeric_limits<float>::infinity();
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            min = std::min(min, m[i][j]);
            max = std::max(max, m[i][j]);
        }
    return {min, max};
}
//minMaxBottomTriangle минимум и максимум в нижнем треугольнике (включая диагональ)
tuple<float, float> minMaxBottomTriangle(float m[][N]) {
    float min = numeric_limits<float>::infinity();
    float max = -numeric_limits<float>::infinity();
    for (int i = 0; i < N; i++)
        for (int j = 0; j <= i; j++) {  // j <= i – нижний треугольник
            min = std::min(min, m[i][j]);
            max = std::max(max, m[i][j]);
        }
    return {min, max};
}
//minMaxTopTriangle минимум и максимум в верхнем треугольнике (включая диагональ)
tuple<float, float> minMaxTopTriangle(float m[][N]) {
    float min = numeric_limits<float>::infinity();
    float max = -numeric_limits<float>::infinity();
    for (int i = 0; i < N; i++)
        for (int j = 0; j <= i; j++) {  // m[j][i] – верхний треугольник
            min = std::min(min, m[j][i]);
            max = std::max(max, m[j][i]);
        }
    return {min, max};
}
//minMaxMainDiagonal минимум и максимум на главной диагонали
tuple<float, float> minMaxMainDiagonal(float m[][N]) {
    float min = numeric_limits<float>::infinity();
    float max = -numeric_limits<float>::infinity();
    for (int i = 0; i < N; i++) {
        min = std::min(min, m[i][i]);  // Главная диагональ: m[i][i]
        max = std::max(max, m[i][i]);
    }
    return {min, max};
}
//minMaxSecondDiagonal минимум и максимум на побочной диагонали
tuple<float, float> minMaxSecondDiagonal(float m[][N]) {
    float min = numeric_limits<float>::infinity();
    float max = -numeric_limits<float>::infinity();
    for (int i = 0; i < N; i++) {
        int j = N - i - 1;  // Побочная диагональ: m[i][N-i-1]
        min = std::min(min, m[i][j]);
        max = std::max(max, m[i][j]);
    }
    return {min, max};
}
//avg среднее значение всех элементов матрицы
float avg(float m[][N]) {
    float sum = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            sum += m[i][j];
    return sum / (N * N);
}
//sumBottomTriangle умма элементов нижнего треугольника
float sumBottomTriangle(float m[][N]) {
    float sum = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j <= i; j++) {
            sum += m[i][j];
        }
    return sum;
}
//avgBottomTriangle среднее значение нижнего треугольника
float avgBottomTriangle(float m[][N]) {
    int count = (1 + N) * N / 2;  // Формула суммы арифметической прогрессии
    return sumBottomTriangle(m) / count;
}
//sumTopTriangle сумма элементов верхнего треугольника
float sumTopTriangle(float m[][N]) {
    float sum = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j <= i; j++) {  // Возможна ошибка – должно быть j >= i?
            sum += m[j][i];
        }
    return sum;
}
//sumRow сумма элементов строки
float sumRow(float m[][N], int i) {
    float sum = 0;
    for (int j = 0; j < N; j++)
        sum += m[i][j];
    return sum;
}
//sumColumn сумма элементов столбца
float sumColumn(float m[][N], int i) {
    float sum = 0;
    for (int j = 0; j < N; j++)
        sum += m[j][i];
    return sum;
}
//minRow, maxRow, avgRow минимум, максимум и среднее в строке
float minRow(float m[][N], int i) {
    float min_val = numeric_limits<float>::infinity();
    for (int j = 0; j < N; j++)
        min_val = std::min(min_val, m[i][j]);
    return min_val;
}

float maxRow(float m[][N], int i) {
    float max_val = -numeric_limits<float>::infinity();
    for (int j = 0; j < N; j++)
        max_val = std::max(max_val, m[i][j]);
    return max_val;
}

float avgRow(float m[][N], int i) {
    return sumRow(m, i) / N;
}
//minColumn, maxColumn, avgColumn аналогично для столбцов
float minColumn(float m[][N], int i) {
    float min_val = numeric_limits<float>::infinity();
    for (int j = 0; j < N; j++)
        min_val = std::min(min_val, m[j][i]);
    return min_val;
}

float maxColumn(float m[][N], int i) {
    float max_val = -numeric_limits<float>::infinity();
    for (int j = 0; j < N; j++)
        max_val = std::max(max_val, m[j][i]);
    return max_val;
}

float avgColumn(float m[][N], int i) {
    return sumColumn(m, i) / N;
}
//nearAvgValue находим элемент матрицы, наиболее близкий к среднему
float nearAvgValue(float m[][N], float avg_val) {
    float diff = numeric_limits<float>::infinity();
    float nearest_val = m[0][0];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            float diff_local = abs(m[i][j] - avg_val);
            if (diff_local < diff) {
                diff = diff_local;
                nearest_val = m[i][j];
            }
        }
    return nearest_val;
}
//Основная программа. Заполняет матрицу случайными числами (rand()). 
//Выводит матрицу с форматированием (setw, setprecision). 
//Вызывает все функции и выводит результаты.
int main() {
    float m[N][N];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            m[i][j] = rand() / 10.;  // Заполнение случайными числами

    // Вывод матрицы
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << setw(8) << setprecision(5) << m[i][j];
        cout << endl;
    }

    // Вызов всех функций и вывод результатов
    auto min_max = minMax(m);
    cout << "min: " << get<0>(min_max) << endl;
    cout << "max: " << get<1>(min_max) << endl;
    // ... остальные вызовы ...
    return 0;
}
