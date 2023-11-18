#include "main.h"
#include "Character.h"
#include<vector>


// Backend
// Idea cho cai background move
// Idea cho nv di chuyen
// Random xe theo tung khung
// GamePlay-> Trieu, Minh

// Front End
// Menu va Setting
// Hieu, Uyen

// Both
// Save
// ten,score,man,item,...
// -> Tao them 1 class user

int main() 
{
    //Application game;
    //game.run();
    sf::RenderWindow window(sf::VideoMode(1440, 810), "Crossy Road", sf::Style::Close);
    sf::Texture catTex;
    window.setFramerateLimit(144);

    sf::RectangleShape test(sf::Vector2f(200.f,60.f));
    test.setPosition(15.f, 15.f);
    test.setFillColor(sf::Color::Green);
    test.setOrigin(15.f, 15.f);

    sf::Vector2f movement(0.f,0.001f);

    std::vector<sf::RectangleShape> array;
    for (int i = 0;i < 10;i++) {
        array.push_back(test);
    }

    float tmp = 0;
    for (int i = 0;i < 10;i++) {
        tmp += 65.f;
        array[i].setPosition(array[i].getPosition().x, array[i].getPosition().y - tmp);
    }

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

        //
        for (int i = 0;i < 10;i++) {
            array[i].move(0.f,1.f);
        }
        cat.setPosition(array[0].getPosition());
        //cat.update(deltaTime);
        //

        window.clear();
        //cat.drawTo(window);

        //
        for (int i = 0;i < 10;i++) {
            window.draw(array[i]);
        }
        cat.drawTo(window);
        //

        window.display();
    }

    return 0;
}