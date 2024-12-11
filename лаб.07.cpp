/*
    Лабораторная работа №7
    Вариант 26
    Студент Останин С.А; группа ПИ-Э
    Задача:
    Дана прямоугольная целочисленная матрица размера m строк и n
    столбцов. Последовательность элементов матрицы, расположенных
    по чётным строкам слева направо, по нечётным строкам справа
    налево, (строки рассматриваем последовательно сверху вниз) 
    назовем «змейкой». Сдвинуть циклически элементы змейки на 
    одну позицию к концу.
*/

#include <iostream>
#include <iomanip>
#include <locale.h>

using namespace std;

void newMatrix(int**& matrix, int m, int n)
{
matrix = new int* [m];
for (int i = 0; i < m; i++)
matrix[i] = new int[n];
}
//Функция для создания новой матрицы.
void fullMatrix(int** matrix, int m, int n) {
    int num = 1;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            matrix[i][j] = num++;
        }
    }
}
// Функция для вывода матрицы змейкой
void printSnake(int** matrix, int m, int n) {
    for (int i = 0; i < m; ++i) {
        if (i % 2 == 0) { // Четные строки
            for (int j = 0; j < n; ++j) {
                cout << setw(4) << matrix[i][j];
            }
        } else { // Нечетные строки
            for (int j = n - 1; j >= 0; --j) {
                cout << setw(4) << matrix[i][j];
            }
        }
        cout << endl;
    }
}
// Функция для выполнения циклического сдвига в матрице 
void rotateMatrix(int** matrix, int m, int n) {
    int lastElement = matrix[m - 1][n - 1]; 
    for (int i = m - 1; i >= 0; --i) {
        for (int j = n - 1; j > 0; --j) {
            matrix[i][j] = matrix[i][j - 1]; // Сдвигаем элементы вправо
        }
        if (i > 0) {
            matrix[i][0] = matrix[i - 1][n - 1]; // Сдвигаем элемент сверху
        }
    }
    
    matrix[0][0] = lastElement; // Перемещаем последний элемент в верхний левый угол
}

// Функция для вывода матрицы
void printMatrix(int** matrix, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << setw(4) << matrix[i][j];
        }
        cout << endl; 
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    int m;
    int n;
    cout<< "Введите количество строк"<< endl;
    cin>> m;
    cout<< "Введите количество столбцов"<< endl;
    cin>> n;
    
    int** matrix; 

    newMatrix(matrix, m, n);
    fullMatrix(matrix, m, n);
    cout << "Изначальная матрица:" << endl;
    printMatrix(matrix, m, n);

    cout << "Матрица змейкой:" << endl;
    printSnake(matrix, m, n);
    
    rotateMatrix(matrix, m, n);
    cout << "Матрица после циклического сдвига:" << endl;
    printSnake(matrix, m, n);
    
    return 0;
}