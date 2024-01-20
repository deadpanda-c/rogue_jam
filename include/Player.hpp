#pragma once

#include "Entity.hpp"

class Player : public Entity {
    public:
        Player();
        Player(const std::string &filename);
        ~Player();

        void init();
        void update(sf::Event &event);
        void draw(std::shared_ptr<sf::RenderWindow> &window);

        void setScale(const sf::Vector2f &scale);
        void setPosition(const sf::Vector2f &scale);
    private:
};
