#pragma once

#include <SFML/Graphics.hpp>
#include "Grid.hpp"

// Application of water simulation

class WaterAutomata {
public:
    WaterAutomata();
    WaterAutomata (Grid&);

    // Required methods
    void Move(); // Movement method.
    void Tick(); // Update method.
    void Render(sf::RenderWindow& l_window);
    void WaterFall(int i, int j, Grid& grid_tmp, bool& wf);
    void Spread(int i, int j, Grid& grid_tmp);
    void DoubleSpread(int, int, Grid&);
    void LeftSpread(int, int j, Grid& grid_tmp);
    void RightSpread(int, int j, Grid& grid_tmp);
    // Helper metods
    // . . .

private:
    // To do: neccessary fields
    // . . .
    Grid& grid;
};
