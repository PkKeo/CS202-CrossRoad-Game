#include "main.h"
#include "Character.h"

int main() 
{
    //Application game;
    //game.run();
    sf::RenderWindow window(sf::VideoMode(512, 512), "Crossy Road", sf::Style::Close);
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
    }

    return 0;
}