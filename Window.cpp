#include "Window.hpp"

Window::Window() {
    Setup("Window", sf::Vector2u(640, 480));
}

Window::Window(const std::string& title, const sf::Vector2u& l_size) {
    Setup(title, l_size);
}

Window::~Window() { Destroy(); }

void Window::Setup(const std::string& l_title, const sf::Vector2u& l_size) {
    m_windowTitle = l_title;
    m_windowSize = l_size;
    m_isFullscreen = false;
    m_isDone = false;
    isMousePressed = false;
    Create();
}

void Window::Create() {
    auto style = sf::Style::Titlebar | sf::Style::Close;
    m_window.create({ m_windowSize.x, m_windowSize.y, 32 }, m_windowTitle, style);
    static const sf::Color BACKGROUND_COLOR= sf::Color::White;
    m_window.clear(BACKGROUND_COLOR);
}

void Window::Destroy() {
    m_window.close();
}

void Window::Update() {
    while (m_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            m_isDone = true;
        }
        else if (event.type == sf::Event::KeyPressed &&
                 event.key.code == sf::Keyboard::F5) {
            ToggleFullscreen();
        }
        else if (event.type == sf::Event::MouseButtonPressed) {
            isMousePressed = true;
            mouseButton = event.mouseButton.button;
        }
        else if (event.type == sf::Event::MouseButtonReleased) {
            isMousePressed = false;
        }
    }
}

void Window::ToggleFullscreen() {
    m_isFullscreen = !m_isFullscreen;
    Destroy();
    Create();
}

void Window::BeginDraw() {
    m_window.clear(sf::Color::Black);
}

void Window::EndDraw() {
    m_window.display();
}

bool Window::IsDone() {
    return m_isDone;
}

bool Window::IsFullscreen() {
    return m_isFullscreen;
}

bool Window::IsMousePressed() {
    return isMousePressed;
}

sf::Mouse::Button Window::MouseButton() {
    return mouseButton;
}

sf::Event Window::GetEvent() {
    return event;
}

sf::Vector2u Window::GetWindowSize() {
    return m_windowSize;
}

sf::RenderWindow& Window::GetRenderWindow() {
    return m_window;
}

void Window::Draw(sf::Drawable& l_drawable) {
    m_window.draw(l_drawable);
}


