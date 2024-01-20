#include "Player.hpp"

Player::Player() : Entity()
{
}

Player::Player(const std::string &filename) : Entity(filename)
{
}

Player::~Player()
{
}

void Player::init()
{
    std::cout << "[*] Player is initializing..." << std::endl;
    _health = 100;
    _shield = 0;

    _spriteManager.addSprite("player", "");
    _spriteManager.getSprite("player")->setColor((sf::Color){255, 255, 255});
}

void Player::update(sf::Event &event)
{
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Up) {
            _spriteManager.getSprite("player")->move((sf::Vector2f){0, -2});
        }
        if (event.key.code == sf::Keyboard::Down)
        {
            _spriteManager.getSprite("player")->move((sf::Vector2f){0, 2});
        }
        else if (event.key.code == sf::Keyboard::Left)
        {
            _spriteManager.getSprite("player")->move((sf::Vector2f){-2, 0});
        }
        else if (event.key.code == sf::Keyboard::Right)
        {
            _spriteManager.getSprite("player")->move((sf::Vector2f){2, 0});
        }
    }
}

void Player::draw(std::shared_ptr<sf::RenderWindow> &window)
{
    _spriteManager.draw(window, "player");
}

void Player::setScale(const sf::Vector2f &scale)
{
    _spriteManager.getSprite("player")->setScale(scale);
}

void Player::setPosition(const sf::Vector2f &position)
{
    _spriteManager.getSprite("player")->setPosition(position);
}