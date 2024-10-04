#include "Button.h"
#include<iostream>
namespace UIfunc {
	Button::Button():mHoverColor(sf::Color::Yellow ),mFillColor(sf::Color::Blue) {
		mShape.setPosition(0, 0);
		mShape.setFillColor(sf::Color::Red);
		mShape.setSize(sf::Vector2f(50, 50));
		ButtonText.setPosition(mShape.getPosition());
		ButtonText.setCharacterSize(16);
		ButtonText.setFillColor(sf::Color::White);
		Font.loadFromFile("C:\\Users\\vd.bora\\Documents\\texture\\roboto\\Roboto-Bold.ttf");
		ButtonText.setFont(Font);
		ButtonText.setString("TexT");
		ButtonText.setPosition(mShape.getPosition().x + mShape.getGlobalBounds().width / 2 - ButtonText.getGlobalBounds().width / 2, mShape.getPosition().y + mShape.getGlobalBounds().height / 2 - ButtonText.getGlobalBounds().height);
		if (!buffer.loadFromFile("C:\\Users\\vd.bora\\source\\repos\\sfml_start\\sfml_start\\Resource\\Sounds\\Button Click.wav")) {
			std::cerr << "Error loading sound!" << std::endl;
		}
		sound.setBuffer(buffer);
	}
	Button::Button(sf::Vector2f position, sf::Vector2f size, sf::Color fillColor)
		: mPosition(position), mSize(size), mFillColor(fillColor), mHoverColor(sf::Color::Yellow), isHovered(false), mShape(size), isLocked(false) {
		mShape.setPosition(mPosition);
		mShape.setFillColor(mFillColor);
		ButtonText.setPosition(mShape.getPosition());
		ButtonText.setCharacterSize(16);
		ButtonText.setFillColor(sf::Color::Red);
		Font.loadFromFile("C:\\Users\\vd.bora\\Documents\\texture\\roboto\\Roboto-Bold.ttf");
		ButtonText.setFont(Font);
		ButtonText.setString("TexT");
		ButtonText.setPosition(mShape.getPosition().x + mShape.getGlobalBounds().width / 2 - ButtonText.getGlobalBounds().width / 2, mShape.getPosition().y + mShape.getGlobalBounds().height / 2 - ButtonText.getGlobalBounds().height);
		if (!buffer.loadFromFile("C:\\Users\\vd.bora\\source\\repos\\sfml_start\\sfml_start\\Resource\\Sounds\\Button Click.wav")) {
			std::cerr << "Error loading sound!" << std::endl;
		}
		sound.setBuffer(buffer);
	}
	Button::~Button() {}

	void Button::setOnClikedCallback(OnClikedCallback callback)
	{
		mOnClikedCallback = callback;
	
	}

	void Button::Update(sf::RenderWindow& window)
	{
		sf::Vector2i mousePos = sf::Mouse::getPosition(window);

		if (mShape.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
			if (!isHovered) {
				isHovered = true;
				mShape.setFillColor(mHoverColor);
			}

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				if (mOnClikedCallback && isLocked == false) {
					mOnClikedCallback();
					isLocked = true;
					sound.play();
				}
			}
			else
			{
				isLocked = false;
			}
		}
		else {
			if (isHovered) {
				isHovered = false;
				mShape.setFillColor(mFillColor);
			}
		}
	}

	void Button::Draw(sf::RenderWindow& window)
	{
		window.draw(mShape);
		window.draw(ButtonText);

	}

	void Button::SetText(std::string text)
	{
		ButtonText.setString(text);
		ButtonText.setPosition(mShape.getPosition().x + mShape.getGlobalBounds().width / 2 - ButtonText.getGlobalBounds().width / 2, mShape.getPosition().y + mShape.getGlobalBounds().height / 2 - ButtonText.getGlobalBounds().height);

	}
	void Button::SetSize(sf::Vector2f nSize)
	{
		mShape.setSize(nSize);
		ButtonText.setPosition(mShape.getPosition().x + mShape.getGlobalBounds().width / 2 - ButtonText.getGlobalBounds().width / 2, mShape.getPosition().y + mShape.getGlobalBounds().height / 2 - ButtonText.getGlobalBounds().height);

	}
	void Button::SetPosition(sf::Vector2f nPosition)
	{
		mShape.setPosition(nPosition);
		ButtonText.setPosition(mShape.getPosition().x + mShape.getGlobalBounds().width / 2 - ButtonText.getGlobalBounds().width / 2, mShape.getPosition().y + mShape.getGlobalBounds().height / 2 - ButtonText.getGlobalBounds().height);

	}
}