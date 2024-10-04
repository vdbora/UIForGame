#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include<functional>
#include"IUIComponent.hpp"

namespace UIfunc {
	
	class Button:public IUIComponent
	{
		using OnClikedCallback = std::function<void()>;


	public:
		Button();
		Button(sf::Vector2f position, sf::Vector2f size, sf::Color FillColor = sf::Color::White);
		~Button();

		void setOnClikedCallback(OnClikedCallback callback);
		void Update(sf::RenderWindow& window);
		void Draw(sf::RenderWindow& window);
		void SetText(std::string text);
		void SetPosition(sf::Vector2f nPosition);
		void SetSize(sf::Vector2f nSize);
	
	private:
		sf::SoundBuffer buffer;
		sf::Sound sound;
		sf::Text ButtonText;
		sf::Vector2f mPosition;
		sf::Vector2f mSize;
		sf::Color mFillColor;
		sf::Color mHoverColor;
		OnClikedCallback mOnClikedCallback;
		sf::RectangleShape mShape;
		bool isHovered;
		bool isLocked;
		sf::Font Font;
	};
}//!UIfunc

