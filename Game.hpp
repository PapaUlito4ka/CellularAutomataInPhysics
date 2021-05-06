#pragma once

#include <SFML/Graphics.hpp>
#include "WaterAutomata.hpp"
#include "Window.hpp"
#include "Grid.hpp"

class Game {
public:
    
    Game();
    ~Game();
    
    void HandleInput();
    void Update();
    void Render();
    int GetSpeed();
    
    Window* GetWindow();
    sf::Time GetElapsed();
    
    void RestartClock();
    
private:
    sf::Clock clock;
    float elapsed;
    int speed;
    
    Window window;
    Grid grid;
    WaterAutomata water_automata;
};



