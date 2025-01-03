#include <iostream>
#include <string>
#include <cstdlib>
#include <windows.h>
#include <cctype>
#include "number_translation.h"

using namespace std;

int operation1() {
    setlocale(LC_CTYPE, "RUSSIAN");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    int input;
    char tmp[33];
    char operationNumber;

    do {
        cout << "1 - двоичная система, 2 - четырёхричная система, 3 - восьмиричная система, 4 - шестнадцатиричная, 5 - тридцати двухричная система" << endl;
        cout << "Введите номер системы (или 'q' для выхода)(Максимальное число 99999999): ";
        cin >> operationNumber;

        if (operationNumber == 'q') {
            break;
        }

        if (!isdigit(operationNumber) || operationNumber < '1' || operationNumber > '5') {
            cout << "Неверный ввод. Пожалуйста, введите номер от 1 до 5 или 'q' для выхода." << endl;
            continue;
        }

        cout << "Введите число: ";
        cin >> input;

        if (input < 0 || input > 99999999) {
            cout << "Число должно быть в диапазоне от 0 до 99999999." << endl;
            continue;
        }

        switch (operationNumber) {
        case '1':
            _itoa_s(input, tmp, 2);
            break;
        case '2':
            _itoa_s(input, tmp, 4);
            break;
        case '3':
            _itoa_s(input, tmp, 8);
            break;
        case '4':
            _itoa_s(input, tmp, 16);
            break;
        case '5':
            _itoa_s(input, tmp, 32);
            break;
        }
        cout << "Код: " << tmp << endl;
    } while (true);

    return 0;
}

int operation2() {
    setlocale(LC_CTYPE, "RUSSIAN");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    string input;
    char operationNumber1;

    do {
        cout << "1 - двоичная система, 2 - четырёхричная система, 3 - восьмиричная система, 4 - шестнадцатиричная система, 5 - тридцати двухричная система" << endl;
        cout << "Введите номер системы (или 'q' для выхода): ";
        cin >> operationNumber1;

        if (operationNumber1 == 'q') {
            break;
        }

        if (!isdigit(operationNumber1) || operationNumber1 < '1' || operationNumber1 > '5') {
            cout << "Неверный ввод. Пожалуйста, введите номер от 1 до 5 или 'q' для выхода." << endl;
            continue;
        }

        cout << "Введите число: ";
        cin >> input;

        int decimalValue = 0;

        switch (operationNumber1) {
        case '1':
            decimalValue = strtol(input.c_str(), nullptr, 2);
            break;
        case '2':
            decimalValue = strtol(input.c_str(), nullptr, 4);
            break;
        case '3':
            decimalValue = strtol(input.c_str(), nullptr, 8);
            break;
        case '4':
            decimalValue = strtol(input.c_str(), nullptr, 16);
            break;
        case '5':
            decimalValue = strtol(input.c_str(), nullptr, 32);
            break;
        }

        cout << "Десятичное значение: " << decimalValue << endl;
    } while (true);

    return 0;
}

void number_translation() {
    setlocale(LC_CTYPE, "RUSSIAN");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    int operationNumber;

    do {
        cout << "Введите номер операции: 1 - перевод в систему счисления, 2 - перевод обратно в число, 3 - выход из программы" << endl;
        cin >> operationNumber;

        if (operationNumber < 1 || operationNumber > 3) {
            cout << "Неверный номер операции." << endl;
            continue;
        }

        switch (operationNumber) {
        case 1:
            operation1();
            break;
        case 2:
            operation2();
            break;
        case 3:
            cout << "Выход из программы" << endl;
            break;
        }
    } while (operationNumber != 3);
}