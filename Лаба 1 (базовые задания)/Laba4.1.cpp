
#include <iostream>
#include <queue>
#include <limits> // Для использования константы numeric_limits
#include <string> // Для использования функции stod

using namespace std;

// Функция для проверки, является ли строка вещественным числом
bool isFloat(const string& s) {
    size_t pos;
    stod(s, &pos);
    return pos == s.size() && pos != 0;
}

// Функция для поиска минимального элемента в очереди
double findMinElement(queue<double> q) {
    double minElement = numeric_limits<double>::max(); // Инициализируем минимальное значение максимально возможным числом
    while (!q.empty()) {
        if (q.front() < minElement) {
            minElement = q.front();
        }
        q.pop();
    }
    return minElement;
}

// Функция для просмотра данных очереди
void viewQueue(queue<double> q) {
    cout << "Queue contents: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main() {
    queue<double> myQueue;
    int count;

    // Запрос количества элементов очереди
    cout << "Enter the number of elements for the queue: ";
    cin >> count;

    // Ввод элементов очереди
    cout << "Enter " << count << " floating-point numbers for the queue:" << endl;
    for (int i = 0; i < count; ++i) {
        string input;
        double element;
        cout << "Element " << i + 1 << ": ";
        cin >> input;

        // Проверка на корректность ввода вещественного числа
        if (isFloat(input)) {
            element = stod(input);
            myQueue.push(element);
        }
        else {
            cout << "Invalid input. Please enter a floating-point number." << endl;
            i--; // Для повторного запроса ввода элемента
        }
    }

    // Определение минимального элемента в очереди
    double minElement = findMinElement(myQueue);

    // Просмотр данных очереди
    viewQueue(myQueue);

    // Вывод минимального элемента
    cout << "Minimum element in the queue: " << minElement << endl;

    return 0;
}
