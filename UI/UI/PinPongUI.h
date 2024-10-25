#pragma once
#include "Button.h"
#include "MainMenu.h"
#include <iostream>
#include "WindowManager.h"
#include "Slider.h"

namespace UIfunc {
	struct PinPongUI
	{
		// Инициализация UI
		void InitUI(WindowManager& windowManager) {
			MainMenu(windowManager);      // Инициализация главного меню
			SettingMenu(windowManager);   // Инициализация меню настроек
			windowManager.SetCurrentWindow("mainMenu");  // Установка активного окна как "mainMenu"
		}

		// Метод для создания главного меню
		void MainMenu(WindowManager& windowManager) {
			Window mainMenu;  // Создание окна главного меню

			// Создание кнопки "Play"
			std::unique_ptr<UIfunc::Button> playButton = std::make_unique<UIfunc::Button>();
			playButton->SetText("Play");  // Текст кнопки
			playButton->SetSize({ 100, 50 });  // Размер кнопки
			playButton->SetPosition({ 100.f, 50.f });  // Позиция кнопки

			mainMenu.AddComponent(std::move(playButton));  // Добавление кнопки в главное меню
			windowManager.AddWindow("mainMenu", mainMenu);  // Добавление главного меню в менеджер окон
		}

		// Метод для создания меню настроек
		void SettingMenu(WindowManager& windowManager) {
			Window settingsWindow;  // Создание окна настроек

			// Создание слайдера громкости
			std::unique_ptr<UIfunc::Slider> volumeSlider = std::make_unique<UIfunc::Slider>(
				sf::Vector2f{ 650.f, 650.f }, sf::Vector2f{ 100.f, 10.f }
			);
			volumeSlider->setColor(sf::Color::White);  // Установка цвета слайдера

			// Установка обратного вызова для изменения значения слайдера
			volumeSlider->SetOnChanged([](long value) {
				std::cout << "Volume: " << value << std::endl;  // Вывод значения громкости в консоль
				});

			settingsWindow.AddComponent(std::move(volumeSlider));  // Добавление слайдера в окно настроек
			windowManager.AddWindow("settingsWindow", settingsWindow);  // Добавление окна настроек в менеджер окон
		}
	};
}
