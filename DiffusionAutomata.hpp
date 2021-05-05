#pragma once

#include <SFML/Graphics.hpp>

// Application of diffusion simulation

class DiffusionAutomata {
public:
    
    // Required methods
    int GetSpeed();
    void Move(); // Movement method.
    void Tick(); // Update method.
    void Render(sf::RenderWindow& l_window);
    
    // Helper metods
    // . . .
    
private:
    // To do: neccessary methods
    // . . .
};
