#pragma once
#include "Window.h"
#include <iostream>
#include <map>

class WindowManager
{
public:
    WindowManager() : mCurrentWindow(nullptr) {} // Инициализация указателя на текущее окно

    // Метод для добавления нового окна
    void AddWindow(const std::string& name, Window& window)
    {
        mWindowList[name] = std::move(window);  // Добавление окна в список
    }

    // Метод для установки текущего активного окна
    void SetCurrentWindow(const std::string& name)
    {
        auto it = mWindowList.find(name);
        if (it != mWindowList.end())
        {
            mCurrentWindow = &it->second;  // Установка указателя на текущее окно
        }
        else
        {
            std::cout << "[ERROR] No window with Name: " << name << std::endl;
        }
    }

    // Отрисовка текущего активного окна
    void Draw(sf::RenderWindow& window) const
    {
        if (mCurrentWindow != nullptr)
        {
            mCurrentWindow->Draw(window);  // Вызов метода отрисовки у текущего окна
        }
    }

    // Обновление текущего активного окна
    void Update(sf::RenderWindow& window) const
    {
        if (mCurrentWindow != nullptr)
        {
            mCurrentWindow->Update(window);  // Вызов метода обновления у текущего окна
        }
    }

private:
    Window* mCurrentWindow;  // Указатель на текущее окно
    std::map<std::string, Window> mWindowList;  // Список окон
};

