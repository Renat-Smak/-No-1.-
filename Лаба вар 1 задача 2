#include <iostream>
#include <stack>

using namespace std;

struct Monitor {
    string name;
    float diagonal;
    float price;

    Monitor(string n, float d, float p) : name(n), diagonal(d), price(p) {}
};

// Функция для просмотра данных стека
void viewStack(stack<Monitor> s) {
    cout << "данные стека:" << endl;
    while (!s.empty()) {
        cout << "Имя: " << s.top().name << ", Диагональ: " << s.top().diagonal << " дюймов, Цена: $" << s.top().price << endl;
        s.pop();
    }
    cout << endl;
}

int main() {
    setlocale(LC_ALL, "RU");
    stack<Monitor> monitorStack;
    int count;

    // Запрос количества мониторов
    cout << "Введите количество мониторов: ";
    cin >> count;

    // Ввод информации о мониторах
    cout << "Введите характеристики монитора (монитор, диагональ, цена) для " << count << " монитора:" << endl;
    for (int i = 0; i < count; ++i) {
        string name;
        float diagonal, price;
        cout << "Монитор " << i + 1 << ":" << endl;
        cout << "имя: ";
        cin >> name;
        cout << "диагональ (в дюймах): ";
        cin >> diagonal;
        cout << "Цена: $";
        cin >> price;
        monitorStack.push(Monitor(name, diagonal, price));
    }

    // Просмотр данных стека
    viewStack(monitorStack);

    // Определение количества мониторов с диагональю более 20 дюймов
    int countMoreThan20 = 0;
    stack<Monitor> tempStack = monitorStack;
    while (!tempStack.empty()) {
        if (tempStack.top().diagonal > 20.0) {
            countMoreThan20++;
        }
        tempStack.pop();
    }

    // Вывод результата
    cout << "Количество мониторов с диагональю больше 20 дюймов: " << countMoreThan20 << endl;

    return 0;
}
