#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <memory>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

class Sprite {
    public:
        Sprite();
        ~Sprite();

        void init(const std::string& path, const sf::Vector2f& position, const sf::Vector2f& scale);
        void setScale(const sf::Vector2f& scale);
        void setPosition(const sf::Vector2f& position);
        void draw(std::shared_ptr<sf::RenderWindow> window);

        sf::Vector2f getPosition() const;
        sf::Vector2f getScale() const;
    private:
        sf::Texture _texture;
        sf::Sprite _sprite;
        sf::Vector2f _position;
        sf::Vector2f _scale;
};
