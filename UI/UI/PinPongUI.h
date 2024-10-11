#pragma once
#include"Button.h"
#include"MainMenu.h"
#include<iostream>
#include"WindowManager.h"
#include"Slider.h"
namespace UIfunc {
	struct PinPongUI
	{
		void InitUI(WindowManager& windowManager) {
			MainMenu(windowManager);
			SettingMenu(windowManager);
			windowManager.SetCurrentWindow("mainMenu");

		}

		void MainMenu(WindowManager& windowManager) {
			//Main Menu Window ------------------------------------------------
			Window mainMenu;

			//Button button({ 450.f, 450.f }, { 100.f, 50.f }, sf::Color::Green);

			std::unique_ptr <UIfunc::Button> playButton = std::make_unique<UIfunc::Button>();


			playButton->SetText("s");
			playButton->SetSize({ 100,50 });
			playButton->SetPosition({ 100.f, 50.f });



			mainMenu.AddComponent(std::move(playButton));

			windowManager.AddWindow("mainMenu", mainMenu);

			//windowManager.SetCurrentWindow("mainMenu");






			//button.setOnClikedCallback([]() {});

		}
		void SettingMenu(WindowManager& windowManager) {

			Window settingsWindow;


			// Button sound -> std::unique_ptr <UIfunc::Button> SoundButton 
			// 
			// нада так 	Button button({ 450.f, 450.f }, { 100.f, 50.f }, sf::Color::Green);


			windowManager.AddWindow("settingsWindow", settingsWindow);

			//---------------------------------------------------------------------
			std::unique_ptr <UIfunc::Slider> SliderVolume = std::make_unique<UIfunc::Slider>(sf::Vector2f{ 650.f, 650.f }, sf::Vector2f{ 100.f , 10.f });
			SliderVolume->setColor(sf::Color::White);

			SliderVolume->SetOnChanged([](long value) {

				std::cout << value << std::endl;
				});
			settingsWindow.AddComponent(std::move(SliderVolume));
		}


	};
}