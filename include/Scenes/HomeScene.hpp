#pragma once
#include "Scene.hpp"
#include "Player.hpp"

#include "Sprite/SpriteManager.hpp"
#include "Text/TextManager.hpp"

#define HOME_MAP "../assets/img/home.png"

#define FONT_TEXT  "../assets/fonts/PERRYGOT.TTF"
#define ARIAL_FONT "../assets/fonts/Arial.ttf"

#define ONEPIECE 0
#define DRAGONBALL 1
#define ASSASSINATION_CLASSROOM 2
#define BLEACH 3

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
        TextManager _entranceTextManager;
        TextManager _dungeonTextManager;
        Player _player;
        int _currentIndex;
};
