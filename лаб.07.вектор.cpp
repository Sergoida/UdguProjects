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
#include <clocale>
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

// Функция для создания матрицы заданного размера
void newMatrix(vector<vector<int>>& matrix, int m, int n) {
    matrix.resize(m, vector<int>(n));
}

// Функция для создания матрицы змейкой
void matrixSnake(vector<vector<int>>& matrix) {
    int num = 1;
    for (size_t i = 0; i < matrix.size(); ++i) {
        if (i % 2 == 0) { // Четные строки
            for (size_t j = 0; j < matrix[i].size(); ++j) {
                matrix[i][j] = num++;
            }
        } else { // Нечетные строки
            for (size_t j = matrix[i].size(); j > 0; --j) {
                matrix[i][j - 1] = num++;
            }
        }
    }
}

// Функция для выполнения циклического сдвига в матрице
void shiftMatrix(vector<vector<int>>& matrix) {
    int a = matrix[0][0];
    int b = 1;
    for (size_t i = 0; i < matrix.size(); ++i) {
        if (i % 2 == 0) { // Четные строки
            for (size_t j = 0; j < matrix[i].size(); ++j) {
                if (i == 0 && j == 0) continue; // Пропускаем первую ячейку
                b = matrix[i][j];
                matrix[i][j] = a; 
                a = b;
            }
        } else { // Нечетные строки
            for (size_t j = matrix[i].size(); j > 0; --j) {
                if (i == matrix.size() - 1 && j == matrix[i].size()) continue; // Пропускаем последнюю ячейку
                b = matrix[i][j - 1];
                matrix[i][j - 1] = a; 
                a = b; 
            }
        }
    }
    matrix[0][0] = a;
}

// Функция для вывода матрицы
void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (const auto& element : row) {
            cout << setw(4) << element;
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


    newMatrix(matrix, m, n);
    matrixSnake(matrix);
    cout << "Матрица:" << endl;
    printMatrix(matrix);
    
    shiftMatrix(matrix);
    cout << "Матрица после циклического сдвига:" << endl;
    printMatrix(matrix);
    
    return 0;
}