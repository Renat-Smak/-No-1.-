#include <iostream>
#include <list>
#include <string>

using namespace std;

// Структура для хранения информации об автобусе
struct Bus {
    int number;
    string driverName;
    string routeNumber;
};

// Функция для вывода информации об автобусе
void printBus(const Bus& bus) {
    cout << "Bus number: " << bus.number << ", Driver: " << bus.driverName << ", Route: " << bus.routeNumber << endl;
}

int main() {
    list<Bus> park; // Список автобусов в парке
    list<Bus> route; // Список автобусов на маршруте

    int choice;
    do {
        cout << "\nMenu:\n1. Add a bus to the park\n2. Remove a bus from the park\n3. Move a bus to the route\n4. Move a bus to the park\n5. Display buses in the park\n6. Display buses on the route\n7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                Bus newBus;
                cout << "Enter bus number: ";
                cin >> newBus.number;
                cout << "Enter driver's name: ";
                cin.ignore(); // Clear input buffer
                getline(cin, newBus.driverName);
                cout << "Enter route number: ";
                cin >> newBus.routeNumber;
                park.push_back(newBus);
                break;
            }
            case 2: {
                int busNumber;
                cout << "Enter bus number to remove from the park: ";
                cin >> busNumber;
                for (auto it = park.begin(); it != park.end(); ++it) {
                    if (it->number == busNumber) {
                        route.push_back(*it);
                        it = park.erase(it);
                        cout << "Bus moved to the route.\n";
                        break;
                    }
                }
                break;
            }
            case 3: {
                int busNumber;
                cout << "Enter bus number to move from the route: ";
                cin >> busNumber;
                for (auto it = route.begin(); it != route.end(); ++it) {
                    if (it->number == busNumber) {
                        park.push_back(*it);
                        it = route.erase(it);
                        cout << "Bus moved to the park.\n";
                        break;
                    }
                }
                break;
            }
            case 4: {
                int busNumber;
                cout << "Enter bus number to move from the park: ";
                cin >> busNumber;
                for (auto it = park.begin(); it != park.end(); ++it) {
                    if (it->number == busNumber) {
                        route.push_back(*it);
                        it = park.erase(it);
                        cout << "Bus moved to the route.\n";
                        break;
                    }
                }
                break;
            }
            case 5: {
                cout << "\nBuses in the park:\n";
                for (const auto& bus : park) {
                    printBus(bus);
                }
                break;
            }
            case 6: {
                cout << "\nBuses on the route:\n";
                for (const auto& bus : route) {
                    printBus(bus);
                }
                break;
            }
            case 7:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 7);

    return 0;
}