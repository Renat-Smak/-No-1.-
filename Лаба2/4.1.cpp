#include <iostream>
#include <fstream>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    ifstream inputFile("C:\\Users\\User\\Desktop\\Ренат\\2\\1.txt");
    ofstream oddFile("C:\\Users\\User\\Desktop\\Ренат\\2\\nech.txt");
    ofstream evenFile("C:\\Users\\User\\Desktop\\Ренат\\2\\ch.txt");

    if (!inputFile || !oddFile || !evenFile) {
        cerr << "Ошибка открытия файлов." << endl;
        return 1;
    }

    int number;
    int position = 0;

    while (inputFile >> number) {
        if (position % 2 == 0) {
            evenFile << number << endl;
        }
        else {
            oddFile << number << endl;
        }
        position++;
    }

    inputFile.close();
    oddFile.close();
    evenFile.close();

    cout << "Данные успешно записаны в файлы." << endl;

    return 0;
}

