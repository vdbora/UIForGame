#pragma once
#include<list>
#include<map>
#include<memory>
#include"IUIComponent.hpp"

class Window
{
public:

	void AddComponent(std::unique_ptr<IUIComponent> component)
	{
		mComponentList.push_back(std::move(component));
	}

	void Draw(sf::RenderWindow& window)
	{
		for (auto& component :mComponentList)
		{
			component->Draw(window);
		}
	}
	void Update(sf::RenderWindow& window)
	{
		for (auto& component :mComponentList)
		{
			component->Update(window);
		}
	}

private:

	std::list<std::unique_ptr<IUIComponent>>mComponentList;

};

