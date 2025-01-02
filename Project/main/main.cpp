#include <iostream>

using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	int userChoice;

    do {
        cout << "\n1 - Calendar\n2 - NumberTranslation\n3 - модуль 3\n4 - модуль 4\n5 - выход\n";
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
            cout << "Выход из программы\n";
            break;
        default:
            cout << "Ошибка: неверный ввод\n";
            break;
        }
    } while (userChoice != 5);
}