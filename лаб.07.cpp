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

// Создание матрицы размера m строк n столбцов
void newMatrix(int**  matrix, int m, int n)
{
matrix = new int*[m];
for (int i = 0; i < m; i++)
matrix[i] = new int[n];
for (int i = 0; i < m; i++)
for (int j = 0; j < n; j++)
matrix[i][j] = i*10 + j;
}


// Функция для формирования последовательности змейкой
void getSnake(int** matrix, int m, int n, int* snake) {
    int index = 0;

    for (int i = 0; i < m; ++i) {
        if (i % 2 == 0) { // Чётная строка
            for (int j = 0; j < n; ++j) {
                snake[index++] = matrix[i][j];
            }
        } else { // Нечётная строка
            for (int j = n - 1; j >= 0; --j) {
                snake[index++] = matrix[i][j];
            }
        }
    }
}

// Функция для заполнения матрицы из змейки
void matrixSnake(int** matrix, int m, int n, int* snake) {
    int index = 0;

    for (int i = 0; i < m; ++i) {
        if (i % 2 == 0) { // Чётная строка
            for (int j = 0; j < n; ++j) {
                matrix[i][j] = snake[index++];
            }
        } else { // Нечётная строка
            for (int j = n - 1; j >= 0; --j) {
                matrix[i][j] = snake[index++];
            }
        }
    }
}

// Функция для циклического сдвига элементов змейки
void shiftSnake(int* snake, int length) {
    if (length == 0) return;
    
    int lastElement = snake[length - 1]; 
    for (int i = length - 1; i > 0; --i) {
        snake[i] = snake[i - 1]; 
    }
    snake[0] = lastElement; 
}

// Функция для вывода матрицы
void printMatrix(int ** matrix, int m, int n)
{
for (int i = 0; i < m; i++)
{
for (int j = 0; j < n; j++)
cout << setw(4) << matrix[i][j];
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
    int* snake; 

    newMatrix(matrix, m, n);
    cout << "Изначальная матрица:" << endl;
    printMatrix(matrix, m, n);

    getSnake(matrix, m, n, snake);
    int length = m * n; 
    shiftSnake(snake, length);

    matrixSnake(matrix, m, n, snake);
    cout << "Матрица после циклического сдвига:" << endl;
    printMatrix(matrix, m, n);
    
}