#pragma once
#include "Scene.hpp"

class GameScene : public Scene {
    public:
        GameScene();
        ~GameScene();

        void init();
        void update(std::shared_ptr<sf::RenderWindow> &window, std::string &scene);
        void draw(std::shared_ptr<sf::RenderWindow> &window);
        void handleEvent(std::shared_ptr<sf::RenderWindow> &window, std::string &scene);
    private:
};
