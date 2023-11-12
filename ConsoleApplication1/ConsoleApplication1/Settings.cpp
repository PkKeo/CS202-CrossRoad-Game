#include "Settings.h"

Settings::Settings(sf::RenderWindow& window) :
	settingTitle("SETTINGS", { 500, 200 }, 50, sf::Color::Green, sf::Color::Black),
	backButton("Back", { 200, 70 }, 25, sf::Color::Yellow, sf::Color::Black),
	isEndScreen(false)
{
	//initBackground(window);
	initFont();
	initMainTitle();
	initBackButton();
}

Settings::~Settings()
{

}

//void Settings::initBackground()
//{
//	// Load background from file
//	if (!mainScreenTex.loadFromFile("background/background1.jpg"))
//		std::cout << "Background1 not found!\n";
//	mainScreenTex.setSmooth(true);
//	mainScreen.setTexture(mainScreenTex);
//
//	// Scale the background to fit window
//	float scaleX = static_cast<float>(window.getSize().x) / mainScreenTex.getSize().x;
//	float scaleY = static_cast<float>(window.getSize().y) / mainScreenTex.getSize().y;
//	mainScreen.setScale(scaleX, scaleY);
//}

void Settings::initFont()
{
	// Load font from file
	if (!font.loadFromFile("font/SF-Pro-Rounded-Regular.otf"))
		std::cout << "Font not found!\n";
}

void Settings::initMainTitle()
{
	settingTitle.setFont(font);
	settingTitle.setPosition({ 350, 100 });
	settingTitle.setOutlineThickness(2);
}

void Settings::initBackButton()
{
	backButton.setFont(font);
	backButton.setPosition({ 500, 650 });
	backButton.setOutlineThickness(2);
}

void Settings::handleEvent(sf::Event event, sf::RenderWindow& window, bool& endScreen)
{
	if (event.type == sf::Event::MouseButtonPressed)
	{
		if (backButton.isMouseOver(window))
		{
			endScreen = true;
			isEndScreen = endScreen;
		}
		/*else if (menuButton.isMouseOver(window)) {
			if (currentScreen == ScreenState::MainScreen)
				currentScreen = ScreenState::OptionsScreen;
			else
				currentScreen = ScreenState::MainScreen;
		} */
	}
}



void Settings::update(sf::RenderWindow& window)
{
	if (!isEndScreen)
	{
		backButton.update(window);
	}
	else
	{

	}
}

void Settings::render(sf::RenderWindow& window)
{
	if (!isEndScreen) {
		//window.draw(mainScreen);
		settingTitle.drawTo(window);
		backButton.drawTo(window);
	}
}

void Settings::setEndScreen(bool value) {
	isEndScreen = value;
}