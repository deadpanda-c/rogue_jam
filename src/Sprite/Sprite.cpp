#include "Sprite/Sprite.hpp"

Sprite::Sprite()
{
}

Sprite::~Sprite()
{
}

void Sprite::init(const std::string &path, const sf::Vector2f &position, const sf::Vector2f &scale)
{
    if (_texture.loadFromFile(path))
    {
        _sprite.setTexture(_texture);
        _sprite.setPosition(position);
        _sprite.setScale(scale);
        std::cout << "[*] Sprite::init() - Loaded texture from file: " << path << std::endl;
    } else {
        std::cout << "Error: Sprite::init() - Failed to load texture from file: " << path << std::endl;
    }
}

void Sprite::setScale(const sf::Vector2f &scale)
{
    _sprite.setScale(scale);
}

void Sprite::setPosition(const sf::Vector2f &position)
{
    _sprite.setPosition(position);
}

void Sprite::draw(std::shared_ptr<sf::RenderWindow> window)
{
    window->draw(_sprite);
}

sf::Vector2f Sprite::getScale() const
{
    return _sprite.getScale();
}

sf::Vector2f Sprite::getPosition() const
{
    return _sprite.getPosition();
}
