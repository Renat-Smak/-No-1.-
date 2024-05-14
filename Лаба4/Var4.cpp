#include <iostream>
#include <cstring>

// Базовый класс "Элемент"
class Element {
protected:
    char* name; // Имя элемента
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
    virtual ~Element() {
        delete[] name;
    }

    // Метод, задающий имя элемента
    void setName(const char* newName) {
        delete[] name;
        name = new char[strlen(newName) + 1];
        strcpy(name, newName);
    }
};

// Производный класс "Комбинационный"
class Combinational : public Element {
private:
    bool* inputValues; // Значения входов

public:
    // Конструктор
    Combinational(const char* name, int inputs) : Element(name, inputs, 1) {
        inputValues = new bool[inputs];
    }

    // Конструктор копирования
    Combinational(const Combinational& other) : Element(other.name, other.inputs, 1) {
        inputValues = new bool[inputs];
        memcpy(inputValues, other.inputValues, inputs * sizeof(bool));
    }

    // Деструктор
    ~Combinational() {
        delete[] inputValues;
    }

    // Метод, задающий значение на входах экземпляра класса
    void setInputValues(const bool* values) {
        memcpy(inputValues, values, inputs * sizeof(bool));
    }

    // Метод, позволяющий опрашивать состояние отдельного входа экземпляра класса
    bool getInputValue(int index) const {
        return inputValues[index];
    }

    // Метод, вычисляющий значение выхода
    virtual bool computeOutput() const {
        // Пример вычисления: логическое ИЛИ всех входов
        bool result = false;
        for (int i = 0; i < inputs; ++i) {
            result |= inputValues[i];
        }
        return result;
    }
};

// Производный класс "Память"
class Memory : public Element {
private:
    static const int MAX_INPUTS = 10; // Максимальное количество входов
    bool inputValues[MAX_INPUTS]; // Массив значений входов
    bool output; // Состояние на прямом выходе триггера
    bool invertedOutput; // Состояние на инверсном выходе триггера

public:
    // Конструктор
    Memory() : Element("Memory", MAX_INPUTS, 2) {
        reset();
    }

    // Конструктор копирования
    Memory(const Memory& other) : Element(other.name, MAX_INPUTS, 2) {
        memcpy(inputValues, other.inputValues, MAX_INPUTS * sizeof(bool));
        output = other.output;
        invertedOutput = other.invertedOutput;
    }

    // Деструктор
    ~Memory() {}

    // Метод, задающий значение на входах экземпляра класса
    void setInputValues(const bool* values) {
        memcpy(inputValues, values, MAX_INPUTS * sizeof(bool));
    }

    // Методы, позволяющие опрашивать состояния отдельного входа экземпляра класса
    bool getInputValue(int index) const {
        return inputValues[index];
    }

    // Метод, вычисляющий состояние экземпляра класса
    virtual void computeState() {
        // Пример вычисления: простой триггер
        if (inputValues[0]) { // Если первый вход установлен в true
            output = true;
            invertedOutput = false;
        } else {
            output = false;
            invertedOutput = true;
        }
    }

    // Метод, переопределяющий операцию ==
    bool operator==(const Memory& other) const {
        return (output == other.output && invertedOutput == other.invertedOutput);
    }

    // Метод сброса экземпляра класса
    void reset() {
        memset(inputValues, 0, MAX_INPUTS * sizeof(bool));
        output = false;
        invertedOutput = true;
    }
};

// Класс "Регистр", использующий класс "Память"
class Register {
private:
    static const int SIZE = 4; // Размерность регистра
    Memory memoryCells[SIZE]; // Статический массив типа "Память"
    bool resetState; // Состояние входа "Сброс"
    bool setState; // Состояние входа "Установка"

public:
    // Конструктор
    Register() : resetState(false), setState(false) {}

    // Метод, задающий значение на входах экземпляра класса
    void setInputValues(int index, const bool* values) {
        if (index >= 0 && index < SIZE) {
            memoryCells[index].setInputValues(values);
        }
    }

    // Метод, позволяющий опрашивать состояние отдельного выхода экземпляра класса
    bool getOutputState(int index) const {
        if (index >= 0 && index < SIZE) {
            return memoryCells[index].getInputValue(0); // Пример: возвращаем состояние первого входа
        }
        return false;
    }

    // Метод, вычисляющий значение нового состояния экземпляра класса
    void computeNewState() {
        for (int i = 0; i < SIZE; ++i) {
            memoryCells[i].computeState();
        }
    }
};

// Функция для демонстрации работы классов
void demonstrateClasses() {
    // Создание и использование объектов классов
    Combinational combElement("CombElement", 3);
    bool inputValues[] = {true, false, true};
    combElement.setInputValues(inputValues);
    std::cout << "Output of Combinational Element: " << combElement.computeOutput() << std::endl;

    Memory memoryElement;
    memoryElement.setInputValues(inputValues);
    memoryElement.computeState();
    std::cout << "Output of Memory Element: " << memoryElement.getInputValue(0) << std::endl;

    Register reg;
    reg.setInputValues(0, inputValues);
    reg.computeNewState();
    std::cout << "Output State of Register Cell 0: " << reg.getOutputState(0) << std::endl;
}

int main() {
    demonstrateClasses();
    return 0;
}