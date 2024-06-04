#ifndef QUEUE_H
#define QUEUE_H

#include <queue>
#include <string>

using namespace std;

// Declare the queues for each window
extern queue<pair<string, string>> queue1; // для типов услуг 1, 3, 5
extern queue<pair<string, string>> queue2; // для типов услуг 2, 4
extern queue<pair<string, string>> queue3; // для типов услуг 6, 8
extern queue<pair<string, string>> queue4; // для типов услуг 7, 9

// Function to initialize the queues
void initializeQueues();

// Function to print and write the queue content
void printQueue(queue<pair<string, string>>& q, const string& windowName, ofstream& outFile);

#endif // QUEUE_H