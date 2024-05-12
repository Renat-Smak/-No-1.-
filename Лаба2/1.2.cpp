#include <iostream>
#include <fstream>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    // Открываем файл для чтения
    ifstream file;
    file.open("C:\\Users\\User\\Desktop\\Ренат\\2\\a.txt");

    if (!file) {
        cerr << "Ошибка открытия файла." << endl;
        return 1;
    }

    double number;
    int zeroCount = 0;
    double product = 1.0;

    // Читаем числа из файла и подсчитываем количество нулевых элементов
    // Вычисляем произведение элементов меньше 1 и больших 0
    while (file >> number) {
        if (number == 0) {
            zeroCount++;
        }
        else if (number < 1 && number > 0) {
            product *= number;
        }
    }

    // Закрываем файл
    file.close();

    // Выводим результат
    cout << "Количество нулевых элементов: " << zeroCount << endl;
    cout << "Произведение элементов меньше 1 и больших 0: " << product << endl;

    return 0;
}

