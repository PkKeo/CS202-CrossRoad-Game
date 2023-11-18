#pragma once
#include "SFML/Graphics.hpp"
class obstacle  //Base of the ANY obstacle: river, road, street.
{
public:
	obstacle(float width, sf::Vector2f speed, sf::Texture* texture);
	bool charIsInside();
	bool isCollision();// run the collision affect
	sf::Vector2f getPosition();
	void setPosition(sf::Vector2f);
	void setSpeed();
	sf::Vector2f getSpeed();
private:
	sf::RectangleShape rec;
	float x; //the width of obstacle, the length is fixed at 1440
	sf::Texture getPic;
	sf::Vector2f speed;
};