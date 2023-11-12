#ifndef APPLICATION_H
#define APPLICATION_H
#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
#include "Textbox.h"
#include "Button.h"
#include "Settings.h"

class Application {
public:
    enum class ScreenState {
        MainScreen,
        GamePlayScreen,
        SettingScreen
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

    sf::Texture settingScreenTex;
    sf::Sprite settingScreen;

    sf::Texture screenWithOptionsTex;
    sf::Sprite screenWithOptions;

    sf::Font font;

    ScreenState currentScreen;

    sf::Event event;

    Button settingTitle;
    Button playButton;
    Button instructionButton;
    Button settingButton;
    Button exitButton;

    Button gamePlayTitle;
    Button continueButton;
    Button newGameButton;
    Button backButton;

    Settings* settings;
private:
    void initWindow();
    //void initBackground();
    void initFont();
    void initMainTitle();
    void initPlayButton();
    void initInstructionButton();
    void initSettingButton();
    void initExitButton();
    void initGamePlayTitle();
    void initContinueButton();
    void initNewGameButton();
    void initBackButton();
};

#endif