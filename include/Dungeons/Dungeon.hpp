/*
** EPITECH PROJECT, 2024
** rogue_jam
** File description:
** Dungeon
*/

#ifndef DUNGEON_HPP_
#define DUNGEON_HPP_
#include <string>
#include <iostream>
#include <memory>
#include <map>
#include "Scenes/Scene.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>


class Dungeon : public Scene {
    public:
        Dungeon();
        ~Dungeon();

        void init();
        void update(std::shared_ptr<sf::RenderWindow> &window, std::string &dungeon);
        void handleEvent(std::shared_ptr<sf::RenderWindow> &window, std::string &dungeon);
        void draw(std::shared_ptr<sf::RenderWindow> &window);
    protected:
    private:
};

#endif /* !DUNGEON_HPP_ */
