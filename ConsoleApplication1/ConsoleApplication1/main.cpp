#pragma once
#include "main.h"


Application::Application() :
	videoMode(1200, 900),
	window(videoMode, "Crossy Road", sf::Style::Close), //don't clear the close style!!
	settingTitle("CROSSY ROAD G2", { 500, 200 }, 50, sf::Color::Green, sf::Color::Black),
	playButton("Play", { 200, 70 }, 25, sf::Color::Yellow, sf::Color::Black),
	instructionButton("Instruction", { 200, 70 }, 25, sf::Color::Yellow, sf::Color::Black),
	settingButton("Settings", { 200, 70 }, 25, sf::Color::Yellow, sf::Color::Black),
	exitButton("Exit", { 200, 70 }, 25, sf::Color::Yellow, sf::Color::Black),
	gamePlayTitle("GAME PLAY", { 500, 200 }, 50, sf::Color::Green, sf::Color::Black),
	continueButton("Continue", { 200, 70 }, 25, sf::Color::Yellow, sf::Color::Black),
	newGameButton("New game", { 200, 70 }, 25, sf::Color::Yellow, sf::Color::Black),
	backButton("Back", { 200, 70 }, 25, sf::Color::Yellow, sf::Color::Black),
	settings(nullptr),
	currentScreen(ScreenState::MainScreen)
{
	initWindow();
	//initBackground();
	initFont();
	initMainTitle();
	initPlayButton();
	initInstructionButton();
	initSettingButton();
	initExitButton();
	initGamePlayTitle();
	initContinueButton();
	initNewGameButton();
	initBackButton();
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

//void Application::initBackground()
//{
//	// Load background from file
//	if (!mainScreenTex.loadFromFile("background/background1.jpg"))
//		std::cout << "Background1 not found!\n";
//	mainScreenTex.setSmooth(true);
//	mainScreen.setTexture(mainScreenTex);
//
//	if (!screenWithOptionsTex.loadFromFile("background/background2.jpg"))
//		std::cout << "Background2 not found!\n";
//	screenWithOptionsTex.setSmooth(true);
//	screenWithOptions.setTexture(screenWithOptionsTex);
//
//	// Scale the background to fit window
//	float scaleX = static_cast<float>(window.getSize().x) / mainScreenTex.getSize().x;
//	float scaleY = static_cast<float>(window.getSize().y) / mainScreenTex.getSize().y;
//	mainScreen.setScale(scaleX, scaleY);
//
//
//	scaleX = static_cast<float>(window.getSize().x) / screenWithOptionsTex.getSize().x;
//	scaleY = static_cast<float>(window.getSize().y) / screenWithOptionsTex.getSize().y;
//	screenWithOptions.setScale(scaleX, scaleY);
//}

void Application::initFont()
{
	// Load font from file
	if (!font.loadFromFile("font/SF-Pro-Rounded-Regular.otf"))
		std::cout << "Font not found!\n";
}

void Application::initMainTitle()
{
	settingTitle.setFont(font);
	settingTitle.setPosition({ 350, 100 });
	settingTitle.setOutlineThickness(2);
}

void Application::initPlayButton()
{
	playButton.setFont(font);
	playButton.setPosition({ 500, 350 });
	playButton.setOutlineThickness(2);
}


void Application::initInstructionButton()
{
	instructionButton.setFont(font);
	instructionButton.setPosition({ 500, 450 });
	instructionButton.setOutlineThickness(2);
}


void Application::initSettingButton()
{
	settingButton.setFont(font);
	settingButton.setPosition({ 500, 550 });
	settingButton.setOutlineThickness(2);
}

void Application::initExitButton()
{
	exitButton.setFont(font);
	exitButton.setPosition({ 500, 650 });
	exitButton.setOutlineThickness(2);
}

void Application::initGamePlayTitle()
{
	gamePlayTitle.setFont(font);
	gamePlayTitle.setPosition({ 350, 100 });
	gamePlayTitle.setOutlineThickness(2);
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
				settings->setEndScreen(endScreen);
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
		window.clear(sf::Color::White);
		//window.draw(mainScreen);
		settingTitle.drawTo(window);
		playButton.drawTo(window);
		instructionButton.drawTo(window);
		settingButton.drawTo(window);
		exitButton.drawTo(window);
	}
	else if (currentScreen == ScreenState::GamePlayScreen) {
		window.clear(sf::Color::White);
		//window.draw(screenWithOptions);
		gamePlayTitle.drawTo(window);
		continueButton.drawTo(window);
		newGameButton.drawTo(window);
		backButton.drawTo(window);
	}
	else if (currentScreen == ScreenState::SettingScreen) {
		window.clear(sf::Color::White);
		settings->render(window);
	}
	else
	{

	}

	window.display();
}