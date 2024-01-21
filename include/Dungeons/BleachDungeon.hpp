/*
** EPITECH PROJECT, 2024
** rogue_jam
** File description:
** BleachDungeon
*/

#ifndef BLEACHDUNGEON_HPP_
#define BLEACHDUNGEON_HPP_

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

#endif /* !BLEACHDUNGEON_HPP_ */
