#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

enum class CellType {
    NONE,
    AIR,
    WATER,
    GROUND,
    BOUNDS
};

struct Cell {
    
    Cell();
    
    void setAir();
    void setWater();
    void setGround();
    void setBounds();
    
    sf::Vector2<int> coords;
    int cnt;
    CellType type;
    int pressure;
};

using Matrix = std::vector<std::vector<Cell>>;

struct Grid {
    Grid();
    Grid(sf::Vector2<int> gridSize);

    ~Grid();

    sf::Vector2<int> GridSize();
    void DrawMouse(sf::RenderWindow&, sf::Mouse::Button);
    bool isMouseInScreen(int, int);
    void GridClear();
    void Update();
    void Render(sf::RenderWindow&);

    std::vector<Cell>& operator[](int);

private:
    Matrix grid;
    sf::Vector2<int> gridSize;
    sf::RectangleShape cellTexture;
    int cellSize;
};


