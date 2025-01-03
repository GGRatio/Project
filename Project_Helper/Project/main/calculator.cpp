#include "calculator.h"
#include <iostream>

double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    return a / b;
}

int calculator() {
    setlocale(LC_ALL, "ru");
    using namespace std;
    double num1, num2, result;
    char op;

    cout << "������� ������ �����: ";
    cin >> num1;
    cout << "������� �������� (+, -, *, /): ";
    cin >> op;
    cout << "������� ������ �����: ";
    cin >> num2;

    switch (op) {
    case '+':
        result = add(num1, num2);
        break;
    case '-':
        result = subtract(num1, num2);
        break;
    case '*':
        result = multiply(num1, num2);
        break;
    case '/':
        if (num2 != 0) {
            result = divide(num1, num2);
        }
        else {
            cout << "������: ������� �� ����!" << endl;
            return 1;
        }
        break;
    default:
        cout << "����������� ��������!" << endl;
        return 1;
    }

    cout << "���������: " << result << endl;
    return 0;
}