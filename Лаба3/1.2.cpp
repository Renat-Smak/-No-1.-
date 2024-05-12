	#include <iostream>
#include <string>

using namespace std;

class Date {
private:
    int day;
    int month;
    int year;

public:
    // Конструктор по умолчанию
    Date() : day(1), month(1), year(2000) {}

    // Конструктор перезагрузки с параметрами
    Date(int d, int m, int y) : day(d), month(m), year(y) {}

    // Деструктор для освобождения памяти
    ~Date() {
        cout << "Объект удален" << endl;
    }

    // Определить, является ли год высокосным (кратным 4)
    bool isLeapYear() {
        return (year % 4 == 0);
    }

    // Увеличить дату на 5 дней
    void increaseDateBy5Days() {
        day += 5;
        // Проверка на корректность новой даты
        if (day > 30) {
            day -= 30;
            month++;
            if (month > 12) {
                month = 1;
                year++;
            }
        }
    }

    // Функция формирования строки информации об объекте
    string getInfo() {
        return "Дата: " + to_string(day) + "." + to_string(month) + "." + to_string(year);
    }
};

int main() {
    setlocale(LC_ALL, "rus");
    // Создание объекта класса Date с конструктором по умолчанию
    Date date1;
    cout << "Дата 1 (по умолчанию): " << date1.getInfo() << endl;
    cout << "Год высокосный? " << (date1.isLeapYear() ? "Да" : "Нет") << endl;
    date1.increaseDateBy5Days();
    cout << "Дата 1 (увеличена на 5 дней): " << date1.getInfo() << endl;

    // Ввод значений полей объекта из компонентов Edit
    int day, month, year;
    cout << "Введите день: ";
    cin >> day;
    cout << "Введите месяц: ";
    cin >> month;
    cout << "Введите год: ";
    cin >> year;

    // Создание объекта класса Date с введенными значениями
    Date date2(day, month, year);
    cout << "Дата 2 (введенная): " << date2.getInfo() << endl;
    cout << "Год высокосный? " << (date2.isLeapYear() ? "Да" : "Нет") << endl;
    date2.increaseDateBy5Days();
    cout << "Дата 2 (увеличена на 5 дней): " << date2.getInfo() << endl;

    return 0;
}
