#pragma once
#include <string>
#include <iostream>
#include <memory>
#include <map>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>

class Scene {
    public:
        Scene();
        virtual ~Scene() = default;

        virtual void init() = 0;
        virtual void update() = 0;
        virtual void draw(std::shared_ptr<sf::RenderWindow> &window) = 0;
};
