#include "get_calendar.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>

using namespace std;

// Функция для определения високосного года
bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// Функция для подсчёта дней в месяце
int daysInMonth(int month, int year) {
    if (month == 2) { // 2 месяц это февраль
        return isLeapYear(year) ? 29 : 28;
    }
    if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    }
    return 31;
}

// Функция для подсчёта порядкового номера дня в году
int dayOfYear(int day, int month, int year) {
    int days = 0;
    for (int m = 1; m < month; ++m) {
        days += daysInMonth(m, year);
    }
    days += day;
    return days;
}

// Функция для подсчёта дней до заданной даты
int daysUntilDate(int day, int month, int year) {
    time_t now = time(0);
    tm current;
    localtime_s(&current, &now);

    int currentDay = current.tm_mday;
    int currentMonth = current.tm_mon + 1;
    int currentYear = current.tm_year + 1900;

    int daysRemaining = 0;

    // Если даты в одном году
    if (year == currentYear) {
        daysRemaining = dayOfYear(day, month, year) - dayOfYear(currentDay, currentMonth, currentYear);
    }
    else if (year > currentYear) {
        // Дни до конца текущего года
        daysRemaining += (isLeapYear(currentYear) ? 366 : 365) - dayOfYear(currentDay, currentMonth, currentYear);

        // Дни в полных годах между текущим и целевым
        for (int y = currentYear + 1; y < year; ++y) {
            daysRemaining += isLeapYear(y) ? 366 : 365;
        }

        // Дни в целевом году
        daysRemaining += dayOfYear(day, month, year);
    }
    else {
        // Если дата в прошлом
        daysRemaining -= dayOfYear(currentDay, currentMonth, currentYear);

        // Дни в полных годах между текущим и целевым
        for (int y = currentYear - 1; y > year; --y) {
            daysRemaining -= isLeapYear(y) ? 366 : 365;
        }

        // Дни в целевом году
        daysRemaining -= (isLeapYear(year) ? 366 : 365) - dayOfYear(day, month, year);
    }

    return daysRemaining;
}

// Функция для определения дня недели
string dayOfWeek(int day, int month, int year) {
    tm date = {};
    date.tm_mday = day;
    date.tm_mon = month - 1;
    date.tm_year = year - 1900;

    mktime(&date); // Автоматически корректирует дату и устанавливает день недели

    const char* days[] = { "Воскресенье", "Понедельник", "Вторник", "Среда", "Четверг", "Пятница", "Суббота" };
    return days[date.tm_wday];
}

// Главная функция
void getCalendar() {
    setlocale(LC_ALL, "Russian");

    int day, month, year, option;

    do {
        cout << "Введите дату (день месяц год): ";
        cin >> day >> month >> year;

        if (month < 1 || month > 12 || day < 1 || day > daysInMonth(month, year)) {
            cout << "Ошибка: некорректная дата." << endl;
        }
        else {
            cout << "Введённая дата: " << day;
            if (month < 10) {
                cout << ".0" << month << "." << year << endl;
            }
            else {
                cout << "." << month << "." << year << endl;
            }
            if (isLeapYear(year)) {
                cout << "Год является високосным" << endl;
            }
            else {
                cout << "Год не является високосным" << endl;
            }
            cout << "День недели: " << dayOfWeek(day, month, year) << endl;
            cout << "Номер дня в году: " << dayOfYear(day, month, year) << endl;
            cout << "Дней до введённой даты: " << daysUntilDate(day, month, year) << endl;
            cout << "Хотите продолжить? (1 - да, 2 - нет): ";
            cin >> option;
        }
    } while (option != 2);
}