#pragma once

#include <queue>
#include "../include/Grid.h"

struct NodeComparator {
    bool operator()(const Node* a, const Node* b) const {
        return a->fCost > b->fCost;
    }
};

class AStar {
private:
    static float calculateHeuristic(Node* a ,Node* b);
    static void reconstructPath(Node* endNode);
    std::priority_queue<Node*, std::vector<Node*>, NodeComparator> openSet;
    bool initialized = false;
    bool finished = false;
    Node* startNode;
    Node* endNode;
public:
    bool update(Grid& grid);
};
