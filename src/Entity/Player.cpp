#include "Entity/Player.hpp"

Player::Player() : Entity()
{
}


Player::~Player()
{
}

void Player::init()
{
    _currentAnimation = IDLE;
    std::cout << "[*] Player is initializing..." << std::endl;
    // set the origin of the sprite on the center

    _spriteManager.addSprite("player_idle", PLAYER_IDLE);
    _spriteManager.getSprite("player_idle")->setScale((sf::Vector2f){-2, 2});
    sf::Texture texture = _spriteManager.getSprite("player_idle")->getTexture();
    _spriteManager.getSprite("player_idle")->setOrigin((sf::Vector2f)texture.getSize() / 2.f);
    _spriteManager.getSprite("player_idle")->setPosition((sf::Vector2f){100, 500});
    std::vector<sf::IntRect> frames_idle = {
        (sf::IntRect){0, 0, 130, 148},
        (sf::IntRect){130, 0, 130, 148},
        (sf::IntRect){260, 0, 130, 148},
        (sf::IntRect){390, 0, 130, 148},
        (sf::IntRect){520, 0, 130, 148},
        (sf::IntRect){650, 0, 130, 148}
    };
    std::string name = "player_idle";
    _spriteManager.addAnimation("player_idle", name, frames_idle, 0.1);

    _spriteManager.addSprite("player_attack", PLAYER_ATTACK);
    _spriteManager.getSprite("player_attack")->setScale((sf::Vector2f){-2, 2});
    texture = _spriteManager.getSprite("player_attack")->getTexture();
    _spriteManager.getSprite("player_attack")->setOrigin((sf::Vector2f)texture.getSize() / 2.f);
    _spriteManager.getSprite("player_attack")->setPosition((sf::Vector2f){100, 500});
    std::vector<sf::IntRect> frames_attack = {
        (sf::IntRect){0, 0, 166, 181},
        (sf::IntRect){207, 0, 400 - 207, 181},
        (sf::IntRect){403, 0, 595 - 403, 181},
        (sf::IntRect){628, 0, 803 - 628, 181},
    };
    name = "player_attack";
    _spriteManager.addAnimation("player_attack", name, frames_attack, 0.1);
    _animationIndexIdle = 0;
    _animationIndexAttack = 0;
}

void Player::attack()
{
    _currentAnimation = ATTACK;

}

void Player::update(std::shared_ptr<sf::RenderWindow> &window)
{
    std::string name_idle = "player_idle";
    std::string name_attack = "player_attack";

    _spriteManager.playAnimation(
            (_currentAnimation == IDLE) ? name_idle :
            (_currentAnimation == ATTACK) ? name_attack : name_idle,
            (_currentAnimation == IDLE ? _animationIndexIdle : _animationIndexAttack));
    if (_animationIndexAttack == 3)
        _currentAnimation = IDLE;
}

void Player::draw(std::shared_ptr<sf::RenderWindow> &window)
{
    _spriteManager.draw(window,
            (_currentAnimation == IDLE) ? "player_idle" :
            (_currentAnimation == ATTACK) ? "player_attack" : "player_idle");
}

