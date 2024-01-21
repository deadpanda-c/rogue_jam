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


        void addAnimation(const std::string &animationName, std::string &spriteName, std::vector<sf::IntRect> &frames, float time);
        void playAnimation(const std::string &animationName, int size);
        void addSprite(const std::string &name, const std::string &path);
        void removeSprite(const std::string &name);

        void draw(std::shared_ptr<sf::RenderWindow> &window);
        void draw(std::shared_ptr<sf::RenderWindow> &window, const std::string &name);
        size_t getNbSprites() const;
        std::shared_ptr<Sprite> getSprite(const std::string &name) const;
    private:
        std::map<std::string, std::shared_ptr<Sprite>> _sprites;
        std::map<std::string, std::pair<std::string, std::vector<sf::IntRect>>> _animations;
        std::map<std::string, std::pair<sf::Clock, float>> _clocks;
        std::string _currentAnimation;
};
