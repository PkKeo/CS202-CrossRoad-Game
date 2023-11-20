#include "main.h"
#include "Character.h"
#include "obstacle.h"
int main() 
{
   Application game;
    game.run();


   /* sf::RenderWindow window(sf::VideoMode(1440, 920), "Crossy Road", sf::Style::Close);
    sf::Texture texture;
    texture.loadFromFile("Material/Animations/road.jpg");
    obstacle* tmp = new obstacle(150, sf::Vector2f(0, 0.1), &texture);
    tmp->setPosition(sf::Vector2f(0, 400));
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            }
        }
        window.clear();
        tmp -> drawTo(window);
        window.display();
    }

    /*sf::RenderWindow window(sf::VideoMode(512, 512), "Crossy Road", sf::Style::Close);
    sf::Texture catTex;
    if (!catTex.loadFromFile("Material/Animations/Cat Animation.png"))
        std::cout << "Cat Animation not found!\n";

    Character cat(&catTex, sf::Vector2u(8, 3), 0.1f, 100.0f);

    float deltaTime = 0.0f;
    sf::Clock clock;

    while (window.isOpen())
    {
        deltaTime = clock.restart().asSeconds();

        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            }
        }
        cat.update(deltaTime);
        window.clear();
        cat.drawTo(window);
        window.display();
    }*/

    return 0;
}