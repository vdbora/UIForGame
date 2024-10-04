#pragma once
#include<SFML/Graphics.hpp>
class IUIComponent
{
public:
	virtual ~IUIComponent() = default;

	virtual void Update(sf::RenderWindow& window) = 0;
	virtual void Draw(sf::RenderWindow& window) = 0;
};