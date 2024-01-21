/*
** EPITECH PROJECT, 2024
** rogue_jam
** File description:
** DragonBallDungeon
*/

#include "Dungeons/DragonBallDungeon.hpp"

DragonBallDungeon::DragonBallDungeon()
{
}

DragonBallDungeon::~DragonBallDungeon()
{
}

void DragonBallDungeon::init()
{
    _player.init();
    _isHoverAttack = false;
    _isHoverRun = false;
    _spriteManager.addSprite("card", "");
    _spriteManager.addSprite("attack_card", CARD_BUTTON);
    _spriteManager.addSprite("attack_card_hover", CARD_BUTTON_HOVER);
    _spriteManager.addSprite("run_card", CARD_BUTTON);
    _spriteManager.addSprite("run_card_hover", CARD_BUTTON_HOVER);
    _spriteManager.addSprite("life_player", "");
    _spriteManager.addSprite("life_enemy", "");

    _textManager.addText("attack_card", "Attack", FONT);
    _textManager.addText("run_card", "Run", FONT);

    _spriteManager.getSprite("card")->setScale((sf::Vector2f){15, 2});
    _spriteManager.getSprite("card")->setPosition((sf::Vector2f){100, 850});

    _spriteManager.getSprite("attack_card")->setScale((sf::Vector2f){1, 1});
    _spriteManager.getSprite("attack_card")->setPosition((sf::Vector2f){300, 880});

    _spriteManager.getSprite("attack_card_hover")->setScale((sf::Vector2f){1, 1});
    _spriteManager.getSprite("attack_card_hover")->setPosition((sf::Vector2f){300, 880});

    _spriteManager.getSprite("run_card")->setScale((sf::Vector2f){1, 1});
    _spriteManager.getSprite("run_card")->setPosition((sf::Vector2f){800, 880});

    _spriteManager.getSprite("run_card_hover")->setScale((sf::Vector2f){1, 1});
    _spriteManager.getSprite("run_card_hover")->setPosition((sf::Vector2f){800, 880});

    _spriteManager.getSprite("life_player")->setScale((sf::Vector2f){5, 2});
    _spriteManager.getSprite("life_player")->setPosition((sf::Vector2f){100, 0});

    _spriteManager.getSprite("life_enemy")->setScale((sf::Vector2f){5, 2});
    _spriteManager.getSprite("life_enemy")->setPosition((sf::Vector2f){1200, 0});

    _textManager.getText("attack_card")->setPosition((sf::Vector2f){400, 950});
    _textManager.getText("attack_card")->setCharacterSize(30);

    _textManager.getText("run_card")->setPosition((sf::Vector2f){900, 950});
    _textManager.getText("run_card")->setCharacterSize(30);
}

void DragonBallDungeon::handleEvent(std::shared_ptr<sf::RenderWindow> &window, std::string &scene)
{
    sf::Event event;

    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window->close();
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Escape)
                window->close();
            if (event.key.code == sf::Keyboard::Space)
                scene = "level_map";
        }
        // check if mouse is hover a button with globalbounds
        if (event.type == sf::Event::MouseMoved) {
            _isHoverAttack = (_spriteManager.getSprite("attack_card")->getGlobalBounds().contains(window->mapPixelToCoords(sf::Mouse::getPosition(*window)))) ? true : false;
            _isHoverRun = (_spriteManager.getSprite("run_card")->getGlobalBounds().contains(window->mapPixelToCoords(sf::Mouse::getPosition(*window)))) ? true : false;
        }
        if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                if (_isHoverAttack) {
                    _player.attack();
                }
                if (_isHoverRun) {
                    scene = "level_map";
                }
            }
        }
    }
}
void DragonBallDungeon::update(std::shared_ptr<sf::RenderWindow> &window, std::string &dungeon)
{
    window->clear();
    handleEvent(window, dungeon);

    _player.update(window);
}

void DragonBallDungeon::draw(std::shared_ptr<sf::RenderWindow> &window)
{
    _player.draw(window);

    _spriteManager.draw(window, "card");
    _spriteManager.draw(window,
            (_isHoverAttack) ? "attack_card_hover" : "attack_card");
    _spriteManager.draw(window,
            (_isHoverRun) ? "run_card_hover" : "run_card");
    _spriteManager.draw(window, "life_player");
    _spriteManager.draw(window, "life_enemy");

    _textManager.draw(window, "attack_card");
    _textManager.draw(window, "run_card");
}
