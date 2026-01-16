#pragma once
#include <cstdint>

struct Node {
    uint32_t x;
    uint32_t y;

    float gCost;
    float hCost;
    float fCost;

    bool isWall = false;
    bool isVisited = false;
    bool isEnqueued = false;
    bool isPath = false;

    Node* parent = nullptr;

    void updateCost() { fCost = gCost + hCost; }
    Node(const uint32_t x = 0, const uint32_t y = 0):
        x {x},
        y {y},
        gCost {0.0f},
        hCost {0.0f},
        fCost {0.0f}
    {}
    Node(const uint32_t x, const uint32_t y, const float gCost, const float hCost, const float fCost):
        x {x},
        y {y},
        gCost {gCost},
        hCost {hCost},
        fCost {fCost}
    {}

    bool operator>(const Node& other) const {
        return fCost > other.fCost;
    }

    void resetNode() {
        gCost = 0.0f;
        hCost = 0.0f;
        fCost = 0.0f;
        isVisited = false;
        isEnqueued = false;
        isPath = false;
        parent = nullptr;
    }

    void clearNode() {
        resetNode();
        isWall = false;
    }
};
