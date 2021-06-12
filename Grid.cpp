#include "Grid.hpp"

Grid::Grid() {}

Grid::Grid(sf::Vector2<int> gridSize_) {
    cellSize = 10;
    gridSize = sf::Vector2<int>(gridSize_.x / cellSize, gridSize_.y / cellSize);
    grid = std::vector<std::vector<Cell>>(gridSize.y, std::vector<Cell>(gridSize.x));
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            grid[i][j].coords = { j * cellSize, i * cellSize };
            if (i == 0 || i == grid.size() - 1 ||
                j == 0 || j == grid[0].size() - 1)
                grid[i][j].setBounds();
            else grid[i][j].setAir();
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

bool Grid::isMouseInScreen(int x, int y) {
    if (x < 1 || x > GridSize().x * cellSize - 1 ||
        y < 1 || y > GridSize().y * cellSize - 1) return false;
    return true;
}

void Grid::DrawMouse(sf::RenderWindow& window, sf::Mouse::Button button) {
    int x = sf::Mouse::getPosition(window).x;
    int y = sf::Mouse::getPosition(window).y;
    if (!isMouseInScreen(x, y)) return;
    int a = y / cellSize;
    int b = x / cellSize;
    if (button == sf::Mouse::Right) {
        if(a > 1 && a < GridSize().y - 2 && b > 1 && b < GridSize().x - 2)
        {
            int cnt = 1;
            for (int i = -2; i < 3; i++) {
                for (int j = 0; j < cnt; j++) {
                    if (grid[a+i][b+j].type != CellType::GROUND &&
                        grid[a+i][b+j].type != CellType::BOUNDS) {
                        grid[a+i][b+j].setWater();
                    }
                    if (grid[a+i][b-j].type != CellType::GROUND &&
                        grid[a+i][b-j].type != CellType::BOUNDS) {
                        grid[a+i][b-j].setWater();
                    }
                }
                i < 0 ? cnt++ : cnt--;
            }
        }

    }
    if (button == sf::Mouse::Left) {
        if (grid[a][b].type != CellType::BOUNDS)
            grid[a][b].setGround();
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::LControl))
    {
        for (int i = -1; i < 2; i++) {
            for (int j = -1; j < 2; j++) {
                if (grid[a+i][b+j].type != CellType::BOUNDS)
                    grid[a+i][b+j].setAir();
            }
        }
    }
}

void Grid::GridClear()
{
    for(int i=0;i<GridSize().y;i++)
        for(int j=0;j<GridSize().x;j++)
        {
            if (grid[i][j].type != CellType::BOUNDS)
                grid[i][j].setAir();
        }
}



void Grid::Render(sf::RenderWindow& window) {
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {

            if (grid[i][j].type == CellType::AIR) {
                cellTexture.setFillColor(sf::Color::White);
            }

            if (grid[i][j].type == CellType::WATER) {
                cellTexture.setFillColor(sf::Color(0,0,255));
                cellTexture.setOutlineThickness(-4*(100-grid[i][j].cnt)/100.0);
            }

            if (grid[i][j].type == CellType::GROUND) {
                cellTexture.setFillColor(sf::Color::Black);
                cellTexture.setOutlineThickness(0);
            }
            
            if (grid[i][j].type == CellType::BOUNDS) {
                cellTexture.setFillColor(sf::Color::Black);
                cellTexture.setOutlineThickness(0);
            }

            cellTexture.setPosition(grid[i][j].coords.x, grid[i][j].coords.y);
            window.draw(cellTexture);

        }
    }
}

std::vector<Cell>& Grid::operator[] (int idx) {
    return grid[idx];
}

Cell::Cell() : coords(), cnt(0), type(CellType::AIR), pressure(0) {}

void Cell::setWater() {
    type = CellType::WATER;
    cnt = 100;
}

void Cell::setGround() {
    type = CellType::GROUND;
    cnt = 101;
}

void Cell::setAir() {
    type = CellType::AIR;
    cnt = 0;
}

void Cell::setBounds() {
    type = CellType::BOUNDS;
    cnt = 100000;
}
