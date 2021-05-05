#pragma once

#include <SFML/Graphics.hpp>
#include "WaterAutomata.hpp"
#include "DiffusionAutomata.cpp"
#include "World.hpp"
#include "Window.hpp"

class Game {
public:
    
    Game();
    ~Game();
    
    void HandleInput();
    void Update();
    void Render();
    
    Window* GetWindow();
    sf::Time GetElapsed();
    
    void RestartClock();
    
private:
    sf::Clock m_clock;
    float m_elapsed;
    
    Window m_window;
    World m_world;
    WaterAutomata water_automata;
    DiffusionAutomata diffusion_automata;
};



