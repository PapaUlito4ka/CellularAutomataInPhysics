#include "Grid.hpp"

Grid::Grid() {}

Grid::Grid(sf::Vector2<int> gridSize) {
    cellSize = 10;
    this->gridSize = sf::Vector2<int>(gridSize.x / cellSize, gridSize.y / cellSize);
    grid = std::vector<std::vector<Cell>>(this->gridSize.y, std::vector<Cell>(this->gridSize.x));
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            grid[i][j].coords = { j * cellSize, i * cellSize };
            grid[i][j].type = CellType::AIR;
        }
    }
    cellTexture.setSize(sf::Vector2<float>(cellSize, cellSize));
}

Grid::~Grid() {}

sf::Vector2<int> Grid::GridSize() {
    return gridSize;
}

void Grid::Update() {
    
}

void Grid::DrawMouse(sf::RenderWindow& window, sf::Mouse::Button button) {
    int x = sf::Mouse::getPosition(window).x;
    int y = sf::Mouse::getPosition(window).y;
    if (button == sf::Mouse::Right) {
        grid[y / cellSize][x / cellSize].type = CellType::WATER;
    }
    if (button == sf::Mouse::Left) {
        grid[y / cellSize][x / cellSize].type = CellType::GROUND;
    }
}

void Grid::Render(sf::RenderWindow& window) {
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            
            if (grid[i][j].type == CellType::AIR) {
                cellTexture.setFillColor(sf::Color::White);
            }
            
            if (grid[i][j].type == CellType::WATER) {
                cellTexture.setFillColor(sf::Color::Blue);
            }
            
            if (grid[i][j].type == CellType::GROUND) {
                cellTexture.setFillColor(sf::Color::Black);
            }
            
            cellTexture.setPosition(grid[i][j].coords.x, grid[i][j].coords.y);
            window.draw(cellTexture);
            
        }
    }
}

std::vector<Cell>& Grid::operator[] (int idx) {
    return grid[idx];
}
