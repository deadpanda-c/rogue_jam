#pragma once
#include "Scene.hpp"
#include "Sprite/SpriteManager.hpp"

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
};
