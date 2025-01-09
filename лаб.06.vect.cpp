/*
    Лабораторная работа №6
    Вариант 26
    Студент Останин С.А; группа ПИ-Э
    Задача:
    Коэффициенты многочлена 𝑎𝑛𝑥𝑛 + 𝑎𝑛−1𝑥𝑛−1 + ⋯ + 𝑎1𝑥 + 𝑎0 раз
    мещены в массиве 𝑎0, 𝑎1 … 𝑎𝑛−1, 𝑎𝑛. Дано вещественное число 𝑥. 
    Найти значение многочлена для данного 𝑥. Указание: ввод коэффициентов
    осуществлять с клавиатуры, начиная со старшего коэффициента;
    операцию возведения в степень не использовать
*/

#include <iostream>
#include <vector>
#include <locale.h>

using namespace std;

// Функция для ввода коэффициентов многочлена 
void inputCoefficients(vector<double>& coefficients) {
    cout << "Введите коэффициенты многочлена, начиная со старшего (a_n, a_{n-1}, ..., a_0):" << endl;
    for (auto it = coefficients.begin(); it != coefficients.end(); ++it) {
        cout << "a[" << (it - coefficients.begin()) << "]: "; // Печатаем индекс для удобства
        cin >> *it;
    }
}

// Функция для вычисления значения многочлена  
double evaluatePolynomial(const vector<double>& coefficients, double x) {
    double result = *coefficients.begin(); // Начальное значение
    for (auto it = coefficients.begin() + 1; it != coefficients.end(); ++it) {
        result = result * x + *it;
    }
    return result;
}

int main() {
    setlocale(LC_ALL, "Russian");

    int n;
    cout << "Введите степень многочлена (n): " << endl;
    cin >> n;

    // Создаем вектор с n + 1 элементами для коэффициентов 
    vector<double> coefficients(n + 1);

    inputCoefficients(coefficients);

    double x;
    cout << "Введите значение x: " << endl;
    cin >> x;

    double result = evaluatePolynomial(coefficients, x);

    cout << "Значение многочлена для x = " << x << " равно: " << result << endl;

    return 0;
}
