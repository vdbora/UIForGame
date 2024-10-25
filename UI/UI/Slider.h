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
		// ����������� �� ���������
		Slider() = default;

		// ����� map: ��������� �������� �� ������ ��������� � ������
		long map(long value, long fromLow, long fromHigh, long toLow, long toHigh) {
			return ((value - fromLow) * (toHigh - toLow) / (fromHigh - fromLow) + toLow);
		}

		// ����������� � �������� � ��������
		Slider(sf::Vector2f Position, sf::Vector2f Size) {
			setSize(Size);
			setPosition(Position);
		}

		// ����� ��������� ��������
		void Draw(sf::RenderWindow& window) override {
			window.draw(mHandle);
			window.draw(RectangleBackGround);
			window.draw(RectangleToFill);
		}

		// ����� ���������� ��������� ��������
		void Update(sf::RenderWindow& window) override {
			sf::Vector2i mousePos = sf::Mouse::getPosition(window);

			// �������� ������� �� �������� � ��� �����������
			if (mHandle.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				float backgroundLeft = RectangleBackGround.getPosition().x;
				float backgroundRight = backgroundLeft + RectangleBackGround.getSize().x;

				// ����������� ����������� �������� ������ ����
				if (mousePos.x > backgroundLeft && mousePos.x < backgroundRight) {
					mHandle.setPosition(mousePos.x - mHandle.getRadius(), mPosition.y - mHandle.getRadius());

					// ���������� �������� �������� � ����� ��������� ������
					long mappedValue = map(mHandle.getPosition().x + mHandle.getRadius(),
						backgroundLeft, backgroundRight, 0, 100);
					mOnChangedCallback(mappedValue);
				}
			}
		}

		// ����� ��������� ��������� ������ ��� ��������� ��������
		void SetOnChanged(OnChangedCallback callback) {
			mOnChangedCallback = callback;
		}

		// ����� ��������� ������� ��������
		sf::Vector2f getPosition() {
			return sf::Vector2f(mHandle.getPosition().x, mPosition.y);
		}

		// ����� ��������� �������
		void setSize(sf::Vector2f Size) {
			float divided = Size.y / 3.0f;
			mHandle.setRadius(Size.x / 6.0f);
			RectangleBackGround.setSize(sf::Vector2f(Size.x, divided + (Size.y / 6.0f)));
			RectangleToFill.setSize(sf::Vector2f(Size.x, divided + (Size.y / 6.0f)));
		}

		// ����� ��������� �������
		void setPosition(sf::Vector2f Position) {
			mPosition = Position;
			mHandle.setPosition(Position.x, mPosition.y - mHandle.getRadius());
			RectangleBackGround.setPosition(Position);
			RectangleToFill.setPosition(Position);
		}

		// ����� ��������� �����
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

//��� ����������� �� ���������