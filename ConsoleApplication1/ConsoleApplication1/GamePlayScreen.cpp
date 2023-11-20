#include "GamePlayScreen.h"

GamePlayScreen::GamePlayScreen(sf::RenderWindow& window) :
	Screen(window)
{
	sf::Texture t;
	if (!t.loadFromFile("Material/Animations/road.jpg"))
	{
		std::cout << "Can not load road! \n";
	}

	for (int i = 0; i < 10; i++)
	{
		obstacle* tmp = new obstacle(150.0f, sf::Vector2f(0, 0.1), &t);
		listObstacle.push_back(tmp);
	}



	float dis = 0;
	for (int i = 0; i < listObstacle.size(); i++)
	{
		listObstacle[i]->setPosition(sf::Vector2f(720, -15 - dis));
		dis += 160;
	}
	sf::Texture catTex;
	if (!catTex.loadFromFile("Material/Animations/Cat Animation.png"))
		std::cout << "Cat Animation not found!\n";

	Character cat(&catTex, sf::Vector2u(8, 3), 0.1f, 100.0f);
	player = cat;

}

void GamePlayScreen::handleEvent(sf::Event event, sf::RenderWindow& window, ScreenState& currentScreen, bool& endScreen)
{
	if (event.type == sf::Event::Closed)
	{
		window.close();
	}
}

void GamePlayScreen::update(sf::RenderWindow& window) 
{
	deltaTime = clock.restart().asSeconds();
	for (int i = 0; i < listObstacle.size();i++)
	{
		listObstacle[i]->setPosition(listObstacle[i]->getPosition() + listObstacle[i]->getSpeed());
	}
	player.update(deltaTime, listObstacle);
}

void GamePlayScreen::render(sf::RenderWindow& window)
{
	if (!isEndScreen)
	{
		window.clear();
	
		for (int i = 0; i < listObstacle.size(); i++)
		{
			listObstacle[i]->drawTo(window);
		}
		player.drawTo(window);
	}

}