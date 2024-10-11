#pragma once
#include "MainMenu.h"
#include<iostream>
#include"WindowManager.h"
#include<SFML/Graphics.hpp>
namespace UIfunc {
	class Slider : public IUIComponent
	{

	public:
		Slider() {}
		long map(long value, long fromLow, long fromHigh, long toLow, long toHigh) {
			return ((value - fromLow) * (toHigh - toLow) / (fromHigh - fromLow) + toLow);
		}
		// +20 END

		Slider(sf::Vector2f Position, sf::Vector2f Size) {
			setSize(Size);
			setPosition(Position);
		}

		void Draw(sf::RenderWindow& window) override {
			window.draw(mHandle);
			window.draw(RectangleBackGround);
			window.draw(RectangleToFill);
		}
		void Update(sf::RenderWindow& window) override {


			sf::Vector2i mousePos = sf::Mouse::getPosition(window);
			if (mHandle.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)) &&
				sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				if (mousePos.x < RectangleBackGround.getPosition().x + RectangleBackGround.getSize().x - mHandle.getRadius() && mousePos.x > RectangleBackGround.getPosition().x - mHandle.getRadius()) {

					//mHandle.setPosition(mousePos.x , mPosition.y);
					mHandle.setPosition(mousePos.x - 3, mPosition.y - (mHandle.getRadius()));
					

					std::cout<< map(mHandle.getPosition().x, RectangleBackGround.getPosition().x - mHandle.getRadius(), RectangleBackGround.getPosition().x + RectangleBackGround.getSize().x - mHandle.getRadius(), 0, 100)<<std::endl;
					//- mHandle.getRadius() --
				}
			}
		};


		//дял звука Get valume



		//if (mousePos.x < mHandle.getPosition().x +( mHandle.getRadius()*2) && mousePos.x > mHandle.getPosition().x) { std::cout << "gg";
		//mHandle.setPosition(mousePos.x , mPosition.y);
		//mHandle.setPosition(mousePos.x - 3, mPosition.y - (mHandle.getRadius()));//
		//}

		sf::Vector2f getPosition() {

			return sf::Vector2f(mHandle.getPosition().x, mPosition.y);

		}



		void setSize(sf::Vector2f Size) {

			float divided = (Size.y / 3);
			mHandle.setRadius(Size.x / 6);
			RectangleBackGround.setSize(sf::Vector2f(Size.x, divided + (Size.y / 6)));
			RectangleToFill.setSize(sf::Vector2f(Size.x, divided + (Size.y / 6)));
		}
		void setPosition(sf::Vector2f Position) {

			mPosition = Position;
			mHandle.setPosition(Position.x, mPosition.y - (mHandle.getRadius()));
			RectangleBackGround.setPosition(Position);
			RectangleToFill.setPosition(Position);

		}
		void setColor(sf::Color FillColor) {
			mHandle.setFillColor(sf::Color::Green);
			RectangleBackGround.setFillColor(sf::Color::Red);
			RectangleToFill.setFillColor(sf::Color::Green);
		}

	private:
		sf::CircleShape mHandle;
		sf::RectangleShape RectangleBackGround;
		sf::RectangleShape RectangleToFill;

		sf::Vector2u mSoundScale;
		sf::Vector2f mPosition;
		sf::Vector2f mSize;
		sf::Color mFillColor;
		
	};
}
