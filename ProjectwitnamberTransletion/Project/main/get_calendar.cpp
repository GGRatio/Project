#include "get_calendar.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>

using namespace std;

// ������� ��� ����������� ����������� ����
bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// ������� ��� �������� ���� � ������
int daysInMonth(int month, int year) {
    if (month == 2) { // 2 ����� ��� �������
        return isLeapYear(year) ? 29 : 28;
    }
    if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    }
    return 31;
}

// ������� ��� �������� ����������� ������ ��� � ����
int dayOfYear(int day, int month, int year) {
    int days = 0;
    for (int m = 1; m < month; ++m) {
        days += daysInMonth(m, year);
    }
    days += day;
    return days;
}

// ������� ��� �������� ���� �� �������� ����
int daysUntilDate(int day, int month, int year) {
    time_t now = time(0);
    tm current;
    localtime_s(&current, &now);

    int currentDay = current.tm_mday;
    int currentMonth = current.tm_mon + 1;
    int currentYear = current.tm_year + 1900;

    int daysRemaining = 0;

    // ���� ���� � ����� ����
    if (year == currentYear) {
        daysRemaining = dayOfYear(day, month, year) - dayOfYear(currentDay, currentMonth, currentYear);
    }
    else if (year > currentYear) {
        // ��� �� ����� �������� ����
        daysRemaining += (isLeapYear(currentYear) ? 366 : 365) - dayOfYear(currentDay, currentMonth, currentYear);

        // ��� � ������ ����� ����� ������� � �������
        for (int y = currentYear + 1; y < year; ++y) {
            daysRemaining += isLeapYear(y) ? 366 : 365;
        }

        // ��� � ������� ����
        daysRemaining += dayOfYear(day, month, year);
    }
    else {
        // ���� ���� � �������
        daysRemaining -= dayOfYear(currentDay, currentMonth, currentYear);

        // ��� � ������ ����� ����� ������� � �������
        for (int y = currentYear - 1; y > year; --y) {
            daysRemaining -= isLeapYear(y) ? 366 : 365;
        }

        // ��� � ������� ����
        daysRemaining -= (isLeapYear(year) ? 366 : 365) - dayOfYear(day, month, year);
    }

    return daysRemaining;
}

// ������� ��� ����������� ��� ������
string dayOfWeek(int day, int month, int year) {
    tm date = {};
    date.tm_mday = day;
    date.tm_mon = month - 1;
    date.tm_year = year - 1900;

    mktime(&date); // ������������� ������������ ���� � ������������� ���� ������

    const char* days[] = { "�����������", "�����������", "�������", "�����", "�������", "�������", "�������" };
    return days[date.tm_wday];
}

// ������� �������
void getCalendar() {
    setlocale(LC_ALL, "Russian");

    int day, month, year, option;

    do {
        cout << "������� ���� (���� ����� ���): ";
        cin >> day >> month >> year;

        if (month < 1 || month > 12 || day < 1 || day > daysInMonth(month, year)) {
            cout << "������: ������������ ����." << endl;
        }
        else {
            cout << "�������� ����: " << day;
            if (month < 10) {
                cout << ".0" << month << "." << year << endl;
            }
            else {
                cout << "." << month << "." << year << endl;
            }
            if (isLeapYear(year)) {
                cout << "��� �������� ����������" << endl;
            }
            else {
                cout << "��� �� �������� ����������" << endl;
            }
            cout << "���� ������: " << dayOfWeek(day, month, year) << endl;
            cout << "����� ��� � ����: " << dayOfYear(day, month, year) << endl;
            cout << "���� �� �������� ����: " << daysUntilDate(day, month, year) << endl;
            cout << "������ ����������? (1 - ��, 2 - ���): ";
            cin >> option;
        }
    } while (option != 2);
}