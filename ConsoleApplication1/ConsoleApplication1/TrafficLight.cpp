#include "TrafficLight.h"

TrafficLight::TrafficLight()
{

}

TrafficLight::TrafficLight(sf::Texture* texture, sf::Vector2u imgCount, float switchTime,float timeRed, float timeGreen)
	//: animation(texture,imgCount,switchTime)
{
	this->body.setTexture(texture);
	this->timeRed = timeRed;
	this->timeGreen = timeGreen;

	this->body.setPosition(0.f, 0.f);
}

TrafficLight::~TrafficLight()
{

}

void TrafficLight::setPosition(sf::Vector2f pos)
{
	body.setPosition(pos);
}

void TrafficLight::setTexture(sf::Texture* texture)
{
	body.setTexture(texture);
}

bool TrafficLight::update()
{
	//int row = 0;
	//animation.update(row, 1.f, true);
	//body.setTextureRect(animation.uvRect);

	return false;
}

sf::RectangleShape& TrafficLight::getShape()
{
	// TODO: insert return statement here
	return body;
}





