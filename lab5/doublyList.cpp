#include <iostream>
#include <cassert>
#include "doubleList.h"

    Node* DoubleLinkedList::insertAfter(Node* node, int value) {
        Node* newNode = new Node(value);
        newNode->prevNode = node;
        newNode->nextNode = node->nextNode;

        if (node == nullptr) {
            Node* newNode = new Node(value);
            firstNode = newNode;
            lastNode = newNode;
            return newNode;
        }

        

        if (node->nextNode != nullptr) {
            node->nextNode->prevNode = newNode;
        } else {
            lastNode = newNode;
        }

        node->nextNode = newNode;
        return newNode;
    }

    Node* DoubleLinkedList::insertBefore(Node* node, int value) {
        if (node == nullptr) {
            Node* newNode = new Node(value);
            firstNode = newNode;
            lastNode = newNode;
            return newNode;
        }

        Node* newNode = new Node(value);
        newNode->nextNode = node;
        newNode->prevNode = node->prevNode;

        if (node->prevNode != nullptr) {
            node->prevNode->nextNode = newNode;
        } else {
            firstNode = newNode;
        }

        node->prevNode = newNode;
        return newNode;
    }

    Node* DoubleLinkedList::find(int value) {
        Node* current = firstNode;
        while (current != nullptr) {
            if (current->data == value) {
                return current;
            }
            current = current->nextNode;
        }
        return nullptr;
    }

    void DoubleLinkedList::remove(Node* node) {
        if (node == nullptr) {
            return;
        }

        if (node->prevNode != nullptr) {
            node->prevNode->nextNode = node->nextNode;
        } else {
            firstNode = node->nextNode;
        }

        if (node->nextNode != nullptr) {
            node->nextNode->prevNode = node->prevNode;
        } else {
            lastNode = node->prevNode;
        }

        delete node;
    }

    void DoubleLinkedList::assertNoCycles() {
        Node* current = firstNode;
        while (current != nullptr) {
            if ((current->nextNode != nullptr && current->nextNode->prevNode != current) ||
                (current->prevNode != nullptr && current->prevNode->nextNode != current)) {
                assert(false && "Cycle detected in the linked list!");
            }
            current = current->nextNode;
        }
    }

    DoubleLinkedList::~DoubleLinkedList() {
        deleteList();
    }


    void DoubleLinkedList::deleteList() {
        Node* current = firstNode;
        Node* next = nullptr;

        while (current != nullptr) {
            next = current->nextNode;
            delete current;
            current = next;
        }

        firstNode = nullptr;
        lastNode = nullptr;
    }