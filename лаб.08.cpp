/*
    Лабораторная работа №8
    Вариант 26
    Студент Останин С.А; группа ПИ-Э
    Задача:
    Даны две строки символов s1 и s2, а также натуральное число L.
     Выяснить, если у этих строк общая подстрока длиной L.  
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool SeekString(const string &s1, const string &s2 ,int L) {
    if (L <= 0 || s1.length() < L || s2.length() < L) {
        return false;
    }
    
    // Проверяем все подстроки длиной L в первой строке
    for (size_t i = 0; i <= s1.length() - L; ++i) {
        string substring = s1.substr(i, L);
        
        // Сравниваем подстроку из первой строки с подстроками во второй строке
        for (size_t j = 0; j <= s2.length() - L; ++j) {
            if (substring == s2.substr(j, L)) {
                return true; // Найдена общая подстрока
        }
    }

    return false; // Общая подстрока не найдена
}

int main() {
    setlocale(LC_ALL, "Russian");
    ifstream inputFile("input.txt");
    
    if (!inputFile.is_open()) {
        cerr << "Файл невозможно открыть"  << endl;
        exit(1);
    }

    string s1, s2;
    int L;

    // Читаем строки и длину подстроки из файла
    cout << "Введите 1 строку " << endl;
    inputFile >> s1 >> L;
    cout << "Введите 2 строку " << endl;
    inputFile >> s2 >> L;
    inputFile.close();

    if (SeekString(s1, s2, L)) {
        cout << "Есть общая подстрока длиной " << L << "." << endl;
        cout << "Подстрока: " << lstring << "." << endl;
    } else {
        cout << "Нет общей подстроки длиной " << L << "." << endl;
    }

    return 0;
}
