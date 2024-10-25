#pragma once
#include "Button.h"
#include "MainMenu.h"
#include <iostream>
#include "WindowManager.h"
#include "Slider.h"

namespace UIfunc {
	struct PinPongUI
	{
		// ������������� UI
		void InitUI(WindowManager& windowManager) {
			MainMenu(windowManager);      // ������������� �������� ����
			SettingMenu(windowManager);   // ������������� ���� ��������
			windowManager.SetCurrentWindow("mainMenu");  // ��������� ��������� ���� ��� "mainMenu"
		}

		// ����� ��� �������� �������� ����
		void MainMenu(WindowManager& windowManager) {
			Window mainMenu;  // �������� ���� �������� ����

			// �������� ������ "Play"
			std::unique_ptr<UIfunc::Button> playButton = std::make_unique<UIfunc::Button>();
			playButton->SetText("Play");  // ����� ������
			playButton->SetSize({ 100, 50 });  // ������ ������
			playButton->SetPosition({ 100.f, 50.f });  // ������� ������

			mainMenu.AddComponent(std::move(playButton));  // ���������� ������ � ������� ����
			windowManager.AddWindow("mainMenu", mainMenu);  // ���������� �������� ���� � �������� ����
		}

		// ����� ��� �������� ���� ��������
		void SettingMenu(WindowManager& windowManager) {
			Window settingsWindow;  // �������� ���� ��������

			// �������� �������� ���������
			std::unique_ptr<UIfunc::Slider> volumeSlider = std::make_unique<UIfunc::Slider>(
				sf::Vector2f{ 650.f, 650.f }, sf::Vector2f{ 100.f, 10.f }
			);
			volumeSlider->setColor(sf::Color::White);  // ��������� ����� ��������

			// ��������� ��������� ������ ��� ��������� �������� ��������
			volumeSlider->SetOnChanged([](long value) {
				std::cout << "Volume: " << value << std::endl;  // ����� �������� ��������� � �������
				});

			settingsWindow.AddComponent(std::move(volumeSlider));  // ���������� �������� � ���� ��������
			windowManager.AddWindow("settingsWindow", settingsWindow);  // ���������� ���� �������� � �������� ����
		}
	};
}
