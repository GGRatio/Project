#include <iostream>
#include "get_calendar.h"
#include"number_translation.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	int userChoice;

    do {
        cout << "\n1 - Calendar\n2 - NumberTranslation\n3 - ������ 3\n4 - ������ 4\n5 - �����\n";
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
            cout << "����� �� ���������\n";
            break;
        default:
            cout << "������: �������� ����\n";
            break;
        }
    } while (userChoice != 5);
}