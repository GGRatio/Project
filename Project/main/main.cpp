#include <iostream>

using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	int userChoice;

    do {
        cout << "\n1 - Calendar\n2 - NumberTranslation\n3 - ������ 3\n4 - ������ 4\n5 - �����\n";
        cin >> userChoice;
        switch (userChoice>'9') {
        case 1:
            break;
        case 2:
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