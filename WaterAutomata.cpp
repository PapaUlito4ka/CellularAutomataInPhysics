#include "WaterAutomata.hpp"

WaterAutomata::WaterAutomata(Grid& grid) : grid(grid) {}

void WaterAutomata::Move() {
    Grid grid_tmp = grid;
    for (int i = 0; i < grid.GridSize().y; i++) {
        for (int j = 0; j < grid.GridSize().x; j++) {
            if (grid[i][j].type == CellType::WATER && i != grid.GridSize().y - 1) {
                grid_tmp[i][j].type = CellType::AIR;
                grid_tmp[i+1][j].type = CellType::WATER;
            }
        }
    }
    grid = grid_tmp;
}

void WaterAutomata::Tick() {
    Move();
}

void WaterAutomata::Render(sf::RenderWindow& l_window) {
    // Leave it blank for now
}
