#pragma once
#include"Window.h"
#include<iostream>

class WindowManager
{

public:
	void AddWindow(const std::string& name,Window& window)
	{
		mWindowList[name] = std::move(window);
	}

	void SetCurrentWindow(const std::string& name)
	{
		auto it = mWindowList.find(name);
		if (it !=mWindowList.end())
		{
			mCurrentWindow = &it->second;
		}
		else
		{
			std::cout << "[ERROR] No window with Name: "<<name<< std::endl;
		}
	}
	void Draw(sf::RenderWindow& window)
	{
		if (mCurrentWindow != nullptr)
		{
			mCurrentWindow->Draw(window);
		}
	}	

	void Update(sf::RenderWindow& window)
	{
		if (mCurrentWindow != nullptr)
		{
			mCurrentWindow->Update(window);
		}
	}

private:

	Window* mCurrentWindow;

	std::map<std::string,Window>mWindowList;



};

