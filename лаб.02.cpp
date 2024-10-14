/*
    Лабораторная работа №2
    Вариант 26
    Студент Останин С.А; группа ПИ-Э
    Задача:
    Даны вещественные a1,b1,c1,a2,b2,c2. Решить систему уравнений { a1*x + b1* y = c1 ; a2*x+ b2*y = c2.
*/


#include <iostream>
#include <iomanip>
#include <math.h>
#include <locale.h>
int main() {
    setlocale(LC_ALL, "Russian");
    
    double a1,b1,c1,a2,b2,c2;
    std::cout<< "Введите коэфициенты a1, b1, c1, a2, b2, c2 из системы уравнения"<<std::endl;
    std::cin>> a1 >> b1 >> c1 >> a2>> b2 >> c2;
    if ((a1*b2-a2*b1)==0){std::cout<< "Не имеет короней"<< std::endl;}
    else{
        double x= (b2*c1-b1*c2)/(a1*b2-a2*b1);
        double y1= (c1-a1*x)/b1;
        double y2= (c2-a2*x)/b2;
        if (y1==y2){
        std::cout << "Корни уравнения: X="<< x << " Y=" << y1 <<std::endl;
        }
        else{std::cout<< "Не имеет короней"<<std::endl;
        }
    }
}