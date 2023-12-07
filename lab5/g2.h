#include <iostream>
#include <vector>
#include <unordered_map>

struct Node {
    int value;
    std::vector<Node*> neighbors;

    inline Node(int val) : value(val) {}
};

class Graph {
private:
    std::unordered_map<int, Node*> nodes;
public:
    void addNode(int value);
    bool addEdge(int fromValue, int toValue);
    int sumOfNeighbors(int nodeValue);
    ~Graph();
};