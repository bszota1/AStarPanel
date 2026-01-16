#include "../include/Application.h"
#include <optional>

Application::Application():
    grid(30,40,20.0f),
    currentTool(Tool::Wall),
    isSimulating(false){
    uint16_t screenWidth = 40 * 20;
    uint16_t screenHeight = 30 * 20;

    window.create(sf::VideoMode({screenWidth,screenHeight}),"A* Visualizer");
    window.setFramerateLimit(60);
}

void Application::run() {
    while (window.isOpen()) {
        processEvents();
        update();
        render();
    }
}

void Application::processEvents() {
    while (const std::optional event = window.pollEvent()) {

        if (event->is<sf::Event::Closed>()) {
            window.close();
        }

        if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {

            if (keyPressed->code == sf::Keyboard::Key::Num1) currentTool = Tool::Wall;
            if (keyPressed->code == sf::Keyboard::Key::Num2) currentTool = Tool::Start;
            if (keyPressed->code == sf::Keyboard::Key::Num3) currentTool = Tool::End;

            if (keyPressed->code == sf::Keyboard::Key::Enter) {
                isSimulating = true;
            }

            if (keyPressed->code == sf::Keyboard::Key::C) {
                isSimulating = false;
                grid.clear();
                astar.reset();
            }
        }
    }

    if (!isSimulating) {
        const sf::Vector2i mousePos = sf::Mouse::getPosition(window);

        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
            if (currentTool == Tool::Wall)  grid.setWall(mousePos.x, mousePos.y);
            if (currentTool == Tool::Start) grid.setStart(mousePos.x, mousePos.y);
            if (currentTool == Tool::End)   grid.setEnd(mousePos.x, mousePos.y);
        }


        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Right)) {
            grid.removeWall(mousePos.x, mousePos.y);
        }
    }
}

void Application::update() {
    if (isSimulating) {
        if (astar.update(grid)) {
            isSimulating = false;
        }
    }
}

void Application::render() {
    window.clear(sf::Color(50, 50, 50));
    grid.draw(window);
    window.display();
}
