#pragma once
#include"Button.h"
#include "MainMenu.h"
#include<iostream>
#include"WindowManager.h"
#include"Slider.h"
using namespace UIfunc;
//git Version

int main() {



	//auto cooldownTime = std::chrono::seconds(3);
	//auto lastActivationTime = std::chrono::steady_clock::now();

	//while (true) {
	//	auto now = std::chrono::steady_clock::now();

	//	if (lastActivationTime + cooldownTime <= now) {
	//		std::cout << "Message printed every 3 seconds" << std::endl;
	//		lastActivationTime = now;
	//	}

	//	std::this_thread::sleep_for(std::chrono::milliseconds(100));
	//}
	//Main Menu Window ------------------------------------------------
	Window mainMenu;

	std::unique_ptr <UIfunc::Button> playButton = std::make_unique<UIfunc::Button>();

	playButton->SetText("som2");
	playButton->SetSize({ 100,50 });
	playButton->SetPosition({ 100.f, 50.f });

	mainMenu.AddComponent(std::move(playButton));


	sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML");

	Button button({ 450.f, 450.f }, { 100.f, 50.f }, sf::Color::Green);
	//---------------------------------------------------------------------
	std::unique_ptr <UIfunc::Slider> SliderVolume = std::make_unique<UIfunc::Slider>(sf::Vector2f{ 650.f, 650.f }, sf::Vector2f{ 100.f , 10.f });
	SliderVolume->setColor(sf::Color::White);


	//SliderVolume.Draw(window);

	//---------------------------------------------------------------------

	Window settingsWindow;

	std::unique_ptr <UIfunc::Button> SoundButton = std::make_unique<UIfunc::Button>();

	// Button sound -> std::unique_ptr <UIfunc::Button> SoundButton 
	// 
	// нада так 	Button button({ 450.f, 450.f }, { 100.f, 50.f }, sf::Color::Green);
	SoundButton->SetText("som");
	SoundButton->SetSize({ 100,50 });
	SoundButton->SetPosition({ 200.f, 50.f });
	

	settingsWindow.AddComponent(std::move(SoundButton));
	mainMenu.AddComponent(std::move(SliderVolume));
	MainMenu MenuButton;


	//---------------------------------------------------------------------
	WindowManager windowManager;

	windowManager.AddWindow("mainMenu", mainMenu);

	windowManager.AddWindow("settingsWindow", settingsWindow);
	windowManager.SetCurrentWindow("mainMenu");
	//windowManager.SetCurrentWindow("settingsWindow");



	int countClickedButton = 0;

	button.setOnClikedCallback([&countClickedButton, &button]() {

		countClickedButton++;
		std::cout << "Button clicked!" << countClickedButton << std::endl;
		button.SetText(std::to_string(countClickedButton));

	});






	while (window.isOpen()) {

		sf::Event event;
		while (window.pollEvent(event)) {

			if (event.type == sf::Event::Closed)
				window.close();

		/*	if (event.key.code == sf::Keyboard::Escape) {
				window.close();

			}
		*/

			if (event.type == sf::Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::E) {

					windowManager.SetCurrentWindow("mainMenu");
				}

			}
			if (event.type == sf::Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::Q) {

					windowManager.SetCurrentWindow("settingsWindow");
				}
			}

		}

		button.Update(window);

		

		window.clear(sf::Color::Black);


		if (countClickedButton == 0)
		{

			button.Draw(window);

		}
		else {
			MenuButton.Draw(window);
		}

		windowManager.Draw(window);
		windowManager.Update(window);

	

	


		window.display();
	}

	return 0;
}
