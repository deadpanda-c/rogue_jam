#include "Dungeons/DungeonManager.hpp"

DungeonManager::DungeonManager()
{
    //ctor
}

DungeonManager::~DungeonManager()
{
    //dtor
}

void DungeonManager::addDungeon(const std::string &name, std::shared_ptr<Dungeon> dungeon)
{
    if (_dungeons.find(name) != _dungeons.end())
        throw std::runtime_error("Dungeon already exists");
    _dungeons[name] = dungeon;
    _dungeons[name]->init();
}

void DungeonManager::removeDungeon(const std::string &name)
{
    if (_dungeons.find(name) == _dungeons.end())
        throw std::runtime_error("Dungeon not found");
    _dungeons.erase(name);
}

void DungeonManager::changeDungeon(const std::string &name)
{
    if (_dungeons.find(name) == _dungeons.end())
        throw std::runtime_error("Dungeon not found");
    _currentDungeon.first = _dungeons[name];
    _currentDungeon.second = name;
}

void DungeonManager::update(std::shared_ptr<sf::RenderWindow> &window, std::string &dungeon)
{
    _currentDungeon.first->update(window, dungeon);
}

void DungeonManager::draw(std::shared_ptr<sf::RenderWindow> &window)
{
    _currentDungeon.first->draw(window);
}

std::string DungeonManager::getCurrentDungeonName() const
{
    return _currentDungeon.second;
}
