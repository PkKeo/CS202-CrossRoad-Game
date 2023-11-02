#ifndef APPLICATION_H
#define APPLICATION_H
#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
#include "Textbox.h"
#include "Button.h"

class Application
{
public:
    enum class ScreenState
    {
        MainScreen,
        OptionsScreen
    };
public:
    Application();
    ~Application();
    void run();
public:
    void handleEvent();
    void update();
    void render();
private:
    sf::VideoMode videoMode;
    sf::RenderWindow window;

    sf::Texture mainScreenTex;
    sf::Sprite mainScreen;

    sf::Texture screenWithOptionsTex;
    sf::Sprite screenWithOptions;

    ScreenState currentScreen;

    sf::Event event;

    Button menuButton;
private:
    void initWindow();
    //void initBackground();
    //void initFont();
    void initMenuButton();
};

#endif