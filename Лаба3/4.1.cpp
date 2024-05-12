#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Product {
private:
    int caloriePer100g;  // Калорийность продукта на 100 грамм
    int weight;          // Вес продукта в граммах

public:
    // Конструктор для инициализации объекта
    Product(int calorie, int weight_val) : caloriePer100g(calorie), weight(weight_val) {}

    // Функция формирования строки с информацией о продукте
    string getInfo() {
        return "Калорийность на 100 г: " + to_string(caloriePer100g) + " ккал, Вес: " + to_string(weight) + " г";
    }

    // Функция вычисления общей калорийности продукта
    int calculateTotalCalories() {
        return (caloriePer100g * weight) / 100;
    }
};

int main() {
    setlocale(LC_ALL, "rus");

    vector<Product> products; // Вектор для хранения объектов класса Product

    // Ввод значений полей каждого объекта
    char addMore;
    do {
        int calorie, weight;
        cout << "Введите калорийность продукта на 100 г: ";
        cin >> calorie;
        cout << "Введите вес продукта в граммах: ";
        cin >> weight;

        // Создание объекта класса Product и добавление его в вектор
        products.push_back(Product(calorie, weight));

        cout << "Хотите добавить еще один продукт? (y/n): ";
        cin >> addMore;
    } while (addMore == 'y' || addMore == 'Y');

    // Вывод информации о продуктах
    cout << "Информация о продуктах:\n";
    for (auto& product : products) {
        cout << product.getInfo() << endl;
    }

    // Вычисление и вывод общей калорийности продуктов
    int totalCalories = 0;
    for (auto& product : products) {
        totalCalories += product.calculateTotalCalories();
    }
    cout << "Общая калорийность продуктов: " << totalCalories << " ккал" << endl;

    return 0;
}
