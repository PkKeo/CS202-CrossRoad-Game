#pragma once
#include "main.h"


Application::Application() :
	videoMode(SCREEN_WIDTH, SCREEN_HEIGHT),
	window(videoMode, "Crossy Road", sf::Style::Close), //don't clear the close style!!
	playButton("", { 178, 55 }, 25, sf::Color::Transparent, sf::Color::Transparent, &playButtonTex),
	instructionButton("Instruction", { 400, 55 }, 25, sf::Color::Transparent, sf::Color::Transparent, &intButtonTex),
	settingButton("Settings", { 303, 55 }, 25, sf::Color::Transparent, sf::Color::Transparent, &settingButtonTex),
	exitButton("", { 145, 55 }, 25, sf::Color::Transparent, sf::Color::Transparent, &exitButtonTex),
	continueButton("Continue", { 200, 70 }, 25, sf::Color::Yellow, sf::Color::Black),
	newGameButton("New game", { 200, 70 }, 25, sf::Color::Yellow, sf::Color::Black),
	backButton("Back", { 200, 70 }, 25, sf::Color::Yellow, sf::Color::Black),
	saveButton("", { 175, 55 }, 25, sf::Color::Transparent, sf::Color::Black, &saveButtonTex),
	settings(nullptr),
	currentScreen(ScreenState::MainScreen)
{
	initWindow();
	initBackground();
	initFont();
	initPlayButton();
	initInstructionButton();
	initSettingButton();
	initExitButton();
	initContinueButton();
	initNewGameButton();
	initBackButton();
	initSaveButton();
}

Application::~Application()
{
	delete settings;
}

void Application::initWindow()
{
	sf::Vector2i centerWindow(
		(sf::VideoMode::getDesktopMode().width / 2) - 600,
		(sf::VideoMode::getDesktopMode().height / 2) - 450
	);
	window.setPosition(centerWindow);
	window.setKeyRepeatEnabled(true);
}

void Application::initBackground()
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

	// Save button
	if (!saveButtonTex.loadFromFile("Material/Buttons/Save/Save Buttons.png"))
		std::cout << "Save Button hover not found!\n";
	saveButtonTex.setSmooth(true);

}

void Application::initFont()
{
	// Load font from file
	if (!font.loadFromFile("font/SF-Pro-Rounded-Regular.otf"))
		std::cout << "Font not found!\n";
}

void Application::initPlayButton()
{
	playButton.setFont(font);
	playButton.setPosition({ 677, 300 });
	playButton.setOutlineThickness(2);
	playButton.setBackgroundAnimation(&playButtonTex);
}


void Application::initInstructionButton()
{
	instructionButton.setFont(font);
	instructionButton.setPosition({ 570, 400 });
	instructionButton.setOutlineThickness(2);
	instructionButton.setBackgroundAnimation(&intButtonTex);
}


void Application::initSettingButton()
{
	settingButton.setFont(font);
	settingButton.setPosition({ 610, 500 });
	settingButton.setOutlineThickness(2);
	settingButton.setBackgroundAnimation(&settingButtonTex);
}

void Application::initExitButton()
{
	exitButton.setFont(font);
	exitButton.setPosition({ 690, 600 });
	exitButton.setOutlineThickness(2);
	exitButton.setBackgroundAnimation(&exitButtonTex);
}

void Application::initSaveButton()
{
	saveButton.setFont(font);
	saveButton.setPosition({ 690, 600 });
	saveButton.setOutlineThickness(2);
	saveButton.setBackgroundAnimation(&saveButtonTex);
}

void Application::initContinueButton()
{
	continueButton.setFont(font);
	continueButton.setPosition({ 500, 350 });
	continueButton.setOutlineThickness(2);
}

void Application::initNewGameButton()
{
	newGameButton.setFont(font);
	newGameButton.setPosition({ 500, 500 });
	newGameButton.setOutlineThickness(2);
}

void Application::initBackButton()
{
	backButton.setFont(font);
	backButton.setPosition({ 500, 650 });
	backButton.setOutlineThickness(2);
}

void Application::run()
{
	//window.draw(loadingScreen);
	window.display();
	settings = new Settings(window);
	while (window.isOpen())
	{
		/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
			searchBar.setSelected(true);
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			searchBar.setSelected(false);*/

		handleEvent();
		update();
		render();
	}
}

void Application::handleEvent()
{
	//Event Loop:
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			window.close();
		}
		if (currentScreen == ScreenState::MainScreen) // || currentScreen == ScreenState::GamePlayScreen)
		{
			// if (event.type == sf::Event::TextEntered) { }

			if (event.type == sf::Event::MouseButtonPressed)
			{
				//if (searchBar.isMouseOver(window))
				//	searchBar.setSelected(true);
				//else
				//	searchBar.setSelected(false);
				//// Start searching when search button is pressed

				if (playButton.isMouseOver(window))
				{
					currentScreen = ScreenState::GamePlayScreen;
				}
				else if (settingButton.isMouseOver(window))
				{
					currentScreen = ScreenState::SettingScreen;
				}
				else if (exitButton.isMouseOver(window))
				{
					window.close();
				}
				/*else if (menuButton.isMouseOver(window)) {
					if (currentScreen == ScreenState::MainScreen)
						currentScreen = ScreenState::OptionsScreen;
					else
						currentScreen = ScreenState::MainScreen;
				}*/
			}
		}
		else if (currentScreen == ScreenState::GamePlayScreen)
		{
			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (backButton.isMouseOver(window))
				{
					currentScreen = ScreenState::MainScreen;
				}
			}
		}
		else if (currentScreen == ScreenState::SettingScreen)
		{
			bool endScreen = false;
			settings->setEndScreen(endScreen);
			settings->handleEvent(event, window, endScreen);
			if (endScreen) {
				//settings->setEndScreen(endScreen);
				currentScreen = ScreenState::MainScreen;
			}
		}
		else
		{

		}
	}
}



void Application::update()
{
	if (currentScreen == ScreenState::MainScreen)
	{
		playButton.update(window);
		instructionButton.update(window);
		settingButton.update(window);
		exitButton.update(window);
	}
	else if (currentScreen == ScreenState::GamePlayScreen)
	{
		continueButton.update(window);
		newGameButton.update(window);
		backButton.update(window);
	}
	else if (currentScreen == ScreenState::SettingScreen)
	{
		settings->update(window);
	}
	else
	{

	}
}

void Application::render()
{
	if (currentScreen == ScreenState::MainScreen) {
		window.draw(mainScreen);
		playButton.drawTo(window);
		instructionButton.drawTo(window);
		settingButton.drawTo(window);
		exitButton.drawTo(window);
	}
	else if (currentScreen == ScreenState::GamePlayScreen) {
		window.clear(sf::Color::White);
		//window.draw(settingScreen);
		continueButton.drawTo(window);
		newGameButton.drawTo(window);
		backButton.drawTo(window);
	}
	else if (currentScreen == ScreenState::SettingScreen) {
		settings->render(window);
	}
	else
	{

	}

	window.display();
}