#include <iostream>

using namespace std;

// Структура для представления узла односвязного списка
struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

// Класс стека на основе односвязного списка
class Stack {
private:
    Node* top; // Вершина стека

public:
    Stack() : top(nullptr) {}

    // Добавление элемента в стек (push)
    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
    }

    // Удаление элемента из стека (pop)
    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty. Cannot pop element." << endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    // Проверка на пустоту стека
    bool isEmpty() {
        return top == nullptr;
    }

    // Возвращает значение вершины стека без удаления
    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty. Peek operation cannot be performed." << endl;
            return -1;
        }
        return top->data;
    }

    // Распечатать содержимое стека
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

    // Поиск минимального элемента в стеке
    int findMin() {
        if (isEmpty()) {
            cout << "Stack is empty. Cannot find minimum element." << endl;
            return -1;
        }
        int minElement = top->data;
        Node* current = top->next;
        while (current != nullptr) {
            if (current->data < minElement) {
                minElement = current->data;
            }
            current = current->next;
        }
        return minElement;
    }
};

int main() {
    Stack stack;

    // Добавление элементов в стек
    stack.push(4);
    stack.push(3);
    stack.push(1);
    stack.push(2);
    stack.push(4);

    // Печать содержимого стека
    stack.printStack();
    cout << "Stack printed successfully." << endl;

    // Удаление одного элемента из стека
    stack.pop();
    cout << "One element removed from the stack." << endl;

    // Печать содержимого стека после удаления элемента
    stack.printStack();
    cout << "Stack printed successfully after removal." << endl;

    // Поиск минимального элемента в стеке
    int minElement = stack.findMin();
    if (minElement != -1) {
        cout << "Minimum element in the stack: " << minElement << endl;
    }

    return 0;
}
