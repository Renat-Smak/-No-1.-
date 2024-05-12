#include <iostream>
#include <string>

using namespace std;

// Структура для узла очереди
struct Node {
    string data;
    Node* next;

    Node(const string& value) : data(value), next(nullptr) {}
};

// Класс очереди на основе односвязного списка
class Queue {
private:
    Node* front; // Указатель на начало очереди
    Node* rear; // Указатель на конец очереди

public:
    Queue() : front(nullptr), rear(nullptr) {}

    // Функция для добавления элемента в очередь (enqueue)
    void enqueue(const string& value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            front = rear = newNode;
        }
        else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    // Функция для удаления элемента из очереди (dequeue)
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return;
        }
        Node* temp = front;
        front = front->next;
        delete temp;
    }

    // Функция для проверки на пустоту очереди
    bool isEmpty() {
        return front == nullptr;
    }

    // Функция для распечатки содержимого очереди
    void printQueue() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Queue contents:" << endl;
        Node* current = front;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    // Функция для нахождения суммарной длины строк в очереди, кроме первой строки
    // Функция для нахождения суммарной длины строк в очереди, кроме первой строки
    int sumLength() {
        if (isEmpty() || front->next == nullptr) {
            return 0;
        }
        int sum = 0;
        Node* current = front->next;
        while (current != nullptr) {
            sum += current->data.length();
            current = current->next;
        }
        return sum;
    }

};

int main() {
    setlocale(LC_ALL, "RU");
    Queue queue;

    // Добавляем строки в очередь
    queue.enqueue("one");
    queue.enqueue("two");
    queue.enqueue("three");
    queue.enqueue("four");

    // Выводим содержимое очереди
    cout << "Содержимое очереди:" << endl;
    queue.printQueue();

    // Удаляем два элемента из очереди
    queue.dequeue();
    queue.dequeue();

    // Добавляем новую строку в очередь
    queue.enqueue("inf");

    // Выводим содержимое очереди после удаления и добавления элементов
    cout << "Содержимое очереди после удаления и добавления элементов:" << endl;
    queue.printQueue();

    // Находим суммарную длину строк в очереди, кроме первой строки
    int sum = queue.sumLength();
    cout << "Суммарная длина строк в очереди, кроме первой строки: " << sum << endl;

    return 0;
}
