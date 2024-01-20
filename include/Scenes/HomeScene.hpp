#pragma once
#include "Scene.hpp"

#include "Sprite/SpriteManager.hpp"
#include "Text/TextManager.hpp"

#define HOME_MAP "../assets/img/home.png"

class HomeScene : public Scene {
    public:
        HomeScene();
        ~HomeScene();

        void init();
        void update(std::shared_ptr<sf::RenderWindow> &window, std::string &scene);
        void draw(std::shared_ptr<sf::RenderWindow> &window);
        void handleEvent(std::shared_ptr<sf::RenderWindow> &window, std::string &scene);
    private:
        SpriteManager _spriteManager;
        TextManager _textManager;
};
