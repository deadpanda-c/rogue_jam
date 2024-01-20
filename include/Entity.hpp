#pragma once

#include <string>
#include <iostream>
#include <memory>
#include <map>

#include "Sprite/SpriteManager.hpp"

class Entity {
    public:
        Entity();
        Entity(const std::string &filename);
        virtual ~Entity() = default;

        virtual void init() = 0;
        virtual void update(sf::Event &event) = 0;
        virtual void draw(std::shared_ptr<sf::RenderWindow> &window) = 0;

        void setFilename(const std::string &filename);
        void setHealth(int health);
        void setShield(int shield);

        int getHealth() const;
        int getShield() const;
    protected:
        SpriteManager _spriteManager;
        std::string _filename;
        int _health;
        int _shield;
};
