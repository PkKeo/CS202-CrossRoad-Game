#include "main.h"

int main()
{
    /*sf::RenderWindow window(sf::VideoMode(800, 600), "Test SFML");
    sf::Event evnt;
    while (window.isOpen())
    {
        while (window.pollEvent(evnt))
        {
            if (evnt.type == sf::Event::Closed)
            {
                window.close();
            }
        }
    }*/

    Application game;
    game.run();

    return 0;
}