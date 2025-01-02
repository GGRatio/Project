#include <iostream>
#include "get_calendar.h"
#include"number_translation.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	int userChoice;

    do {
        cout << "\n1 - Calendar\n2 - NumberTranslation\n3 - модуль 3\n4 - модуль 4\n5 - выход\n";
        cin >> userChoice;
        switch (userChoice) {
        case 1:
            getCalendar();
            break;
        case 2:
            number_translation();
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            cout << "Выход из программы\n";
            break;
        default:
            cout << "Ошибка: неверный ввод\n";
            break;
        }
    } while (userChoice != 5);
}