#include <iostream>
#include <cassert>

struct Node {
    int data;
    Node* nextNode;

    inline Node(int value) : data(value), nextNode(nullptr) {}
};

class Queue {
    Node* firstNode;
    Node* lastNode;

    inline Queue() : firstNode(nullptr), lastNode(nullptr) {}

    void enqueue(int value);
    int dequeue();
    inline bool isEmpty() const {
        return (firstNode == nullptr);
    }
    ~Queue();

private:
    void clear();
};