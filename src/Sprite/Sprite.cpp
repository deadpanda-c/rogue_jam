#include "Sprite/Sprite.hpp"

Sprite::Sprite()
{
    std::cout << "[*] Sprite ctor" << std::endl;
    _path = "";
}

Sprite::~Sprite()
{
}

void Sprite::init(const std::string &path, const sf::Vector2f &position, const sf::Vector2f &scale)
{
    if (path.size() == 0) {
        std::cout << "[*] Sprite::init() - Path not provided, creating rectangle" << std::endl;
        _rect = sf::RectangleShape(sf::Vector2f(100, 100));
        _rect.setFillColor(sf::Color::Red);
        _rect.setPosition(position);
        _rect.setScale(scale);
        return;
    }
    if (_texture.loadFromFile(path))
    {
        _path = path;
        _sprite.setTexture(_texture);
        _sprite.setPosition(position);
        _sprite.setScale(scale);
        std::cout << "[*] Sprite::init() - Loaded texture from file: " << path << std::endl;
    } else {
        std::cout << "Error: Sprite::init() - Failed to load texture from file: " << path << std::endl;
    }
}

void Sprite::setTexture(const std::string &path)
{
    if (_texture.loadFromFile(path))
        _path = path;
}

void Sprite::setScale(const sf::Vector2f &scale)
{
    if (_path.size() == 0) {
        _rect.setScale(scale);
        return;
    }
    _sprite.setScale(scale);
}

void Sprite::setPosition(const sf::Vector2f &position)
{
    if (_path.size() == 0) {
        _rect.setPosition(position);
        return;
    }
    _sprite.setPosition(position);
}

void Sprite::draw(std::shared_ptr<sf::RenderWindow> window)
{
    if (_path.size() == 0) {
        std::cout << "[*] Sprite::draw() - Drawing rectangle" << std::endl;
        window->draw(_rect);
        return;
    }
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

sf::FloatRect Sprite::getGlobalBounds() const
{
    return _sprite.getGlobalBounds();
}
