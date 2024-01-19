#include "Sprite/SpriteManager.hpp"

SpriteManager::SpriteManager()
{
    // ctor
}

SpriteManager::~SpriteManager()
{
    // dtor
}

void SpriteManager::addSprite(const std::string &name, const std::string &path)
{
    if (_sprites.find(name) != _sprites.end()) {
        std::cout << "SpriteManager::addSprite: Sprite " << name << " already exists" << std::endl;
        return;
    }
    _sprites[name] = std::make_shared<Sprite>();
    _sprites[name]->init(path, (sf::Vector2f){0, 0}, (sf::Vector2f){0, 0});
}

void SpriteManager::removeSprite(const std::string &name)
{
    if (_sprites.find(name) == _sprites.end()) {
        std::cout << "SpriteManager::removeSprite: Sprite " << name << " doesn't exist" << std::endl;
        return;
    }
    _sprites.erase(name);
}

void SpriteManager::draw(std::shared_ptr<sf::RenderWindow> &window)
{
    for (auto &sprite : _sprites) {
        sprite.second->draw(window);
    }
}

size_t SpriteManager::getNbSprites() const
{
    return _sprites.size();
}

std::shared_ptr<Sprite> SpriteManager::getSprite(const std::string &name) const
{
    if (_sprites.find(name) == _sprites.end()) {
        std::cout << "SpriteManager::getSprite: Sprite " << name << " doesn't exist" << std::endl;
        return nullptr;
    }
    return _sprites.at(name);
}
