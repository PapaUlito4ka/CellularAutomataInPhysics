#pragma once

#include <SFML/Graphics.hpp>
#include "Grid.hpp"

// Application of water simulation

class WaterAutomata {
public:
    
    WaterAutomata (Grid&);
    
    // Required methods
    void Move(); // Movement method.
    void Tick(); // Update method.
    void Render(sf::RenderWindow& l_window);
    
    // Helper metods
    // . . .
    
private:
    // To do: neccessary fields
    // . . .
    Grid grid;
};
