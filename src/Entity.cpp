#include "Entity.hpp"

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
    _health = (_health + health) > 100 ? 100 : _health + health;
}

void Entity::setShield(int shield)
{
    _shield = (_shield + shield) > 100 ? 100 : _shield + shield;
}

int Entity::getHealth() const
{
    return _health;
}

int Entity::getShield() const
{
    return _shield;
}
