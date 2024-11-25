/*
    Лабораторная работа №5
    Вариант 26
    Студент Останин С.А; группа ПИ-Э
    Задача:
    Даны четыре вещественных положительных числа 𝑎, 𝑏, 𝑐, 𝑑. Найти 
    среди них все тройки Пифагора.
*/

#include <iostream>
#include <cmath>
#include <locale.h>

using namespace std;

// Функция для проверки, являются ли три числа тройкой Пифагора
bool isTriple(double x, double y, double z) {
    return (abs(x * x + y * y - z * z) == 0);  
}

// Функция для поиска и вывода троек Пифагора 
void findTriples(double a, double b, double c, double d) {
    bool found = false;

    // Проверяем все возможные комбинации тройки
    if (isTriple(a, b, c)) {
        cout << "Тройка Пифагора: (" << a << ", " << b << ", " << c << ")"<<endl;
        found = true;
    }
    if (isTriple(a, b, d)) {
        cout << "Тройка Пифагора: (" << a << ", " << b << ", " << d << ")"<<endl;
        found = true;
    }
    if (isTriple(a, c, d)) {
        cout << "Тройка Пифагора: (" << a << ", " << c << ", " << d << ")"<<endl;
        found = true;
    }
    if (isTriple(b, c, d)) {
        cout << "Тройка Пифагора: (" << b << ", " << c << ", " << d << ")"<<endl;
        found = true;
    }

    if (!found) {
        cout << "Тройки Пифагора не найдены."<<endl;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    
    double a, b, c, d;

    cout << "Введите четыре положительных числа (a, b, c, d): "<<endl;
    cin >> a >> b >> c >> d;

    // Проверка на положительность
    if (a <= 0 || b <= 0 || c <= 0 || d <= 0) {
        cout << "Все числа должны быть положительными."<<endl;
        return 1;
    }

    // Поиск троек Пифагора
    findTriples(a, b, c, d);

    return 0;
}
