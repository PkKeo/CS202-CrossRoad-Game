#include "Character.h"

Character:: Character(): animation()
{}

Character::Character(sf::Texture* texture, sf::Vector2u imgCount, float switchTime, float speed) :
	animation(texture, imgCount, switchTime),
	speed(speed),
	row(0),
	faceRight(true)
{
	body.setSize(sf::Vector2f(60.0f, 60.0f));
	body.setPosition(sf::Vector2f(200.0f, 200.0f));
	body.setTexture(texture);
	body.setOrigin(50.f, 75.f);
}

Character::~Character()
{

}

sf::Vector2f Character::getSize()
{
	return body.getSize();
}


void Character::update(float deltaTime, std::vector <obstacle*> listObstacle)
{
	//get which the Obstacle Player is inside
	obstacle* inside = 0;
	int index = -1;
	for (int i = 0; i < listObstacle.size(); i++)
	{
		if (listObstacle[i]->charIsInside(*this))
		{
			inside = listObstacle[i];
			index = i;
				break;
		}
	}
	//std::cout << index;
	sf::Vector2f movement(0.0f, 0.0f);
	bool moveToOther = 0;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		movement.x -= speed * deltaTime * 2;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		movement.x += speed * deltaTime * 2;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		if (inside)
		{
			if (index + 1 < listObstacle.size() && listObstacle[index + 1]->distaceToPlayer(*this) < 150)
			{
				std::cout << "get here\n";
				body.setPosition(body.getPosition().x, listObstacle[index + 1]->getPosition().y + listObstacle[index + 1]->getWidth() - body.getSize().y * 0.5 - 2);
				moveToOther = 1;
			}
		}
		else
		movement.y -= speed * deltaTime * 2;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		movement.y += speed * deltaTime * 2;

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
	body.setFillColor(sf::Color::Blue);
	if (moveToOther == 0) {
		body.move(movement + listObstacle[0]->getSpeed());
		//body.move(listObstacle[0]->getSpeed());
	}
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

sf::Vector2f Character::getPosition()
{
	return body.getPosition();
}

sf::RectangleShape Character::getBody()
{
	return body;
}
