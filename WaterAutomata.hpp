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
    int CalculateVerticalFlowValue(int remainingLiquid, Cell destination);
    void Simulate();
    // Helper metods
    // . . .

private:
    // To do: neccessary fields
    // . . .
    Grid& grid;
    const int minValue = 1;
    const int maxValue = 100;
    const int maxCompression = 25;
    const int minFlow = 1;
    const int maxFlow = 400;

};
