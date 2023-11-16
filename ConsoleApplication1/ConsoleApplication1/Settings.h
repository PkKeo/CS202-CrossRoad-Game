#ifndef SETTINGS_H
#define SETTINGS_H

#include <iostream>
#include "SFML/Graphics.hpp"
#include "Textbox.h"
#include "Button.h"

class Settings {
public:
    Settings(sf::RenderWindow& window);
    ~Settings();
public:
    void handleEvent(sf::Event event, sf::RenderWindow& window, bool& endScreen);
    void update(sf::RenderWindow& window);
    void render(sf::RenderWindow& window);
    void setEndScreen(bool value);
private:
    sf::Texture settingScreenTex;
    sf::Sprite settingScreen;

    sf::Texture saveButtonTex;

    sf::Texture backButtonTex;

    sf::Font font;

    ButtonCustom backButton;
    ButtonCustom saveButton;

    bool isEndScreen; // Check if users want to leave the screen
private:
    void initBackground(sf::RenderWindow& window);
    void initFont();
    void initBackButton();
    void initSaveButton();
};

#endif