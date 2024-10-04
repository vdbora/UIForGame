#pragma once
#include "Button.h"

class MainMenu
{
	
public:
MainMenu();
~MainMenu();


void Draw(sf::RenderWindow& window);

private:

	UIfunc::Button Start;
	UIfunc::Button Shop;
	UIfunc::Button Setting;
	UIfunc::Button Exit;

};

