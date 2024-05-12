#include <iostream>
#include <fstream>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    // Открываем файл для чтения
    ifstream file;
    file.open("C:\\Users\\renat\\Desktop\\Смак англ\\2 — копия\\a.txt");
    if (!file) {
        cerr << "Ошибка открытия файла." << endl;
        return 1;
    }

    double number;
    int positiveCount = 0;
    int negativeCount = 0;

    // Читаем числа из файла и подсчитываем количество положительных и отрицательных
    while (file >> number) {
        if (number > 0) {
            positiveCount++;
        }
        else if (number < 0) {
            negativeCount++;
        }
    }

    // Закрываем файл
    file.close();

    // Выводим результат
    cout << "Количество положительных чисел: " << positiveCount << endl;
    cout << "Количество отрицательных чисел: " << negativeCount << endl;

    return 0;
}

