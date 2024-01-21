/*
** EPITECH PROJECT, 2024
** rogue_jam
** File description:
** BleachDungeon
*/

#pragma once

#include "Dungeon.hpp"

class BleachDungeon : public Dungeon {
    public:
        BleachDungeon();
        ~BleachDungeon();

        void init() override;
        void update(std::shared_ptr<sf::RenderWindow> &window, std::string &dungeon) override;
        void handleEvent(std::shared_ptr<sf::RenderWindow> &window, std::string &dungeon) override;
        void draw(std::shared_ptr<sf::RenderWindow> &window) override;
    protected:
    private:
};
