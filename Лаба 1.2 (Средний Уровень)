#include <iostream>
#include <queue>

using namespace std;

// Функция для объединения двух очередей
void mergeQueues(queue<int>& q1, queue<int>& q2, queue<int>& result) {
    while (!q1.empty() && !q2.empty()) {
        // Добавляем элемент из первой очереди
        result.push(q1.front());
        q1.pop();
        // Добавляем элемент из второй очереди
        result.push(q2.front());
        q2.pop();
    }
}

int main() {
    // Создаем две непустые очереди
    queue<int> q1, q2;
    q1.push(1);
    q1.push(3);
    q1.push(5);

    q2.push(2);
    q2.push(4);
    q2.push(6);

    // Создаем новую очередь для объединения
    queue<int> result;
    queue<int> result1;

    // Объединяем очереди
    mergeQueues(q1, q2, result);

    result1 = result;
    // Выводим указатели на начало и конец полученной очереди
    cout << "Содержимое полученной очереди: ";
    while (!result1.empty()) {
        cout << result1.front() << " ";
        result1.pop();
    }
    cout << endl;

    cout << "Начало полученной очереди: " << result.front() << endl;
    cout << "Конец полученной очереди: " << result.back() << endl;
    
    return 0;
}
