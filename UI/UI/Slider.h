#pragma once
#include "MainMenu.h"
#include <iostream>
#include "WindowManager.h"
#include <SFML/Graphics.hpp>

namespace UIfunc {
	class Slider : public IUIComponent
	{
		using OnChangedCallback = std::function<void(long)>;

	public:
		// Конструктор по умолчанию
		Slider() = default;

		// Метод map: переводит значение из одного диапазона в другой
		long map(long value, long fromLow, long fromHigh, long toLow, long toHigh) {
			return ((value - fromLow) * (toHigh - toLow) / (fromHigh - fromLow) + toLow);
		}

		// Конструктор с позицией и размером
		Slider(sf::Vector2f Position, sf::Vector2f Size) {
			setSize(Size);
			setPosition(Position);
		}

		// Метод отрисовки ползунка
		void Draw(sf::RenderWindow& window) override {
			window.draw(mHandle);
			window.draw(RectangleBackGround);
			window.draw(RectangleToFill);
		}

		// Метод обновления состояния ползунка
		void Update(sf::RenderWindow& window) override {
			sf::Vector2i mousePos = sf::Mouse::getPosition(window);

			// Проверка нажатия на ползунок и его перемещение
			if (mHandle.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				float backgroundLeft = RectangleBackGround.getPosition().x;
				float backgroundRight = backgroundLeft + RectangleBackGround.getSize().x;

				// Ограничение перемещения ползунка внутри фона
				if (mousePos.x > backgroundLeft && mousePos.x < backgroundRight) {
					mHandle.setPosition(mousePos.x - mHandle.getRadius(), mPosition.y - mHandle.getRadius());

					// Вычисление текущего значения и вызов обратного вызова
					long mappedValue = map(mHandle.getPosition().x + mHandle.getRadius(),
						backgroundLeft, backgroundRight, 0, 100);
					mOnChangedCallback(mappedValue);
				}
			}
		}

		// Метод установки обратного вызова при изменении значения
		void SetOnChanged(OnChangedCallback callback) {
			mOnChangedCallback = callback;
		}

		// Метод получения позиции ползунка
		sf::Vector2f getPosition() {
			return sf::Vector2f(mHandle.getPosition().x, mPosition.y);
		}

		// Метод установки размера
		void setSize(sf::Vector2f Size) {
			float divided = Size.y / 3.0f;
			mHandle.setRadius(Size.x / 6.0f);
			RectangleBackGround.setSize(sf::Vector2f(Size.x, divided + (Size.y / 6.0f)));
			RectangleToFill.setSize(sf::Vector2f(Size.x, divided + (Size.y / 6.0f)));
		}

		// Метод установки позиции
		void setPosition(sf::Vector2f Position) {
			mPosition = Position;
			mHandle.setPosition(Position.x, mPosition.y - mHandle.getRadius());
			RectangleBackGround.setPosition(Position);
			RectangleToFill.setPosition(Position);
		}

		// Метод установки цвета
		void setColor(sf::Color FillColor) {
			mHandle.setFillColor(sf::Color::Green);
			RectangleBackGround.setFillColor(sf::Color::Red);
			RectangleToFill.setFillColor(sf::Color::Green);
		}

	private:
		sf::CircleShape mHandle;
		sf::RectangleShape RectangleBackGround;
		sf::RectangleShape RectangleToFill;
		OnChangedCallback mOnChangedCallback;
		sf::Vector2f mPosition;
	};
}
//	SliderVolume->SetOnChanged([](long value) {		
//std::cout << value << std::endl;});

//гпт рефвкторинг та пояснення