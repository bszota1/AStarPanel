#pragma once

#include "../include/Node.h"
#include <vector>
#include <SFML/Graphics.hpp>

using GridVector = std::vector<std::vector<Node>>;

class Grid {
private:
    GridVector nodes;
    uint16_t height;
    uint16_t width;
    float cellSize;
    Node* startNode;
    Node* endNode;
public:
    Grid(uint16_t height, uint16_t width, float cellSize);

    Node* getStart() const { return startNode; }
    Node* getEnd() const { return endNode; }

    void draw(sf::RenderWindow& window);
    void setWall(int mouseX , int mouseY);
    void removeWall(int mouseX, int mouseY);
    void setStart(int mouseX, int mouseY);
    void setEnd(int mouseX, int mouseY);

    std::vector<Node*> getNeighbours(Node* node);
    void reset();
    void clear();

};