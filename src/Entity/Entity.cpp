#include "Entity/Entity.hpp"

Entity::Entity()
{
}

Entity::Entity(const std::string &filename)
{
    _filename = filename;
}

void Entity::setFilename(const std::string &filename)
{
    _filename = filename;
}

void Entity::setHealth(int health)
{
    _stats[HEALTH] = (_stats[HEALTH] + health) > 100 ? 100 : _stats[HEALTH] + health;
}

void Entity::setShield(int shield)
{
    _stats[SHIELD] = (_stats[SHIELD] + shield) > 100 ? 100 : _stats[SHIELD] + shield;
}

int Entity::getHealth() const
{
    return _stats[HEALTH];
}

int Entity::getShield() const
{
    return _stats[SHIELD];
}
