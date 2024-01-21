/*
** EPITECH PROJECT, 2024
** rogue_jam
** File description:
** BleachDungeon
*/

#include "Dungeons/BleachDungeon.hpp"

BleachDungeon::BleachDungeon()
{
}

BleachDungeon::~BleachDungeon()
{
}

void BleachDungeon::init() {

}

void BleachDungeon::handleEvent(std::shared_ptr<sf::RenderWindow> &window, std::string &scene)
{
    sf::Event event;

    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window->close();
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Escape)
                window->close();
            if (event.key.code == sf::Keyboard::Space)
                scene = "game";
        }
    }
}

void BleachDungeon::update(std::shared_ptr<sf::RenderWindow> &window, std::string &dungeon)
{
    window->clear();
    handleEvent(window, dungeon);
}

void BleachDungeon::draw(std::shared_ptr<sf::RenderWindow> &window) {

}
