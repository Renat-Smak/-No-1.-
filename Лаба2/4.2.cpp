#include <iostream>
#include <fstream>
#include <climits>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    ifstream file;
    file.open("C:\\Users\\User\\Desktop\\Ренат\\2\\b.txt");


    if (!file) {
        cerr << "Ошибка открытия файла." << endl;
        return 1;
    }

    int number;
    int position = 0;
    int maxNegative = INT_MIN;

    while (file >> number) {
        position++;
        if (position % 2 == 0 && number < 0 && number > maxNegative) {
            maxNegative = number;
        }
    }

    if (maxNegative == INT_MIN) {
        cout << "В файле нет отрицательных чисел на чётных позициях." << endl;
    }
    else {
        cout << "Наибольший отрицательный компонент файла среди компонент файла на чётных позициях: " << maxNegative << endl;
    }

    file.close();

    return 0;
}

