#include <iostream>
#include <stack>

using namespace std;

// Функция для вычисления произведения нечетных значений элементов стека
int calculateOddProduct(stack<int> s) {
    int product = 1;
    while (!s.empty()) {
        int current = s.top();
        if (current % 2 != 0) {
            product *= current;
        }
        s.pop();
    }
    return product;
}

// Функция для просмотра данных стека
void viewStack(stack<int> s) {
    cout << "стек: ";
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main() {
    setlocale(LC_ALL, "RU");
    stack<int> myStack;
    int count;

    // Запрос количества элементов стека
    cout << "Введите количество элементов: ";
    cin >> count;

    // Ввод элементов стека
    cout << "Введите элементы стека:\n";
    for (int i = 0; i < count; ++i) {
        int element;
        cin >> element;
        myStack.push(element);
    }

    // Вычисление произведения нечетных значений элементов стека
    int oddProduct = calculateOddProduct(myStack);

    // Просмотр данных стека
    viewStack(myStack);

    // Вывод результата
    cout << "Результат перемножения: " << oddProduct << endl;

    return 0;
}

