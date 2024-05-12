#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Banknote {
private:
    int nominal;    // Поле 1 - Номинал купюры
    int quantity;   // Поле 2 - Количество купюр

public:
    // Конструктор для инициализации объекта
    Banknote(int nominal_val, int quantity_val) : nominal(nominal_val), quantity(quantity_val) {}

    // Функция формирования строки с информацией об объекте
    string getInfo() {
        return "Номинал: " + to_string(nominal) + ", Количество: " + to_string(quantity);
    }

    // Функция вычисления суммы купюр данного номинала
    int calculateSum() {
        return nominal * quantity;
    }
};

int main() {
    setlocale(LC_ALL, "rus");

    vector<Banknote> banknotes; // Вектор для хранения объектов класса Banknote

    // Ввод значений полей каждого объекта
    char addMore;
    do {
        int nominal, quantity;
        cout << "Введите номинал купюры: ";
        cin >> nominal;
        cout << "Введите количество купюр: ";
        cin >> quantity;

        // Создание объекта класса Banknote и добавление его в вектор
        banknotes.push_back(Banknote(nominal, quantity));

        cout << "Хотите добавить еще одну купюру? (y/n): ";
        cin >> addMore;
    } while (addMore == 'y' || addMore == 'Y');

    // Вывод информации о купюрах
    cout << "Информация о купюрах:\n";
    for (auto& note : banknotes) {
        cout << note.getInfo() << endl;
    }

    // Вычисление и вывод общей суммы купюр
    int total = 0;
    for (auto& note : banknotes) {
        total += note.calculateSum();
    }
    cout << "Общая сумма купюр: " << total << endl;

    return 0;
}
