#pragma once

#include <SFML/Graphics.hpp>
#include "WaterAutomata.hpp"
#include "DiffusionAutomata.hpp"
#include <vector>

class World {
public:
    
    World(sf::Vector2u l_windowSize);
    
    ~World();
    
    int GetCellSize();
    void Update();
    void Render(sf::RenderWindow& l_window);
    
private:
    sf::Vector2u m_windowSize;
    int m_cellSize;
};
