#include <cstring>
#include <iostream>

class Element {
private:
    char* name; // Указатель на строку символов для имени элемента
    int inputs; // Количество входов элемента
    int outputs; // Количество выходов элемента

public:
    // Конструктор класса
    Element(const char* elementName, int elementInputs, int elementOutputs) {
        name = new char[strlen(elementName) + 1];
        strcpy(name, elementName);
        inputs = elementInputs;
        outputs = elementOutputs;
    }

    // Деструктор класса
    ~Element() {
        delete[] name;
    }

    // Метод, задающий имя элемента
    void setName(const char* newName) {
        delete[] name; // Освобождаем старую память
        name = new char[strlen(newName) + 1]; // Выделяем память под новое имя
        strcpy(name, newName); // Копируем новое имя в name
    }

    // Методы для доступа к полям (не требовались, но могут быть полезны)
    const char* getName() const { return name; }
    int getInputs() const { return inputs; }
    int getOutputs() const { return outputs; }
};

int main() {
    Element element("TestElement", 3, 1);
    element.setName("UpdatedElement");
    
    // Вывод информации об элементе для проверки
    std::cout << "Element Name: " << element.getName() << std::endl;
    std::cout << "Inputs: " << element.getInputs() << ", Outputs: " << element.getOutputs() << std::endl;

    return 0;
}