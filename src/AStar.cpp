#include <cmath>
#include "../include/AStar.h"

//  This function returns value of Manhattan heuristic of two Nodes

float AStar::calculateHeuristic(Node *a, Node *b) {
    const int dx = static_cast<int>(a->x) - static_cast<int>(b->x);
    const int dy = static_cast<int>(a->y) - static_cast<int>(b->y);

    return static_cast<float>(std::abs(dx) + std::abs(dy));
}

// This fuction backtracks the path that lead to the end
// When doing this it changes Node flag (isPath)

void AStar::reconstructPath(Node *endNode) {
    if (!endNode) return;

    Node* currentNode = endNode;
    while (currentNode->parent != nullptr) {
        currentNode -> isPath = true;
        currentNode = currentNode->parent;
    }
}

// This function compares diofferent Node taking options and chooses this with lowes cost to get to

bool AStar::update(Grid &grid) {
    if (!initialized) {
        grid.reset();
        startNode = grid.getStart();
        endNode = grid.getEnd();

        if (!startNode || !endNode) return false;

        openSet = std::priority_queue<Node*, std::vector<Node*>, NodeComparator>();

        startNode->gCost = 0.0f;
        startNode->hCost = calculateHeuristic(startNode, endNode);
        startNode->updateCost();

        openSet.push(startNode);
        startNode->isEnqueued = true;
        initialized = true;
        finished = false;
        return false;
    }

    if (!openSet.empty() && !finished) {
        Node* currentNode = openSet.top();
        openSet.pop();

        if (currentNode->isVisited) return false;
        currentNode->isVisited = true;

        if (currentNode == endNode) {
            reconstructPath(endNode);
            finished = true;
            return true;
        }

        auto neighbours = grid.getNeighbours(currentNode);
        for (auto &neighbour : neighbours) {
            float tentativeGCost = currentNode->gCost + 1.0f;

            if (!neighbour->isVisited && (neighbour->gCost == 0.0f || tentativeGCost < neighbour->gCost)) {
                neighbour->parent = currentNode;
                neighbour->gCost = tentativeGCost;
                neighbour->hCost = calculateHeuristic(neighbour, endNode);
                neighbour->updateCost();

                if (!neighbour->isEnqueued) {
                    openSet.push(neighbour);
                    neighbour->isEnqueued = true;
                }
            }
        }
    }
    return finished;
}


