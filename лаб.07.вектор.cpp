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
#include <vector>
#include <iomanip>
#include <locale.h>

using namespace std;

// Функция для создания матрицы змейкой
void matrixSnake(vector<vector<int>>& matrix, int m, int n) {
    int num = 1;
    for (int i = 0; i < m; ++i) {
        if (i % 2 == 0) { // Четные строки
            for (int j = 0; j < n; ++j) {
                matrix[i][j] = num++;
            }
        } else { // Нечетные строки
            for (int j = n - 1; j >= 0; --j) {
                matrix[i][j] = num++;
            }
        }

    }
}
// Функция для выполнения циклического сдвига в матрице 
void shiftMatrix(vector<vector<int>>& matrix , int m, int n) {
    
    int a = matrix[0][0];
    int b = 1;
    for (int i = 0; i < m; ++i) {
        if (i % 2 == 0) { // Четные строки
            for (int j = 0; j < n; ++j) {
                if (i == 0 && j == 0) continue; // Пропускаем первую ячейку
                b = matrix[i][j];
                matrix[i][j] = a; 
                a = b;
            }
        } else { // Нечетные строки
            for (int j = n - 1; j >= 0; --j) {
                if (i == m - 1 && j == n - 1) continue; // Пропускаем последнюю ячейку
                b = matrix[i][j];
                matrix[i][j] = a; 
                a = b; 
            }
        }
    }
    matrix[0][0] = a;
}


// Функция для вывода матрицы
void printMatrix(vector<vector<int>>& matrix, int m, int n) {
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
    
    vector<vector<int>> matrix(m, vector<int>(n)); 

    matrixSnake(matrix, m, n);
    cout << "Матрица:" << endl;
    printMatrix(matrix, m, n);
    
    shiftMatrix(matrix, m, n);
    cout << "Матрица после циклического сдвига:" << endl;
    printMatrix(matrix, m, n);
    
    return 0;
}