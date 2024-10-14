/*
    Лабораторная работа №3
    Вариант 26
    Студент Останин С.А; группа ПИ-Э
    Задача:
    Напечатать треугольник Паскаля, состоящий из n строк.
*/
#include <iostream> 
#include <locale.h>
using namespace std; 

int main() {
    setlocale(LC_ALL, "Russian"); 
    int n; 
    cout << "n = "; 
    cin >> n; 
    for (int i = 0; i < n; i++) { 
        int number = 1; 
        for (int j = 0; j < n - i - 1; j++) { 
            cout << " "; 
        }
        for (int j = 0; j <= i; j++) { 
            cout << number << " "; 
            number = number * (i - j) / (j + 1); 
        }
        cout << endl; 
    }
    return 0; 
}