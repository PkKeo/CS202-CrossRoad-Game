#ifndef APPLICATION_H
#define APPLICATION_H
#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
#include "Textbox.h"
#include "Button.h"
#include "Settings.h"

static const unsigned int SCREEN_HEIGHT = 810;
static const unsigned int SCREEN_WIDTH = 1440;

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

    sf::Texture mainScreenTex;
    sf::Sprite mainScreen;

    sf::Texture playButtonTex;

    sf::Texture intButtonTex;

    sf::Texture settingButtonTex;

    sf::Texture exitButtonTex;

    sf::Texture saveButtonTex;

    sf::Font font;

    ScreenState currentScreen;

    sf::Event event;

    ButtonCustom playButton;
    ButtonCustom instructionButton;
    ButtonCustom settingButton;
    ButtonCustom exitButton;

    Button continueButton;
    Button newGameButton;
    Button backButton;
    ButtonCustom saveButton;

    Settings* settings;
private:
    void initWindow();
    void initBackground();
    void initFont();
    void initPlayButton();
    void initInstructionButton();
    void initSettingButton();
    void initExitButton();
    void initContinueButton();
    void initNewGameButton();
    void initBackButton();
    void initSaveButton();
};

#endif