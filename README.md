## A* Pathfinding Visualizer
A real-time, interactive visualization of the A* search algorithm built with C++20 and SFML 3. This version is a lightweight, high-performance implementation focused solely on the grid visualization without a text-based UI.

## Project Structure
The project is organized into a clean directory structure separating definitions from implementation:
```
AStarPanel/
├── CMakeLists.txt         # Build configuration for SFML 3
├── include/               # Header files (.h)
│   ├── Application.h      # Window and loop management
│   ├── AStar.h            # Algorithm state and priority queue
│   ├── Grid.h             # 2D node container and indexing
│   └── Node.h             # Node data (costs and coordinates)
├── src/                   # Source files (.cpp)
│   ├── main.cpp           # CLI argument parsing and entry point
│   ├── Application.cpp    # Event handling and render loop
│   ├── AStar.cpp          # Step-by-step pathfinding logic
│   └── Grid.cpp           # Visualization and grid manipulation
```

## Features
* CLI Parameters: Configure grid dimensions and cell size via command-line arguments.

* Real-time Interaction: Draw obstacles or move start/end points while the app is running.

* 4-Way Movement: Pathfinding is optimized for Manhattan distance heuristics.

* No Dependencies on External Assets: Completely standalone; does not require font files or images.

## Controls
Control the visualizer using your keyboard and mouse:
 
Keyboard

* 1: Switch to Wall tool.

* 2: Switch to Start Node tool.

* 3: Switch to End Node tool.

* Enter: Start simulation.

* C: Clear grid and reset algorithm.

Mouse

* Left Click: Place wall/start/end (based on selected tool).

* Right Click: Erase walls (eraser tool).

## Build and Run
Prerequisites

* C++20 Compiler.

* CMake 3.20+.

* SFML 3 installed on your system.

Compilation

```Bash
mkdir build && cd build
cmake ..
cmake --build .
```
Execution

Run the program with custom parameters:

```Bash
# ./AStarPanel [height] [width] [cellSize]
./AStarPanel 30 50 15
```