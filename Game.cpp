#include "Game.hpp"

Game::Game() :
    window("Physics", sf::Vector2u(800, 800)),
    grid(sf::Vector2<int>(800, 800)),
    water_automata(grid)
{
    srand((unsigned int)time(0));
    clock.restart();
    elapsed = 0.0f;
    speed = 60;
}

Game::~Game() {}

void Game::Update() {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Delete)) {
        grid.GridClear();
    }
    window.Update();
    float timestep = 1.0f / GetSpeed();
    if (elapsed >= timestep) {
        water_automata.Tick();
        elapsed -= timestep;
    }
}

void Game::HandleInput() {
    if (window.IsMousePressed()) {
        grid.DrawMouse(window.GetRenderWindow(), window.MouseButton());
    }
}

int Game::GetSpeed() {
    return speed;
}

void Game::Render() {
    window.BeginDraw();
    grid.Render(window.GetRenderWindow());
    window.EndDraw();
}

sf::Time Game::GetElapsed() {
    return clock.getElapsedTime();
}

void Game::RestartClock() {
    elapsed += clock.restart().asSeconds();
}

Window* Game::GetWindow() {
    return &window;
}

