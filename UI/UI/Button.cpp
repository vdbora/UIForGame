#include "Button.h"
#include <iostream>

namespace UIfunc {

	Button::Button()
		: mFillColor(sf::Color::Blue), mHoverColor(sf::Color::Yellow) {
		mShape.setSize(sf::Vector2f(50, 50));
		mShape.setFillColor(mFillColor);
		mButtonText.setCharacterSize(16);
		mButtonText.setFillColor(sf::Color::White);

		if (!mFont.loadFromFile("C:\\Users\\vd.bora\\Documents\\texture\\roboto\\Roboto-Bold.ttf")) {
			std::cerr << "Error loading font!" << std::endl;
		}
		mButtonText.setFont(mFont);
		SetText("Text");

		if (!mBuffer.loadFromFile("C:\\Users\\vd.bora\\source\\repos\\sfml_start\\sfml_start\\Resource\\Sounds\\Button Click.wav")) {
			std::cerr << "Error loading sound!" << std::endl;
		}
		mSound.setBuffer(mBuffer);
	}

	Button::Button(const sf::Vector2f& position, const sf::Vector2f& size, sf::Color fillColor)
		: mPosition(position), mSize(size), mFillColor(fillColor), mHoverColor(sf::Color::Yellow) {
		mShape.setPosition(mPosition);
		mShape.setSize(mSize);
		mShape.setFillColor(mFillColor);
		mButtonText.setCharacterSize(16);
		mButtonText.setFillColor(sf::Color::Red);

		if (!mFont.loadFromFile("C:\\Users\\vd.bora\\Documents\\texture\\roboto\\Roboto-Bold.ttf")) {
			std::cerr << "Error loading font!" << std::endl;
		}
		mButtonText.setFont(mFont);
		SetText("Text");

		if (!mBuffer.loadFromFile("C:\\Users\\vd.bora\\source\\repos\\sfml_start\\sfml_start\\Resource\\Sounds\\Button Click.wav")) {
			std::cerr << "Error loading sound!" << std::endl;
		}
		mSound.setBuffer(mBuffer);
	}

	void Button::SetOnClickedCallback(const OnClickedCallback& callback) {
		mOnClickedCallback = callback;
	}

	void Button::Update(sf::RenderWindow& window) {
		sf::Vector2i mousePos = sf::Mouse::getPosition(window);
		bool isInside = mShape.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos));

		if (isInside && !mIsHovered) {
			mIsHovered = true;
			mShape.setFillColor(mHoverColor);
		}
		else if (!isInside && mIsHovered) {
			mIsHovered = false;
			mShape.setFillColor(mFillColor);
		}

		if (isInside && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			if (mOnClickedCallback && !mIsLocked) {
				mOnClickedCallback();
				mIsLocked = true;
				mSound.play();
			}
		}
		else {
			mIsLocked = false;
		}
	}

	void Button::Draw(sf::RenderWindow& window) {
		window.draw(mShape);
		window.draw(mButtonText);
	}

	void Button::SetText(const std::string& text) {
		mButtonText.setString(text);
		CenterText();
	}

	void Button::SetSize(const sf::Vector2f& size) {
		mShape.setSize(size);
		CenterText();
	}

	void Button::SetPosition(const sf::Vector2f& position) {
		mShape.setPosition(position);
		CenterText();
	}

	void Button::CenterText() {
		sf::FloatRect textBounds = mButtonText.getGlobalBounds();
		sf::FloatRect shapeBounds = mShape.getGlobalBounds();
		mButtonText.setPosition(
			shapeBounds.left + (shapeBounds.width - textBounds.width) / 2,
			shapeBounds.top + (shapeBounds.height - textBounds.height) / 2
		);
	}

}  // namespace UIfunc
