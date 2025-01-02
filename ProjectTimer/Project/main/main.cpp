#include <iostream>
#include <windows.h>
#include "get_calendar.h"
#include"number_translation.h"
#include "clock_and_timer.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "rus");
	int userChoice;

    do {
        cout << "\n1 - Calendar\n2 - NumberTranslation\n3 - ClockAndTimer\n4 - ìîäóëü 4\n5 - âûõîä\n";
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
            break;
        case 5:
            cout << "Âûõîä èç ïðîãðàììû\n";
            break;
        default:
            cout << "Îøèáêà: íåâåðíûé ââîä\n";
            break;
        }
    } while (userChoice != 5);
}
