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

#include <locale.h>
#include <iostream>
#include <cstdlib> 
#include <vector>  

using namespace std;

// Функция для ввода коэффициентов многочлена
void inputCoefficients(vector<double>& coefficients, int n) {
    cout << "Введите коэффициенты многочлена, начиная со старшего (a_n, a_{n-1}, ..., a_0):"<< endl;
    for (int i = 0; i <= n; i++) {
        cout << "a[" << i << "]: ";
        cin >> coefficients[i];
    }
}

// Функция для вычисления значения многочлена 
double evaluatePolynomial(vector<double>& coefficients, int n, double x) {
    double result = coefficients[0]; 
    for (int i = 1; i <= n; i++) {
        result = result * x + coefficients[i];
    }
    return result;
}

int main() {
    setlocale(LC_ALL, "Russian");
    
    int n; 
    cout << "Введите степень многочлена (n): "<<endl;
    cin >> n;

    vector<double> coefficients(n + 1);
    
    inputCoefficients(coefficients, n);

    double x;
    cout << "Введите значение x: "<<endl;
    cin >> x;

    double result = evaluatePolynomial(coefficients, n, x);

    cout << "Значение многочлена для x = " << x << " равно: " << result << endl;

}
    
    