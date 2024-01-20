#pragma once
#include "Scene.hpp"
#include "Sprite/SpriteManager.hpp"
#include "Text/TextManager.hpp"

#define DEFAULT_PLAY_BTN "../assets/img/play_default.png"
#define HOVER_PLAY_BTN "../assets/img/play_hover.png"

#define BACKGROUND_MENU "../assets/img/menu.png"

#define TITLE_FONT "../assets/fonts/PERRYGOT.TTF"

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
        TextManager _textManager;
        bool _isHoverPlayBtn;
};
