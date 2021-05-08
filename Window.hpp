#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

class Window {
public:
    Window();
    Window(const std::string& l_title, const sf::Vector2u& l_size);
    ~Window();
    void BeginDraw(); // Clear the window.
    void EndDraw(); // Display the changes.
    void Update();
    bool IsDone();
    bool IsFullscreen();
    bool IsMousePressed();
    sf::Mouse::Button MouseButton();
    sf::Event GetEvent();
    sf::Vector2u GetWindowSize();
    sf::RenderWindow& GetRenderWindow();
    void ToggleFullscreen();
    void Draw(sf::Drawable& l_drawable);
    
    
private:
    void Setup(const std::string& l_title,
     const sf::Vector2u& l_size);
    void Destroy();
    void Create();
    sf::RenderWindow m_window;
    sf::Vector2u m_windowSize;
    std::string m_windowTitle;
    bool m_isDone;
    bool isMousePressed;
    bool m_isFullscreen;
    sf::Mouse::Button mouseButton;
    sf::Event event;
};
