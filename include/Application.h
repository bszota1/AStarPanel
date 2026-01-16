#pragma once

#include "../include/AStar.h"

class Application {
private:
    sf::RenderWindow window;
    Grid grid;
    AStar astar;
    enum class Tool{Wall, Start, End} currentTool;
    bool isSimulating;

    void processEvents();
    void update();
    void render();

public:
    void run();
    Application();
};