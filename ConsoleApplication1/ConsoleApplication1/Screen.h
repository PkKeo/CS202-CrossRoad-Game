#ifndef SCREEN_H
#define SCREEN_H

#include <iostream>
#include <vector>
#include "SFML/Graphics.hpp"
#include "Textbox.h"
#include "Button.h"

enum class ScreenState {
    MainScreen,
    //GamePlayScreen,
    SettingScreen
};

//ANY screen will be inheritance from this abstract base screen.
class Screen {
public:
    Screen(sf::RenderWindow& window) : isEndScreen(false) { initFont(); }
    ~Screen() {}

    virtual void handleEvent(sf::Event event, sf::RenderWindow& window, ScreenState& currentScreen, bool& endScreen) {}
    virtual void update(sf::RenderWindow& window) {}
    virtual void render(sf::RenderWindow& window) {}
    void setEndScreen(bool value) { isEndScreen = value; }

protected:
    virtual void initBackground(sf::RenderWindow& window) {}
    void initFont();

protected: // my set to protected if need
    sf::Font font;
    bool isEndScreen;

};

class MainScreen : public Screen {
public:
    MainScreen(sf::RenderWindow& window);
    ~MainScreen() {}

    void handleEvent(sf::Event event, sf::RenderWindow& window, ScreenState& currentScreen, bool& endScreen) override;
    void update(sf::RenderWindow& window) override;
    void render(sf::RenderWindow& window) override;

private:
    void initBackground(sf::RenderWindow& window) override;
    void initPlayButton();
    void initInstructionButton();
    void initSettingButton();
    void initExitButton();

private:
    sf::Texture mainScreenTex;
    sf::Sprite mainScreen;

    sf::Texture playButtonTex;
    ButtonCustom playButton;

    sf::Texture intButtonTex;
    ButtonCustom instructionButton;

    sf::Texture settingButtonTex;
    ButtonCustom settingButton;

    sf::Texture exitButtonTex;
    ButtonCustom exitButton;
};

class SettingScreen : public Screen {
public:
    SettingScreen(sf::RenderWindow& window);
    ~SettingScreen() {}

public:
    void handleEvent(sf::Event event, sf::RenderWindow& window, ScreenState& currentScreen, bool& endScreen) override;
    void update(sf::RenderWindow& window) override;
    void render(sf::RenderWindow& window) override;

private:
    void initBackground(sf::RenderWindow& window);
    void initBackButton();
    void initSaveButton();

private:
    sf::Texture settingScreenTex;
    sf::Sprite settingScreen;

    sf::Texture saveButtonTex;
    ButtonCustom saveButton;

    sf::Texture backButtonTex;
    ButtonCustom backButton;

};

class ScreenControl {
public:
    ScreenControl(sf::RenderWindow& window);
    ~ScreenControl();

    Screen* getScreen(ScreenState state);

private:
    std::vector<Screen*> screens;
};

#endif