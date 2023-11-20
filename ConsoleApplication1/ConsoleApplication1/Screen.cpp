#include "Screen.h"
#include "GamePlayScreen.h"
ScreenControl::ScreenControl(sf::RenderWindow& window)
{
	Screen* tmp;
	tmp = new MainScreen(window);
	screens.push_back(tmp);
	tmp = new SettingScreen(window);
	screens.push_back(tmp);;
	tmp = new GamePlayScreen(window);
	screens.push_back(tmp);
}

ScreenControl::~ScreenControl()
{
	for (auto screen : screens) delete screen;
	screens.clear();
}

Screen* ScreenControl::getScreen(ScreenState state) 
{
	if (state == ScreenState::MainScreen)
	{
		Screen* tmp = screens[0];
		return tmp;
	}
	if (state == ScreenState::SettingScreen)
	{
		Screen* tmp = screens[1];
		return tmp;
	}
	if (state == ScreenState::GamePlayScreen)
	{
		Screen* tmp = screens[2];
		return tmp;
	}
}

// SCREEN

void Screen::initFont()
{
	// Load font from file
	if (!font.loadFromFile("font/SF-Pro-Rounded-Regular.otf"))
		std::cout << "Font not found!\n";
}

// MAINSCREEN

MainScreen::MainScreen(sf::RenderWindow& window) :
	Screen(window),
	playButton("", { 178, 55 }, 25, sf::Color::Transparent, sf::Color::Transparent, & playButtonTex),
	instructionButton("Instruction", { 400, 55 }, 25, sf::Color::Transparent, sf::Color::Transparent, & intButtonTex),
	settingButton("Settings", { 303, 55 }, 25, sf::Color::Transparent, sf::Color::Transparent, & settingButtonTex),
	exitButton("", { 145, 55 }, 25, sf::Color::Transparent, sf::Color::Transparent, & exitButtonTex)
{
	initBackground(window);
	initPlayButton();
	initInstructionButton();
	initSettingButton();
	initExitButton();
}

void MainScreen::initBackground(sf::RenderWindow& window)
{
	// Load main screen background from file
	if (!mainScreenTex.loadFromFile("Material/Backgrounds/MainScreen1.png"))
		std::cout << "MainScreen1 not found!\n";
	mainScreenTex.setSmooth(true);
	mainScreen.setTexture(mainScreenTex);
	// Scale the background to fit window
	float scaleX = static_cast<float>(window.getSize().x) / mainScreenTex.getSize().x;
	float scaleY = static_cast<float>(window.getSize().y) / mainScreenTex.getSize().y;
	mainScreen.setScale(scaleX, scaleY);

	// Play button
	if (!playButtonTex.loadFromFile("Material/Buttons/Play/Play Buttons.png"))
		std::cout << "Play Button hover not found!\n";
	playButtonTex.setSmooth(true);

	// Instruction button
	if (!intButtonTex.loadFromFile("Material/Buttons/Instruction/Instruction Buttons.png"))
		std::cout << "Play Button hover not found!\n";
	intButtonTex.setSmooth(true);

	// Setting button
	if (!settingButtonTex.loadFromFile("Material/Buttons/Settings/Settings Buttons.png"))
		std::cout << "Play Button hover not found!\n";
	settingButtonTex.setSmooth(true);

	// Exit button
	if (!exitButtonTex.loadFromFile("Material/Buttons/Exit/Exit Buttons.png"))
		std::cout << "Exit Button hover not found!\n";
	exitButtonTex.setSmooth(true);
}

void MainScreen::initPlayButton()
{
	playButton.setFont(font);
	playButton.setPosition({ 677, 300 });
	playButton.setOutlineThickness(2);
	playButton.setBackgroundAnimation(&playButtonTex);
}

void MainScreen::initInstructionButton()
{
	instructionButton.setFont(font);
	instructionButton.setPosition({ 570, 400 });
	instructionButton.setOutlineThickness(2);
	instructionButton.setBackgroundAnimation(&intButtonTex);
}

void MainScreen::initSettingButton()
{
	settingButton.setFont(font);
	settingButton.setPosition({ 610, 500 });
	settingButton.setOutlineThickness(2);
	settingButton.setBackgroundAnimation(&settingButtonTex);
}

void MainScreen::initExitButton()
{
	exitButton.setFont(font);
	exitButton.setPosition({ 690, 600 });
	exitButton.setOutlineThickness(2);
	exitButton.setBackgroundAnimation(&exitButtonTex);
}

void MainScreen::handleEvent(sf::Event event, sf::RenderWindow& window, ScreenState& currentScreen, bool& endScreen)
{
	if (event.type == sf::Event::MouseButtonPressed)
	{
		if (playButton.isMouseOver(window))
		{
			currentScreen = ScreenState::GamePlayScreen;
			endScreen = true;
			isEndScreen = endScreen;
			
		}
		else if (instructionButton.isMouseOver(window))
		{
			
		}
		else if (settingButton.isMouseOver(window))
		{
			currentScreen = ScreenState::SettingScreen;
			endScreen = true;
			isEndScreen = endScreen;
		}
		else if (exitButton.isMouseOver(window))
		{
			window.close();
		}
	}
}

void MainScreen::update(sf::RenderWindow& window)
{
	if (!isEndScreen)
	{
		playButton.update(window);
		instructionButton.update(window);
		settingButton.update(window);
		exitButton.update(window);
	}
	else
	{

	}
}

void MainScreen::render(sf::RenderWindow& window)
{
	if (!isEndScreen) 
	{
		window.draw(mainScreen);
		playButton.drawTo(window);
		instructionButton.drawTo(window);
		settingButton.drawTo(window);
		exitButton.drawTo(window);
	}
}

// SETTINGSCREEN

SettingScreen::SettingScreen(sf::RenderWindow& window) :
	Screen(window),
	backButton("", { 178, 55 }, 25, sf::Color::Transparent, sf::Color::Transparent, & backButtonTex),
	saveButton("", { 178, 55 }, 25, sf::Color::Transparent, sf::Color::Transparent, & saveButtonTex)
{
	initBackground(window);
	initBackButton();
	initSaveButton();
}

void SettingScreen::initBackground(sf::RenderWindow& window)
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

void SettingScreen::initBackButton()
{
	backButton.setFont(font);
	backButton.setPosition({ 510, 600 });
	backButton.setOutlineThickness(2);
	backButton.setBackgroundAnimation(&backButtonTex);
}

void SettingScreen::initSaveButton()
{
	saveButton.setFont(font);
	saveButton.setPosition({ 810, 600 });
	saveButton.setOutlineThickness(2);
	saveButton.setBackgroundAnimation(&saveButtonTex);
}

void SettingScreen::handleEvent(sf::Event event, sf::RenderWindow& window, ScreenState& currentScreen, bool& endScreen)
{
	if (event.type == sf::Event::MouseButtonPressed)
	{
		if (backButton.isMouseOver(window))
		{
			currentScreen = ScreenState::MainScreen;
			endScreen = true;
			isEndScreen = endScreen;
		}
		else
		{

		}
	}
}



void SettingScreen::update(sf::RenderWindow& window)
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

void SettingScreen::render(sf::RenderWindow& window)
{
	if (!isEndScreen) {
		window.draw(settingScreen);
		backButton.drawTo(window);
		saveButton.drawTo(window);
	}
}