
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
#include <vector>
#include <tuple>
#include <locale.h>

using namespace std;

// Функция для проверки, является ли тройка Пифагоровой
bool isPythagoreanTriple(double x, double y, double z) {
    return (abs(x * x + y * y - z * z) == 0);  
}

// Функция для поиска всех Пифагоровых троек
vector<tuple<double, double, double>> findPythagoreanTriples(double a, double b, double c, double d) {
    vector<tuple<double, double, double>> triples;

    // Проверка всех возможных троек
    if (isPythagoreanTriple(a, b, c)) {
        triples.emplace_back(make_tuple(a, b, c));
    }
    if (isPythagoreanTriple(a, b, d)) {
        triples.emplace_back(make_tuple(a, b, d));
    }
    if (isPythagoreanTriple(a, c, d)) {
        triples.emplace_back(make_tuple(a, c, d));
    }
    if (isPythagoreanTriple(b, c, d)) {
        triples.emplace_back(make_tuple(b, c, d));
    }

    return triples;
}

// Функция для вывода пифагоровых троек
void printPythagoreanTriples(const vector<tuple<double, double, double>>& triples) {
    if (triples.empty()) {
        cout << "Нет найденных Пифагоровых троек." << endl;
    } else {
        cout << "Найденные Пифагоровы тройки:" << endl;
        for (const auto& triple : triples) {
            cout << "(" << get<0>(triple) << ", " << get<1>(triple) << ", " << get<2>(triple) << ")" << endl;
        }
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    
    double a, b, c, d;

    cout << "Введите четыре положительных вещественных числа (a, b, c, d): ";
    cin >> a >> b >> c >> d;

    auto foundTriples = findPythagoreanTriples(a, b, c, d);
    printPythagoreanTriples(foundTriples);

    return 0;
}
    
