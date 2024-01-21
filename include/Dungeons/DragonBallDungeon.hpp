/*
** EPITECH PROJECT, 2024
** rogue_jam
** File description:
** DragonBallDungeon
*/

#pragma once

#include "Dungeon.hpp"

class DragonBallDungeon : public Scene {
    public:
        DragonBallDungeon();
        ~DragonBallDungeon();

        void init() ;
        void update(std::shared_ptr<sf::RenderWindow> &window, std::string &dungeon) ;
        void handleEvent(std::shared_ptr<sf::RenderWindow> &window, std::string &dungeon) ;
        void draw(std::shared_ptr<sf::RenderWindow> &window) ;
    protected:
    private:
};

