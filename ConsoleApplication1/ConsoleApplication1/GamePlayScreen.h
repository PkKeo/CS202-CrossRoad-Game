#pragma once
#include "Screen.h"
#include "Character.h"
#include "obstacle.h"
class GamePlayScreen : public Screen
{
public:
    GamePlayScreen(sf::RenderWindow& window);
    GamePlayScreen();
    ~GamePlayScreen() {
        for (auto *e : listObstacle) {
            delete e;
        }
    }
    void handleEvent(sf::Event event, sf::RenderWindow& window, ScreenState& currentScreen, bool& endScreen) override;
    void update(sf::RenderWindow& window) override;
    void render(sf::RenderWindow& window) override;
private:
    Character player;
    std::vector<obstacle*> listObstacle;
    float deltaTime = 0;
    sf::Clock clock;
};