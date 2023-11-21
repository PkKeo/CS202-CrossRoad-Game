#include "obstacle.h"

obstacle::obstacle()
{}
obstacle::obstacle(float width, sf::Vector2f speed, sf::Texture* texture)
    //:light(texture, sf::Vector2u(1, 1), 0.f, 0, 0)
{
    /*
    sf::Texture* TrafficText = new sf::Texture();
    if (!TrafficText->loadFromFile("Material/Traffic light/dendo.png")) {
        std::cout << "ERROR::LOADING TRAFFIC LIGHT.\n";
    }

    light.setTexture(TrafficText);
    light.setPosition(sf::Vector2f(10.f, 10.f));
    */

    rec.setSize(sf::Vector2f(1440, width));
    this->speed = speed;
    rec.setOrigin(1440 / 2, width / 2);
    rec.setTexture(texture);
    getPic = texture;
}

float obstacle::getWidth()
{
    return width;
}
bool obstacle::charIsInside(Character player)
{
    sf::FloatRect obsBounds = rec.getGlobalBounds();
    sf::FloatRect playerBounds = player.getBounds();

    if(obsBounds.contains(playerBounds.left, playerBounds.top) &&
        obsBounds.contains(playerBounds.left + playerBounds.width, playerBounds.top + playerBounds.height)) 
    {
        // The object is entirely inside the target rectangle
        return true;
    }
    else 
    {
     // The object is partially or entirely outside the target rectangle
        return false;
    }
    return false;
}

//virtual bool isCollision(Character player);

sf::Vector2f obstacle::getPosition()
{
    return rec.getPosition();
}

void obstacle::setPosition(sf::Vector2f pos)
{
    rec.setPosition(pos);
}

void obstacle::setSpeed(sf::Vector2f v)
{
    speed = v;
}

sf::Vector2f obstacle::getSpeed()
{
    return speed;
}

float obstacle::distaceToPlayer(Character player)
{
    return abs(player.getPosition().y - getPosition().y);
}

void obstacle::drawTo(sf::RenderWindow& window)
{   
    window.draw(rec);
}