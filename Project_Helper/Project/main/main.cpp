#include <iostream>
#include <windows.h>
#include "get_calendar.h"
#include "number_translation.h"
#include "clock_and_timer.h"
#include "calculator.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "rus");
	int userChoice;

    do {
        cout << "\n1 - Calendar\n2 - NumberTranslation\n3 - ClockAndTimer\n4 - Calculator\n5 - Exit\n";
        cin >> userChoice;
        switch (userChoice) {
        case 1:
            getCalendar();
            break;
        case 2:
            number_translation();
            break;
        case 3:
            clock_and_timer();
            break;
        case 4:
            calculator();
            break;
        case 5:
            cout << "End programm\n";
            break;
        default:
            cout << "Error\n";
            break;
        }
    } while (userChoice != 5);
}
