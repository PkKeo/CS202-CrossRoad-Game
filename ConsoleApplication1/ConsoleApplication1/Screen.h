#pragma once
#include "SFML/Graphics.hpp"

//ANY screen will be inheritance from this abstract base screen.
class Screen 
{
public:
    virtual void handleEvent(sf::Event event, sf::RenderWindow& window, bool& endScreen);
    virtual void update(sf::RenderWindow& window);
    virtual void render(sf::RenderWindow& window);
    virtual void setEndScreen(bool value);
private: // my set to protected if need
    bool isEndScreen;
};