#include "Character.h"

Character::Character(sf::Texture* texture, sf::Vector2u imgCount, float switchTime, float speed) :
	animation(texture, imgCount, switchTime),
	speed(speed),
	row(0),
	faceRight(true)
{
	body.setSize(sf::Vector2f(100.0f, 150.0f));
	body.setPosition(sf::Vector2f(200.0f, 200.0f));
	body.setTexture(texture);
	body.setOrigin(50.f, 75.f);
}

Character::~Character()
{

}

void Character::update(float deltaTime)
{
	sf::Vector2f movement(0.0f, 0.0f);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		movement.x -= speed * deltaTime;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		movement.x += speed * deltaTime;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		movement.y -= speed * deltaTime;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		movement.y += speed * deltaTime;

	if (!movement.x && !movement.y)
		row = 1;
	else
	{
		row = 2;
		if (movement.x > 0.0f)
			faceRight = true;
		else
			faceRight = false;
	}

	animation.update(row, deltaTime, faceRight);
	body.setTextureRect(animation.uvRect);
	body.move(movement);
}

void Character::drawTo(sf::RenderWindow& window)
{
	window.draw(body);
}

const sf::FloatRect& Character::getBounds()
{
	// TODO: insert return statement here
	return body.getGlobalBounds();
}

void Character::setPosition(sf::Vector2f coor)
{
	body.setPosition(coor);
}
