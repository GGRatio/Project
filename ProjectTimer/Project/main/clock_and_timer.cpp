#include <iostream>
#include <iomanip>
#include <thread>
#include <chrono>
#include "clock_and_timer.h"

using namespace std;

class Clock {
public:
    void displayCurrentTime() {
        setlocale(LC_CTYPE, "rus");
        auto now = chrono::system_clock::now();
        time_t now_time_t = chrono::system_clock::to_time_t(now);

        // параметры для локализации времени
        tm local_tm;
        localtime_s(&local_tm, &now_time_t);

        cout << "Текущее время: " << put_time(&local_tm, "%Y-%m-%d %H:%M:%S") << endl;
    }
};

class Timer {
public:
    void startTimer(int seconds) {
        cout << "Запуск таймера на " << seconds << " секунд" << endl;
        this_thread::sleep_for(chrono::seconds(seconds));
        cout << "Время вышло!" << endl;
    }
};

void clock_and_timer() {
    Clock clock;
    Timer timer;

    // отображение текущего времени
    clock.displayCurrentTime();

    // установка таймера
    int seconds;
    cout << "Введите количество секунд для таймера: ";
    cin >> seconds;

    timer.startTimer(seconds);

}

