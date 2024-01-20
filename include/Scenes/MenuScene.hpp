#pragma once
#include "Scene.hpp"
#include "Sprite/SpriteManager.hpp"

#define DEFAULT_PLAY_BTN "../assets/play_default.png"
#define HOVER_PLAY_BTN "../assets/play_hover.png"

class MenuScene : public Scene {
    public:
        MenuScene();
        ~MenuScene();

        void init();
        void update(std::shared_ptr<sf::RenderWindow> &window, std::string &scene);
        void draw(std::shared_ptr<sf::RenderWindow> &window);
        void handleEvent(std::shared_ptr<sf::RenderWindow> &window, std::string &scene);
    private:
        SpriteManager _spriteManager;
        bool _isHoverPlayBtn;
};
