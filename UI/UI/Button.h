#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <functional>
#include "IUIComponent.hpp"

namespace UIfunc {

	class Button : public IUIComponent {
		using OnClickedCallback = std::function<void()>;

	public:
		Button();
		Button(const sf::Vector2f& position, const sf::Vector2f& size, sf::Color fillColor = sf::Color::White);
		~Button() = default;

		void SetOnClickedCallback(const OnClickedCallback& callback);
		void Update(sf::RenderWindow& window);
		void Draw(sf::RenderWindow& window);
		void SetText(const std::string& text);
		void SetPosition(const sf::Vector2f& position);
		void SetSize(const sf::Vector2f& size);

	private:
		void CenterText();

		sf::SoundBuffer mBuffer;
		sf::Sound mSound;
		sf::Text mButtonText;
		sf::RectangleShape mShape;
		sf::Font mFont;

		sf::Vector2f mPosition;
		sf::Vector2f mSize;
		sf::Color mFillColor;
		sf::Color mHoverColor;

		OnClickedCallback mOnClickedCallback;

		bool mIsHovered = false;
		bool mIsLocked = false;
	};

}  // namespace UIfunc
