#ifndef CHARACTER_H
#define CHARACTER_H
#include <iostream>
#include "SFML/Graphics.hpp"
#include "Animation.h"

class Character {
public:
	Character(sf::Texture* texture, sf::Vector2u imgCount, float switchTime, float speed);
	~Character();

	void update(float deltaTime);
	void drawTo(sf::RenderWindow& window);

private:
	sf::RectangleShape body;
	Animation animation;
	unsigned int row;
	float speed;
	bool faceRight;
};

#endif
