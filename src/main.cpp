#include "../include/Application.h"
#include <iostream>
#include <string>


int main(int argc, char* argv[]) {
    uint16_t height = 30;
    uint16_t width = 40;
    float cellSize = 20.0f;

    if (argc == 4) {
        try {
            height = static_cast<uint16_t>(std::stoi(argv[1]));
            width = static_cast<uint16_t>(std::stoi(argv[2]));
            cellSize = std::stof(argv[3]);
        } catch (...) {
            std::cerr << "Wrong parameters!!!" << std::endl;
        }
    }

    Application app(height,width,cellSize);
    app.run();
    return 0;
}