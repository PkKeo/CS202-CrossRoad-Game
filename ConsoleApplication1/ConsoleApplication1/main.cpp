#pragma once
#include <iostream>
#include <fstream>
#include "main.h"


Application::Application() :
	videoMode(1200, 900),
	window(videoMode, "Crossy Road", sf::Style::Close), //don't clear the close style!!
	menuButton("", { 153, 60 }, 20, sf::Color::Transparent, sf::Color::Transparent),
	currentScreen(ScreenState::MainScreen)
{
	initWindow();
	//initBackground();
	//initFont();
	initMenuButton();
}

Application::~Application()
{
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

//void Application::initFont()
//{
//	// Load font from file
//	if (!font.loadFromFile("font/SF-Pro-Rounded-Regular.otf"))
//		std::cout << "Font not found!\n";
//}

void Application::initMenuButton()
{
	//menuButton.setFont(font);
	menuButton.setPosition({ 972, 163 });
	menuButton.setOutlineThickness(2);
}


void Application::run()
{
	// Load dictionaries
	//window.draw(loadingScreen);
	window.display();
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
		if (currentScreen == ScreenState::MainScreen || currentScreen == ScreenState::OptionsScreen)
		{
			if (event.type == sf::Event::TextEntered)
			{
			}
			if (event.type == sf::Event::MouseButtonPressed)
			{
				//if (searchBar.isMouseOver(window))
				//	searchBar.setSelected(true);
				//else
				//	searchBar.setSelected(false);
				//// Start searching when search button is pressed
				/*if (searchButton.isMouseOver(window))
				{
				}
				else if (menuButton.isMouseOver(window)) {
					if (currentScreen == ScreenState::MainScreen)
						currentScreen = ScreenState::OptionsScreen;
					else
						currentScreen = ScreenState::MainScreen;
				}*/
			}
		}
		/*else if (currentScreen == ScreenState::EditDefinitionScreen)
		{
			
		}*/
		else
		{

		}
	}
}



void Application::update()
{
	if (currentScreen == ScreenState::MainScreen)
	{
		menuButton.update(window);
	}
	else if (currentScreen == ScreenState::OptionsScreen)
	{
		menuButton.update(window);
	}
	else
	{

	}
}

void Application::render()
{
	if (currentScreen == ScreenState::MainScreen) {
		window.clear(sf::Color::White);
		window.draw(mainScreen);
		menuButton.drawTo(window);
	}
	else if (currentScreen == ScreenState::OptionsScreen) {
		window.clear(sf::Color::White);
		window.draw(screenWithOptions);

		menuButton.drawTo(window);
	}

	window.display();
}