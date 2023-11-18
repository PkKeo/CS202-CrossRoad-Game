#ifndef BUTTON_H
#define BUTTON_H

#include <iostream>
#include <SFML/Graphics.hpp>

class Button {
public:
	Button(std::string btnText, sf::Vector2f buttonSize, int charSize, sf::Color bgColor, sf::Color textColor);

	// Pass font by reference:
	void setFont(const sf::Font& font);

	void setBackColor(const sf::Color &color);

	void setTextColor(const sf::Color &color);

	virtual void setPosition(const sf::Vector2f &point);

	void setPosition(float x, float y);

	void setOutlineThickness(float thickness);

	void setOutlineColor(const sf::Color& color);

	void setTexture(const sf::Texture *texture);

	const sf::Vector2f& getSize();

	virtual void drawTo(sf::RenderWindow& window);

	// Check if the mouse is within the bounds of the button:
	bool isMouseOver(sf::RenderWindow& window);

	virtual void update(sf::RenderWindow& window);

	void setString(std::string text);

	void setStyle(sf::Uint32 style);

	void adjustSizeToContainText();
private:
	sf::Text text;
	sf::RectangleShape button;

	int btnWidth;
	int btnHeight;
};

class ButtonCustom : public Button {
public:
	ButtonCustom(std::string btnText, sf::Vector2f buttonSize, int charSize, sf::Color bgColor, sf::Color textColor, sf::Texture* buttonTex);

	void setBackgroundAnimation(sf::Texture* buttonTex);

	void setPosition(const sf::Vector2f& point) override;

	void update(sf::RenderWindow& window) override;

	void drawTo(sf::RenderWindow& window) override;

private:
	sf::Texture* buttonTex;
	sf::IntRect uvRect;
	sf::Sprite buttonImg;
};

#endif