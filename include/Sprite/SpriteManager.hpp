#pragma once
#include <map>
#include <iostream>
#include <string>
#include <memory>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include "Sprite.hpp"

class SpriteManager {
    public:
        SpriteManager();
        ~SpriteManager();

        void addSprite(const std::string &name, const std::string &path);
        void removeSprite(const std::string &name);

        void draw(std::shared_ptr<sf::RenderWindow> &window);
        size_t getNbSprites() const;
        std::shared_ptr<Sprite> getSprite(const std::string &name) const;
    private:
        std::map<std::string, std::shared_ptr<Sprite>> _sprites;
};
