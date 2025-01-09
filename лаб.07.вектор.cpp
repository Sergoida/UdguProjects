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
    for (auto row = matrix.begin(); row != matrix.end(); ++row) {
        if ((row - matrix.begin()) % 2 == 0) { // Четные строки
            for (auto col = row->begin(); col != row->end(); ++col) {
                *col = num++;
            }
        } else { // Нечетные строки
            for (auto col = row->end() - 1; col >= row->begin(); --col) {
                *col = num++;
            }
        }
    }
}

// Функция для выполнения циклического сдвига в матрице
void shiftMatrix(vector<vector<int>>& matrix) {
    int a = 1;
    int b = 1;
    for (auto row = matrix.begin(); row != matrix.end(); ++row) {
        if ((row - matrix.begin()) % 2 == 0) { // Четные строки
            for (auto col = row->begin(); col != row->end(); ++col) {
                if (row == matrix.begin() && col == row->begin()) continue; // Пропускаем первую ячейку
                b = *col;
                *col = a;
                a = b;
            }
        } else { // Нечетные строки
            for (auto col = row->end() - 1; col >= row->begin(); --col) {
                if (row == matrix.end() - 1 && col == row->end() - 1) continue; // Пропускаем последнюю ячейку
                b = *(col);
                *col = a;
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
    cout << "Введите количество строк" << endl;
    cin >> m;
    cout << "Введите количество столбцов" << endl;
    cin >> n;

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