/*
** EPITECH PROJECT, 2024
** rogue_jam
** File description:
** DragonBallDungeon
*/

#include "Dungeons/DragonBallDungeon.hpp"

DragonBallDungeon::DragonBallDungeon()
{
}

DragonBallDungeon::~DragonBallDungeon()
{
}

void DragonBallDungeon::init() {

}

void DragonBallDungeon::handleEvent(std::shared_ptr<sf::RenderWindow> &window, std::string &scene)
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
void DragonBallDungeon::update(std::shared_ptr<sf::RenderWindow> &window, std::string &dungeon)
{
    window->clear();
    handleEvent(window, dungeon);
}


void DragonBallDungeon::draw(std::shared_ptr<sf::RenderWindow> &window) {

}
