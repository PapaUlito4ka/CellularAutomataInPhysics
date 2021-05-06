#include "WaterAutomata.hpp"

WaterAutomata::WaterAutomata(Grid& grid) : grid(grid) {}

void WaterAutomata::Move() {
    for (int i = 0; i < grid.GridSize().y; i++) {
        for (int j = 0; j < grid.GridSize().x; j++) {
            if (grid[i][j].type == CellType::WATER) {
                // Here goes water logic
            }
        }
    }
}

void WaterAutomata::Tick() {
    Move();
}

void WaterAutomata::Render(sf::RenderWindow& l_window) {
    // Leave it blank for now
}
