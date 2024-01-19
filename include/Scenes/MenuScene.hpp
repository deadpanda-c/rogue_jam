#pragma once
#include "Scene.hpp"

class MenuScene : public Scene {
    public:
        MenuScene();
        ~MenuScene();

        void init();
        void update();
        void draw(std::shared_ptr<sf::RenderWindow> &window);
    private:
};
