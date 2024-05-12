#include <iostream>
#include <string>

using namespace std;

class Time {
private:
    int hours;
    int minutes;
    int seconds;

public:
    // Конструктор по умолчанию
    Time() : hours(0), minutes(0), seconds(0) {}

    // Конструктор перезагрузки с параметрами
    Time(int h, int m, int s) : hours(h), minutes(m), seconds(s) {}

    // Деструктор
    ~Time() {
        cout << "Объект удален" << endl;
    }

    // Вычисление общего количества секунд в указанном времени
    int totalSeconds() {
        return hours * 3600 + minutes * 60 + seconds;
    }

    // Увеличение времени на 5 секунд
    void increaseTimeBy5Seconds() {
        seconds += 5;
        if (seconds >= 60) {
            seconds -= 60;
            minutes++;
            if (minutes >= 60) {
                minutes -= 60;
                hours++;
                if (hours >= 24) {
                    hours = 0;
                }
            }
        }
    }

    // Функция формирования строки информации об объекте
    string getInfo() {
        return "Время: " + to_string(hours) + ":" + to_string(minutes) + ":" + to_string(seconds);
    }
};

int main() {
    setlocale(LC_ALL, "rus");
    // Создание объекта класса Time с конструктором по умолчанию
    Time time1;
    cout << "Время 1 (по умолчанию): " << time1.getInfo() << endl;
    cout << "Количество секунд: " << time1.totalSeconds() << endl;
    time1.increaseTimeBy5Seconds();
    cout << "Время 1 (увеличено на 5 секунд): " << time1.getInfo() << endl;

    // Ввод значений полей объекта из компонентов Edit
    int hours, minutes, seconds;
    cout << "Введите часы: ";
    cin >> hours;
    cout << "Введите минуты: ";
    cin >> minutes;
    cout << "Введите секунды: ";
    cin >> seconds;

    // Создание объекта класса Time с введенными значениями
    Time time2(hours, minutes, seconds);
    cout << "Время 2 (введенное): " << time2.getInfo() << endl;
    cout << "Количество секунд: " << time2.totalSeconds() << endl;
    time2.increaseTimeBy5Seconds();
    cout << "Время 2 (увеличено на 5 секунд): " << time2.getInfo() << endl;

    return 0;
}
