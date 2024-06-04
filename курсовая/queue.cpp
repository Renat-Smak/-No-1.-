#include "queue.h"
#include <iostream>
#include <fstream>

queue<pair<string, string>> queue1; // для типов услуг 1, 3, 5
queue<pair<string, string>> queue2; // для типов услуг 2, 4
queue<pair<string, string>> queue3; // для типов услуг 6, 8
queue<pair<string, string>> queue4; // для типов услуг 7, 9

void initializeQueues() {
    // Initialization code if needed in future
}

void printQueue(queue<pair<string, string>>& q, const string& windowName, ofstream& outFile) {
    cout << "Содержимое очереди для " << windowName << ":\n";
    outFile << "Содержимое очереди для " << windowName << ":\n";
    while (!q.empty()) {
        cout << q.front().second << endl;
        outFile << q.front().second << endl;
        q.pop();
    }
}
