#pragma once
#include"PinPongUI.h"
using namespace UIfunc;
//git Version
int main() {
	sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML");

	WindowManager windowManager;

	PinPongUI PingPong;

	PingPong.InitUI(windowManager);

	while (window.isOpen()) {

		sf::Event event;
		while (window.pollEvent(event)) {

			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::KeyPressed) {

				if (event.key.code == sf::Keyboard::E) {

					windowManager.SetCurrentWindow("mainMenu");
				}

				if (event.key.code == sf::Keyboard::Q) {

					windowManager.SetCurrentWindow("settingsWindow");
				}

				if (event.key.code == sf::Keyboard::Escape) {
					window.close();

				}
			}
		}
		window.clear(sf::Color::Black);

		windowManager.Draw(window);

		windowManager.Update(window);

		window.display();
	}
	return 0;
}
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
// 
