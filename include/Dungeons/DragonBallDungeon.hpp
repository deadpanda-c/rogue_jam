/*
** EPITECH PROJECT, 2024
** rogue_jam
** File description:
** DragonBallDungeon
*/

#ifndef DRAGONBALLDUNGEON_HPP_
#define DRAGONBALLDUNGEON_HPP_

#include "Dungeon.hpp"

class DragonBallDungeon : public Dungeon {
    public:
        DragonBallDungeon();
        ~DragonBallDungeon();

        void init() override;
        void update(std::shared_ptr<sf::RenderWindow> &window, std::string &dungeon) override;
        void handleEvent(std::shared_ptr<sf::RenderWindow> &window, std::string &dungeon) override;
        void draw(std::shared_ptr<sf::RenderWindow> &window) override;
    protected:
    private:
};

#endif /* !DRAGONBALLDUNGEON_HPP_ */
