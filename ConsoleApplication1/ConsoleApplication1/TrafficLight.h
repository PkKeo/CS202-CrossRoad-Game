#pragma once

#include "SFML/Graphics.hpp"
#include"Animation.h"

class TrafficLight
{
private:
	//sf::Texture  texture;
	sf::RectangleShape body;
	//Animation animation;

	float timeRed;
	float timeGreen;

public:
	TrafficLight();
	TrafficLight(sf::Texture* texture, sf::Vector2u imgCount, float switchTime,float timeRed, float timeGreen);
	~TrafficLight();

	void setPosition(sf::Vector2f pos);
	void setTexture(sf::Texture* texture);

	bool update();
	sf::RectangleShape& getShape();
};

