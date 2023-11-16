#include "Settings.h"

Settings::Settings(sf::RenderWindow& window) :
	backButton("", { 178, 55 }, 25, sf::Color::Transparent, sf::Color::Transparent, &backButtonTex),
	saveButton("", { 178, 55 }, 25, sf::Color::Transparent, sf::Color::Transparent, &saveButtonTex),
	isEndScreen(false)
{
	initBackground(window);
	initFont();
	initBackButton();
	initSaveButton();
}

Settings::~Settings()
{

}

void Settings::initBackground(sf::RenderWindow& window)
{
	// Load setting screen background from file
	if (!settingScreenTex.loadFromFile("Material/Backgrounds/SettingScreen1.png"))
		std::cout << "SettingScreen1 not found!\n";
	settingScreenTex.setSmooth(true);
	settingScreen.setTexture(settingScreenTex);
	// Scale the background to fit window
	float scaleX = static_cast<float>(window.getSize().x) / settingScreenTex.getSize().x;
	float scaleY = static_cast<float>(window.getSize().y) / settingScreenTex.getSize().y;
	settingScreen.setScale(scaleX, scaleY);

	// Back button
	if (!backButtonTex.loadFromFile("Material/Buttons/Back/Back Buttons.png"))
		std::cout << "Back button not found!\n";
	backButtonTex.setSmooth(true);

	// Save button
	if (!saveButtonTex.loadFromFile("Material/Buttons/Save/Save Buttons.png"))
		std::cout << "Save Button hover not found!\n";
	saveButtonTex.setSmooth(true);
}

void Settings::initFont()
{
	// Load font from file
	if (!font.loadFromFile("font/SF-Pro-Rounded-Regular.otf"))
		std::cout << "Font not found!\n";
}

void Settings::initBackButton()
{
	backButton.setFont(font);
	backButton.setPosition({ 510, 600 });
	backButton.setOutlineThickness(2);
	backButton.setBackgroundAnimation(&backButtonTex);
}

void Settings::initSaveButton()
{
	saveButton.setFont(font);
	saveButton.setPosition({ 810, 600 });
	saveButton.setOutlineThickness(2);
	saveButton.setBackgroundAnimation(&saveButtonTex);
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
		else
		{

		}
	}
}



void Settings::update(sf::RenderWindow& window)
{
	if (!isEndScreen)
	{
		backButton.update(window);
		saveButton.update(window);
	}
	else
	{

	}
}

void Settings::render(sf::RenderWindow& window)
{
	if (!isEndScreen) {
		window.draw(settingScreen);
		backButton.drawTo(window);
		saveButton.drawTo(window);
	}
}

void Settings::setEndScreen(bool value) {
	isEndScreen = value;
}