#include <iostream>

using namespace std;

// Структура для узла стека
struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

// Класс стека на основе односвязного списка
class Stack {
private:
    Node* top; // Указатель на вершину стека

public:
    Stack() : top(nullptr) {}

    // Функция для добавления элемента в стек (push)
    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
    }

    // Функция для удаления элемента из стека (pop)
    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty. Cannot pop." << endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    // Функция для проверки на пустоту стека
    bool isEmpty() {
        return top == nullptr;
    }

    // Функция для печати содержимого стека
    void printStack() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Stack contents:" << endl;
        Node* current = top;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    // Функция для нахождения суммы всех положительных элементов в стеке
    int sumPositive() {
        int sum = 0;
        Node* current = top;
        while (current != nullptr) {
            if (current->data > 0) {
                sum += current->data;
            }
            current = current->next;
        }
        return sum;
    }
};

int main() {
    setlocale(LC_ALL, "RU");
    Stack stack;

    // Добавляем числа в стек
    stack.push(-5);
    stack.push(3);
    stack.push(-4);
    stack.push(5);

    // Выводим содержимое стека
    cout << "Содержимое стека:" << endl;
    stack.printStack();

    // Удаляем один элемент из стека
    stack.pop();

    // Добавляем число 10 в стек
    stack.push(10);

    // Выводим содержимое стека после удаления и добавления элементов
    cout << "Содержимое стека после удаления и добавления элементов:" << endl;
    stack.printStack();

    // Находим сумму всех положительных элементов в стеке
    int sumPos = stack.sumPositive();
    cout << "Сумма всех положительных элементов в стеке: " << sumPos << endl;

    return 0;
}
