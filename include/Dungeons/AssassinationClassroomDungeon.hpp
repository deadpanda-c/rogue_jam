/*
** EPITECH PROJECT, 2024
** rogue_jam
** File description:
** AssassinationClassroomDungeon
*/

#pragma once
#include "Dungeon.hpp"

class AssassinationClassroomDungeon : public Dungeon {
    public:
        AssassinationClassroomDungeon();
        ~AssassinationClassroomDungeon();

        void init() override;
        void update(std::shared_ptr<sf::RenderWindow> &window, std::string &dungeon) override;
        void handleEvent(std::shared_ptr<sf::RenderWindow> &window, std::string &dungeon) override;
        void draw(std::shared_ptr<sf::RenderWindow> &window) override;
    protected:
    private:
};

