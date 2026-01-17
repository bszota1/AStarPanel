#include "Grid.h"


// Initializes Grid object with user given arguments, and initializes deafult Nodes

Grid::Grid(const uint16_t height, const uint16_t width, const float cellSize):
    height {height},
    width {width},
    cellSize {cellSize},
    startNode {nullptr},
    endNode {nullptr}{

    nodes.resize(height, std::vector<Node>(width));
    for (uint16_t y = 0; y < height; ++y) {
        for (uint16_t x = 0; x < width; ++x) {
            nodes[y][x] = Node(x, y);
        }
    }
}

// Uses SFML to draw rectangle with different colours depending on their type

void Grid::draw(sf::RenderWindow& window) {
    sf::RectangleShape rectangle(sf::Vector2f(cellSize - 1.0f, cellSize - 1.0f));
    for (uint16_t y = 0; y < height; ++y) {
        for (uint16_t x = 0; x < width; ++x) {
            Node& currentNode = nodes[y][x];
            if (&currentNode == startNode) {
                rectangle.setFillColor(sf::Color::Green);
            }
            else if (&currentNode == endNode) {
                rectangle.setFillColor(sf::Color::Red);
            }
            else if (currentNode.isPath) {
                rectangle.setFillColor(sf::Color::Yellow);
            }
            else if (currentNode.isVisited) {
                rectangle.setFillColor(sf::Color::Cyan);
            }
            else if (currentNode.isWall) {
                rectangle.setFillColor(sf::Color::Black);
            }
            else {
                rectangle.setFillColor(sf::Color::White);
            }

            float posX = x * cellSize;
            float posY = y * cellSize;

            rectangle.setPosition({posX, posY});

            window.draw(rectangle);
        }
    }
}

// Checks if the mouse is clicikg inside of the window and changing Node type to wall

void Grid::setWall(int mouseX, int mouseY) {
    if (mouseX < 0 || mouseY < 0) return;

    const auto indexX = static_cast<uint16_t>(mouseX / cellSize);
    const auto indexY = static_cast<uint16_t>(mouseY / cellSize);

    if (indexX < width && indexY < height) {
        Node& targetNode = nodes[indexY][indexX];
        if (&targetNode != startNode && &targetNode != endNode) {
            targetNode.isWall = true;
        }
    }
}

// Checks if the mouse is clicikg inside of the window and changing Node isWall flag to false

void Grid::removeWall(int mouseX, int mouseY) {
    if (mouseX < 0 || mouseY < 0) return;

    const auto indexX = static_cast<uint16_t>(mouseX / cellSize);
    const auto indexY = static_cast<uint16_t>(mouseY / cellSize);

    if (indexX < width && indexY < height) {
        Node& targetNode = nodes[indexY][indexX];
        if (&targetNode != startNode && &targetNode != endNode) {
            targetNode.isWall = false;
        }
    }
}

// Checks if the mouse is clicikg inside of the window and changing Node type to start


void Grid::setStart(int mouseX , int mouseY) {

    if (mouseX < 0 || mouseY < 0) return;

    const auto indexX = static_cast<uint16_t>(mouseX / cellSize);
    const auto indexY = static_cast<uint16_t>(mouseY / cellSize);

    if (indexX < width && indexY < height ) {
        Node* targetNode = &nodes[indexY][indexX];

        if (targetNode == endNode) return;
        targetNode->isWall = false;
        startNode = targetNode;
    }

}

// Checks if the mouse is clicikg inside of the window and changing Node type to finish


void Grid::setEnd(int mouseX , int mouseY) {

    if (mouseX < 0 || mouseY < 0) return;

    const auto indexX = static_cast<uint16_t>(mouseX / cellSize);
    const auto indexY = static_cast<uint16_t>(mouseY / cellSize);

    if (indexX < width && indexY < height ) {
        Node* targetNode = &nodes[indexY][indexX];

        if (targetNode == startNode) return;
        targetNode->isWall = false;
        endNode = targetNode;
    }
}

// Returns all available Nodes from current Node

std::vector<Node *> Grid::getNeighbours(Node *node) {
    std::vector<Node *> neighbours;
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};

    for (int i = 0; i < 4; ++i) {

        int nx = static_cast<int>(node->x) + dx[i];
        int ny = static_cast<int>(node->y) + dy[i];

        if (nx >= 0 && nx < static_cast<int>(width) && ny >= 0 && ny < static_cast<int>(height)) {
            Node& neighbour = nodes[ny][nx];
            if (!neighbour.isWall) {
                neighbours.push_back(&neighbour);
            }
        }
    }
    return neighbours;
}

// Resets all Nodes (for more info look into Node.h)

void Grid::reset() {
    for (uint16_t y = 0; y < height; ++y) {
        for (uint16_t x = 0; x < width; ++x) {
            nodes[y][x].resetNode();
        }
    }
}

// Clears all Nodes (for more info look into Node.h)

void Grid::clear() {
    for (uint16_t y = 0; y < height; ++y) {
        for (uint16_t x = 0; x < width; ++x) {
            nodes[y][x].clearNode();
        }
    }
    startNode = nullptr;
    endNode = nullptr;
}