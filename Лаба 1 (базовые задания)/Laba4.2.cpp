#include <iostream>
#include <queue>
#include <string>

using namespace std;

struct Computer {
    string name;
    int ram;

    Computer(string n, int r) : name(n), ram(r) {}
};

// Функция для просмотра данных очереди
void viewQueue(queue<Computer>& q) {
    queue<Computer> temp = q;
    cout << "Queue contents:" << endl;
    while (!temp.empty()) {
        cout << "Computer: " << temp.front().name << ", RAM: " << temp.front().ram << " GB" << endl;
        temp.pop();
    }
}

// Функция для вычисления общего объема оперативной памяти компьютеров в очереди
int totalRAM(queue<Computer>& q) {
    int total = 0;
    queue<Computer> temp = q;
    while (!temp.empty()) {
        total += temp.front().ram;
        temp.pop();
    }
    return total;
}

int main() {
    queue<Computer> computerQueue;
    int count;

    // Запрос количества компьютеров
    cout << "Enter the number of computers: ";
    cin >> count;

    // Ввод информации о компьютерах
    cout << "Enter computer details (name and RAM in GB) for " << count << " computers:" << endl;
    for (int i = 0; i < count; ++i) {
        string name;
        int ram;
        cout << "Computer " << i + 1 << ":" << endl;
        cout << "Name: ";
        cin >> name;
        cout << "RAM (GB): ";
        cin >> ram;
        computerQueue.push(Computer(name, ram));
    }

    // Удаление первого компьютера из очереди
    if (!computerQueue.empty()) {
        cout << "Removing the first computer from the queue..." << endl;
        computerQueue.pop();
    }
    else {
        cout << "The queue is empty." << endl;
    }

    // Просмотр данных очереди
    viewQueue(computerQueue);

    // Вычисление общего объема оперативной памяти компьютеров
    int total = totalRAM(computerQueue);
    cout << "Total RAM of computers in the queue: " << total << " GB" << endl;

    return 0;
}
