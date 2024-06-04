#include <iostream>
#include <map>
#include <chrono>
#include <iomanip>
#include <sstream>
#include <windows.h>
#include <fstream>
#include "queue.h" // Include the header file

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // Initialize queues
    initializeQueues();

    // Счетчики для каждого типа услуг
    map<char, int> counters = { {'A', 0}, {'B', 0}, {'C', 0}, {'D', 0}, {'E', 0},
                               {'F', 0}, {'G', 0}, {'H', 0}, {'I', 0} };

    ofstream outFile("C:\\Users\\User\\Desktop\\Ренат\\client_history.txt", ios::app); // открытие файла для записи (в режиме добавления)
    if (!outFile.is_open()) {
        cerr << "Ошибка открытия файла для записи!" << endl;
        return 1;
    }

    int choice;
    do {
        cout << "Выберите тип услуги (введите 0 для завершения ввода):\n"
            << "1. Вклады\n"
            << "2. Кредиты\n"
            << "3. Кредитные карты\n"
            << "4. Ипотека\n"
            << "5. Индивидуальные сейфы\n"
            << "6. Платежи\n"
            << "7. Прием и выдача наличных\n"
            << "8. Денежные переводы\n"
            << "9. Валютно-обменные операции\n"
            << "Выбор: ";
        cin >> choice;

        if (choice == 0) {
            break;
        }

        if (choice < 1 || choice > 9) {
            cout << "Неверный номер операции\n";
            continue;
        }

        string name, surname;
        cout << "Введите имя клиента: ";
        cin >> name;
        cout << "Введите фамилию клиента: ";
        cin >> surname;

        char serviceLetter;
        switch (choice) {
        case 1: serviceLetter = 'A'; break;
        case 2: serviceLetter = 'B'; break;
        case 3: serviceLetter = 'C'; break;
        case 4: serviceLetter = 'D'; break;
        case 5: serviceLetter = 'E'; break;
        case 6: serviceLetter = 'F'; break;
        case 7: serviceLetter = 'G'; break;
        case 8: serviceLetter = 'H'; break;
        case 9: serviceLetter = 'I'; break;
        }

        // Формирование номера талончика
        int counter = ++counters[serviceLetter];
        string ticketNumber = serviceLetter + to_string(counter).insert(0, 3 - to_string(counter).length(), '0');

        // Получение текущего времени
        auto now = chrono::system_clock::now();
        time_t now_time = chrono::system_clock::to_time_t(now);
        tm local_tm;
        localtime_s(&local_tm, &now_time);

        // Форматирование времени
        stringstream timeStream;
        timeStream << put_time(&local_tm, "%Y-%m-%d %H:%M:%S");

        // Формирование строки с информацией о клиенте
        string clientInfo = name + " " + surname + " " + ticketNumber + " " + timeStream.str();

        // Добавление клиента в соответствующую очередь
        switch (serviceLetter) {
        case 'A': case 'C': case 'E':
            queue1.push({ ticketNumber, clientInfo });
            break;
        case 'B': case 'D':
            queue2.push({ ticketNumber, clientInfo });
            break;
        case 'F': case 'H':
            queue3.push({ ticketNumber, clientInfo });
            break;
        case 'G': case 'I':
            queue4.push({ ticketNumber, clientInfo });
            break;
        }

        cout << "Клиент " << name << " " << surname << " добавлен в очередь с номером талончика: " << ticketNumber << " в " << timeStream.str() << endl;

    } while (true);

    // Печать содержимого каждой очереди и запись в файл
    printQueue(queue1, "окна 1", outFile);
    printQueue(queue2, "окна 2", outFile);
    printQueue(queue3, "окна 3", outFile);
    printQueue(queue4, "окна 4", outFile);

    outFile.close(); // закрытие файла

    return 0;
}