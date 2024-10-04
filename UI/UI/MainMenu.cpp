
#include "MainMenu.h"
#include "Button.h"

MainMenu::MainMenu() {
	//Start = UIfunc::Button({ 450.f, 250.f }, { 100.f, 50.f }, sf::Color::Green);
	//Shop = UIfunc::Button({ 450.f, 310.f }, { 100.f, 50.f }, sf::Color::Green);
	//Setting = UIfunc::Button({ 450.f, 370.f }, { 100.f, 50.f }, sf::Color::Green);
	//Exit = UIfunc::Button({ 450.f, 430.f }, { 100.f, 50.f }, sf::Color::Green);



	Start.SetPosition({ 450.f, 250.f });
	Shop.SetPosition({ 450.f, 310.f });
	Setting.SetPosition({ 450.f, 370.f });
	Exit.SetPosition({ 450.f, 430.f });

	Start.SetSize({ 100.f, 50.f });
	Shop.SetSize({ 100.f, 50.f });
	Setting.SetSize({ 100.f, 50.f });
	Exit.SetSize({ 100.f, 50.f });


	Start.SetText("Start");
	Shop.SetText("Shop");
	Setting.SetText("Setting");
	Exit.SetText("Exit");


}


MainMenu::~MainMenu() {}


void MainMenu::Draw(sf::RenderWindow& window)
{


	Start.Draw(window);
	Shop.Draw(window);
	Setting.Draw(window);
	Exit.Draw(window);

}