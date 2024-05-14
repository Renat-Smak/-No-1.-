#include <iostream>

// Узел списка
template <typename T>
class Node {
public:
    T data; // Данные, хранящиеся в узле
    Node* next; // Указатель на следующий узел списка

    // Конструктор узла
    Node(T data) : data(data), next(nullptr) {}
};

// Однонаправленный линейный список
template <typename T>
class LinkedList {
private:
    Node<T>* head; // Указатель на начало списка

public:
    // Конструктор списка
    LinkedList() : head(nullptr) {}

    // Деструктор списка
    ~LinkedList() {
        clear();
    }

    // Добавление элемента в начало списка
    void push_front(T data) {
        Node<T>* newNode = new Node<T>(data);
        newNode->next = head;
        head = newNode;
    }

    // Удаление элемента из начала списка
    void pop_front() {
        if (head) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Очистка списка
    void clear() {
        while (head) {
            pop_front();
        }
    }

    // Вывод списка
    void print() const {
        Node<T>* current = head;
        while (current) {
            std::cout << current->data << " -> ";
            current = current->next;
        }
        std::cout << "nullptr" << std::endl;
    }

    // ... Другие методы, такие как поиск, удаление и т.д.
};

// Пример использования списка
int main() {
    LinkedList<int> list;
    list.push_front(1);
    list.push_front(2);
    list.push_front(3);

    std::cout << "Список: ";
    list.print();

    // ... Решение задачи 1 из раздела "Динамические структуры данных"

    return 0;
}
