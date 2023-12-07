#include "graph.h"


    void Graph::addNode(int value) {
        Node* newNode = new Node(value);
        nodes[value] = newNode;
    }

    bool Graph::addEdge(int fromValue, int toValue) {
        auto fromNodePair = nodes.find(fromValue);
        auto toNodePair = nodes.find(toValue);
        
        if (fromNodePair == nodes.end() || toNodePair == nodes.end()) {
            std::cout << "Node not found!" << std::endl;
            return false;
        }

        Node* fromNode = fromNodePair->second;
        Node* toNode = toNodePair->second;

        fromNode->neighbors.push_back(toNode);
    }

    int Graph::sumOfNeighbors(int nodeValue) {
        if (nodes.find(nodeValue) == nodes.end()) {
            std::cout << "Node not found!" << std::endl;
            return -1;
        }

        int sum = 0;
        Node* currentNode = nodes[nodeValue];

        for (Node* neighbor : currentNode->neighbors) {
            sum += neighbor->value;
        }

        return sum;
    }

    Graph::~Graph() {
        for (auto& pair : nodes) {
            delete pair.second;
        }
    }