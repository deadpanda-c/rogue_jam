/*
** EPITECH PROJECT, 2024
** rogue_jam
** File description:
** DungeonManager
*/

#ifndef DUNGEONMANAGER_HPP_
#define DUNGEONMANAGER_HPP_

#include <memory>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include "Dungeon.hpp"

class DungeonManager {
    public:
        DungeonManager();
        ~DungeonManager();
        void addDungeon(const std::string &name, std::shared_ptr<Dungeon> Dungeon);
        void removeDungeon(const std::string &name);
        void changeDungeon(const std::string &name);
        std::string getCurrentDungeonName() const;
        void update(std::shared_ptr<sf::RenderWindow> &window, std::string &Dungeon);
        void draw(std::shared_ptr<sf::RenderWindow> &window);
    protected:
    private:
        std::pair<std::shared_ptr<Dungeon>, std::string> _currentDungeon;
        std::map<std::string, std::shared_ptr<Dungeon>> _dungeons;
};

#endif /* !DUNGEONMANAGER_HPP_ */
