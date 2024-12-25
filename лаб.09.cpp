/*
    Лабораторная работа №9
    Вариант 26
    Студент Останин С.А; группа ПИ-Э
    Задача:
    Дана символьная строка, в которой могут быть круглые скобки.
    Реализовать булевскую рекурсивную функцию, возвращающую истина,
    если в строке соблюден баланс круглых скобок, и ложь – в противном случае.  
*/

#include <iostream>
#include <string>
#include <clocale>

using namespace std;

// Рекурсивная функция проверяющая баланс скобок
bool isBalanced(const string &str, int i = 0, int balance = 0) {
    
    if (i == str.length()) {
        return balance == 0; 
    }

    if (str[i] == '(') {
        return isBalanced(str, i + 1, balance + 1);
    }
    else if (str[i] == ')') {
        if (balance == 0) {
            return false;
        }
        return isBalanced(str, i + 1, balance - 1);
    } else {
        return isBalanced(str, i + 1, balance);
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    string input;
    
    cout << "Введите строку со скобками: ";
    getline(cin, input);

    // Проверяем баланс и выводим результат
    if (isBalanced(input)) {
        cout << "Строка сбалансирована." << endl;
    } else {
        cout << "Строка не сбалансирована." << endl;
    }

    return 0;
}