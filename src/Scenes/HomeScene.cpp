#include "Scenes/HomeScene.hpp"

HomeScene::HomeScene()
{
    // ctor
}

void HomeScene::init()
{
    std::cout << "[*] Home is init" << std::endl;
    _spriteManager.addSprite("home_map", HOME_MAP);
    _spriteManager.getSprite("home_map")->setScale((sf::Vector2f){1, 1});

    _spriteManager.addSprite("entrance_onepiece", "");
    _spriteManager.addSprite("entrance_assassination-classroom", "");
    _spriteManager.addSprite("entrance_kuroko-no-basket", "");
    _spriteManager.addSprite("entrance_bleach", "");

    _spriteManager.getSprite("entrance_onepiece")->setScale((sf::Vector2f){0.5, 0.5});
    _spriteManager.getSprite("entrance_onepiece")->setPosition((sf::Vector2f){0, 140});

    _spriteManager.getSprite("entrance_assassination-classroom")->setScale((sf::Vector2f){0.5, 0.5});
    _spriteManager.getSprite("entrance_assassination-classroom")->setPosition((sf::Vector2f){100,  950});

    _spriteManager.getSprite("entrance_kuroko-no-basket")->setScale((sf::Vector2f){0.5, 0.5});
    _spriteManager.getSprite("entrance_kuroko-no-basket")->setPosition((sf::Vector2f){300, 580});

    _spriteManager.getSprite("entrance_bleach")->setScale((sf::Vector2f){0.5, 0.5});
    _spriteManager.getSprite("entrance_bleach")->setPosition((sf::Vector2f){1300, 580});

    _textManager.addText("entrance_onepiece", "One Piece", FONT_TEXT);
    _textManager.addText("entrance_assassination-classroom", "Assassination Classroom", FONT_TEXT);
    _textManager.addText("entrance_kuroko-no-basket", "Kuroko no Basket", FONT_TEXT);
    _textManager.addText("entrance_bleach", "Bleach", FONT_TEXT);

    for (auto &text : _textManager.getTexts()) {
        text.second->setCharacterSize(30);
        text.second->setFillColor(sf::Color::White);
    }

    // set the position of the text as a label of the entrance above the sprite
    sf::Vector2f currentPosOnePiece = _spriteManager.getSprite("entrance_onepiece")->getPosition();
    sf::Vector2f currentPosAssassinationClassroom = _spriteManager.getSprite("entrance_assassination-classroom")->getPosition();
    sf::Vector2f currentPosKurokoNoBasket = _spriteManager.getSprite("entrance_kuroko-no-basket")->getPosition();
    sf::Vector2f currentPosBleach = _spriteManager.getSprite("entrance_bleach")->getPosition();

    _textManager.getText("entrance_onepiece")->setPosition((sf::Vector2f){currentPosOnePiece.x, currentPosOnePiece.y - 50});
    _textManager.getText("entrance_assassination-classroom")->setPosition((sf::Vector2f){currentPosAssassinationClassroom.x, currentPosAssassinationClassroom.y - 50});
    _textManager.getText("entrance_kuroko-no-basket")->setPosition((sf::Vector2f){currentPosKurokoNoBasket.x, currentPosKurokoNoBasket.y - 50});
    _textManager.getText("entrance_bleach")->setPosition((sf::Vector2f){currentPosBleach.x, currentPosBleach.y - 50});


    _player.init();
    _player.setScale((sf::Vector2f){0.5, 0.5});
    _player.setPosition((sf::Vector2f){950, 100});
}

void HomeScene::handleEvent(std::shared_ptr<sf::RenderWindow> &window, std::string &scene)
{
    sf::Event event;

    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window->close();
        _player.update(event);
    }
}

void HomeScene::update(std::shared_ptr<sf::RenderWindow> &window, std::string &scene)
{
    window->clear();
    handleEvent(window, scene);
}

void HomeScene::draw(std::shared_ptr<sf::RenderWindow> &window)
{
    _spriteManager.draw(window, "home_map");
    _spriteManager.draw(window, "entrance_onepiece");
    _spriteManager.draw(window, "entrance_assassination-classroom");
    _spriteManager.draw(window, "entrance_kuroko-no-basket");
    _spriteManager.draw(window, "entrance_bleach");
    _textManager.draw(window, "entrance_onepiece");
    _textManager.draw(window, "entrance_assassination-classroom");
    _textManager.draw(window, "entrance_kuroko-no-basket");
    _textManager.draw(window, "entrance_bleach");
    _player.draw(window);

}

HomeScene::~HomeScene()
{
}
