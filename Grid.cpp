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
        grid[y / cellSize][x / cellSize].cnt=100;
        int a=y / cellSize, b=x / cellSize;
        if(a>1 && a<GridSize().y-2 && b>1 && b<GridSize().x-2)
        {
            grid[a-1][b-1].type = CellType::WATER;
            grid[a-1][b-1].cnt=100;
            grid[a-1][b].type = CellType::WATER;
            grid[a-1][b].cnt=100;
            grid[a-1][b+1].type = CellType::WATER;
            grid[a-1][b+1].cnt=100;
            grid[a][b+1].type = CellType::WATER;
            grid[a][b+1].cnt=100;
            grid[a+1][b+1].type = CellType::WATER;
            grid[a+1][b+1].cnt=100;
            grid[a+1][b].type = CellType::WATER;
            grid[a+1][b].cnt=100;
            grid[a+1][b-1].type = CellType::WATER;
            grid[a+1][b-1].cnt=100;
            grid[a][b-1].type = CellType::WATER;
            grid[a][b-1].cnt=100;
            grid[a-2][b].type = CellType::WATER;
            grid[a-2][b].cnt=100;
            grid[a][b+2].type = CellType::WATER;
            grid[a][b+2].cnt=100;
            grid[a+2][b].type = CellType::WATER;
            grid[a+2][b].cnt=100;
            grid[a][b-2].type = CellType::WATER;
            grid[a][b-2].cnt=100;
        }

    }
    if (button == sf::Mouse::Left) {
        grid[y / cellSize][x / cellSize].type = CellType::GROUND;
        grid[y / cellSize][x / cellSize].cnt=101;

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::LControl))
           {
                grid[y / cellSize][x / cellSize].type = CellType::AIR;
                grid[y / cellSize][x / cellSize].cnt=0;
                grid[y / cellSize+1][x / cellSize].type = CellType::AIR;
                grid[y / cellSize+1][x / cellSize].cnt=0;
                grid[y / cellSize+1][x / cellSize+1].type = CellType::AIR;
                grid[y / cellSize+1][x / cellSize+1].cnt=0;
                grid[y / cellSize][x / cellSize+1].type = CellType::AIR;
                grid[y / cellSize][x / cellSize+1].cnt=0;
           }
    }
}

void Grid::GridClear()
{

        for(int i=0;i<GridSize().y;i++)
            for(int j=0;j<GridSize().x;j++)
            {
                grid[i][j].type=CellType::AIR;
                grid[i][j].cnt=0;
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

            cellTexture.setPosition(grid[i][j].coords.x, grid[i][j].coords.y);
            window.draw(cellTexture);

        }
    }
}

std::vector<Cell>& Grid::operator[] (int idx) {
    return grid[idx];
}
