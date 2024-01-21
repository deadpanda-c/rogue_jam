#include "Sprite/SpriteManager.hpp"

SpriteManager::SpriteManager()
{
    // ctor
    _currentAnimation = "";
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
    std::cout << "SpriteManager::addSprite: Sprite " << name << " added" << std::endl;
    _sprites[name] = std::make_shared<Sprite>();
    std::cout << "SpriteManager::addSprite: Sprite " << name << " initialized" << std::endl;
    _sprites[name]->init(path, (sf::Vector2f){0, 0}, (sf::Vector2f){0.75, 0.75});
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
        std::cout << "[*] SpriteManager::draw: Drawing " << sprite.first << std::endl;
        sprite.second->draw(window);
    }
}

void SpriteManager::draw(std::shared_ptr<sf::RenderWindow> &window, const std::string &name)
{
    if (_sprites.find(name) == _sprites.end()) {
        std::cout << "SpriteManager::draw: Sprite " << name << " doesn't exist" << std::endl;
        return;
    }
    _sprites[name]->draw(window);
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

void SpriteManager::addAnimation(const std::string &animationName, std::string &spriteName, std::vector<sf::IntRect> &frames, float time)
{
    _animations[animationName] = std::make_pair(spriteName, frames);
    _clocks[animationName] = std::make_pair(sf::Clock(), time);
}

void SpriteManager::playAnimation(const std::string &animationName, int &size)
{
    sf::Time time = _clocks[animationName].first.getElapsedTime();
    if (_animations.find(animationName) == _animations.end()) {
        std::cout << "SpriteManager::playAnimation: Animation " << animationName << " doesn't exist" << std::endl;
        return;
    }
    if (time.asSeconds() > _clocks[animationName].second) {
        _clocks[animationName].first.restart();
        size++;
        if (size >= _animations[animationName].second.size())
            size = 0;
        _sprites[_animations[animationName].first]->setTextureRect(_animations[animationName].second[size]);
        _clocks[animationName].first.restart();
    }
}
