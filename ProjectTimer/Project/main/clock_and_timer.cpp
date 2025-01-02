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

        // ��������� ��� ����������� �������
        tm local_tm;
        localtime_s(&local_tm, &now_time_t);

        cout << "������� �����: " << put_time(&local_tm, "%Y-%m-%d %H:%M:%S") << endl;
    }
};

class Timer {
public:
    void startTimer(int seconds) {
        cout << "������ ������� �� " << seconds << " ������" << endl;
        this_thread::sleep_for(chrono::seconds(seconds));
        cout << "����� �����!" << endl;
    }
};

void clock_and_timer() {
    Clock clock;
    Timer timer;

    // ����������� �������� �������
    clock.displayCurrentTime();

    // ��������� �������
    int seconds;
    cout << "������� ���������� ������ ��� �������: ";
    cin >> seconds;

    timer.startTimer(seconds);

}

