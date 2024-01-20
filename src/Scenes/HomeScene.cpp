#include "Scenes/HomeScene.hpp"

HomeScene::HomeScene()
{
    // ctor
}

void HomeScene::init()
{
    _currentIndex = 0;
    std::cout << "[*] Home is init" << std::endl;
    _spriteManager.addSprite("home_map", HOME_MAP);
    _spriteManager.getSprite("home_map")->setScale((sf::Vector2f){1, 1});

    _spriteManager.addSprite("entrance_onepiece", "");
    _spriteManager.addSprite("entrance_assassination-classroom", "");
    _spriteManager.addSprite("entrance_dragon-ball", "");
    _spriteManager.addSprite("entrance_bleach", "");

    _spriteManager.getSprite("entrance_onepiece")->setScale((sf::Vector2f){0.5, 0.5});
    _spriteManager.getSprite("entrance_onepiece")->setPosition((sf::Vector2f){300, 140});

    _spriteManager.getSprite("entrance_assassination-classroom")->setScale((sf::Vector2f){0.5, 0.5});
    _spriteManager.getSprite("entrance_assassination-classroom")->setPosition((sf::Vector2f){100,  950});

    _spriteManager.getSprite("entrance_dragon-ball")->setScale((sf::Vector2f){0.5, 0.5});
    _spriteManager.getSprite("entrance_dragon-ball")->setPosition((sf::Vector2f){300, 580});

    _spriteManager.getSprite("entrance_bleach")->setScale((sf::Vector2f){0.5, 0.5});
    _spriteManager.getSprite("entrance_bleach")->setPosition((sf::Vector2f){1300, 580});

    _entranceTextManager.addText("entrance_onepiece", "One Piece", FONT_TEXT);
    _entranceTextManager.addText("entrance_assassination-classroom", "Assassination Classroom", FONT_TEXT);
    _entranceTextManager.addText("entrance_dragon-ball", "Dragon Ball", FONT_TEXT);
    _entranceTextManager.addText("entrance_bleach", "Bleach", FONT_TEXT);


    _dungeonTextManager.addText("dungeonName_onepiece", "One Piece", FONT_TEXT);
    _dungeonTextManager.addText("dungeon_assassination-classroom", "Assassination Classroom", FONT_TEXT);
    _dungeonTextManager.addText("dungeon_dragon-ball", "Dragon Ball", FONT_TEXT);
    _dungeonTextManager.addText("dungeon_bleach", "Bleach", FONT_TEXT);
    for (auto &text : _entranceTextManager.getTexts()) {
        text.second->setCharacterSize(20);
        text.second->setFillColor(sf::Color::White);
    }

    for (auto &text : _dungeonTextManager.getTexts()) {
        text.second->setCharacterSize(50);
        text.second->setFillColor(sf::Color::White);
    }

    sf::Vector2f currentPosOnePiece = _spriteManager.getSprite("entrance_onepiece")->getPosition();
    sf::Vector2f currentPosAssassinationClassroom = _spriteManager.getSprite("entrance_assassination-classroom")->getPosition();
    sf::Vector2f currentPosKurokoNoBasket = _spriteManager.getSprite("entrance_dragon-ball")->getPosition();
    sf::Vector2f currentPosBleach = _spriteManager.getSprite("entrance_bleach")->getPosition();

    _entranceTextManager.getText("entrance_onepiece")->setPosition((sf::Vector2f){currentPosOnePiece.x - 20, currentPosOnePiece.y - 50});
    _entranceTextManager.getText("entrance_assassination-classroom")->setPosition((sf::Vector2f){currentPosAssassinationClassroom.x - 80, currentPosAssassinationClassroom.y - 50});
    _entranceTextManager.getText("entrance_dragon-ball")->setPosition((sf::Vector2f){currentPosKurokoNoBasket.x - 40, currentPosKurokoNoBasket.y - 50});
    _entranceTextManager.getText("entrance_bleach")->setPosition((sf::Vector2f){currentPosBleach.x - 20, currentPosBleach.y - 50});
}

void HomeScene::handleEvent(std::shared_ptr<sf::RenderWindow> &window, std::string &scene)
{
    sf::Event event;

    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window->close();
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Right)
                _currentIndex += (_currentIndex < 3) ? 1 : -3;
            else if (event.key.code == sf::Keyboard::Left)
                _currentIndex -= (_currentIndex > 0) ? 1 : -3;
        }
    }
}

void HomeScene::update(std::shared_ptr<sf::RenderWindow> &window, std::string &scene)
{
    window->clear();
    handleEvent(window, scene);
    switch (_currentIndex) {
        case 0:
            _entranceTextManager.getText("entrance_onepiece")->setFillColor(sf::Color::Red);
            _entranceTextManager.getText("entrance_assassination-classroom")->setFillColor(sf::Color::White);
            _entranceTextManager.getText("entrance_dragon-ball")->setFillColor(sf::Color::White);
            _entranceTextManager.getText("entrance_bleach")->setFillColor(sf::Color::White);
            break;
        case 1:
            _entranceTextManager.getText("entrance_assassination-classroom")->setFillColor(sf::Color::Red);
            _entranceTextManager.getText("entrance_onepiece")->setFillColor(sf::Color::White);
            _entranceTextManager.getText("entrance_dragon-ball")->setFillColor(sf::Color::White);
            _entranceTextManager.getText("entrance_bleach")->setFillColor(sf::Color::White);
            break;
        case 2:
            _entranceTextManager.getText("entrance_dragon-ball")->setFillColor(sf::Color::Red);
            _entranceTextManager.getText("entrance_onepiece")->setFillColor(sf::Color::White);
            _entranceTextManager.getText("entrance_assassination-classroom")->setFillColor(sf::Color::White);
            _entranceTextManager.getText("entrance_bleach")->setFillColor(sf::Color::White);
            break;
        case 3:
            _entranceTextManager.getText("entrance_bleach")->setFillColor(sf::Color::Red);
            _entranceTextManager.getText("entrance_onepiece")->setFillColor(sf::Color::White);
            _entranceTextManager.getText("entrance_assassination-classroom")->setFillColor(sf::Color::White);
            _entranceTextManager.getText("entrance_dragon-ball")->setFillColor(sf::Color::White);
            break;
    }
}

void HomeScene::draw(std::shared_ptr<sf::RenderWindow> &window)
{
    _spriteManager.draw(window, "home_map");
    _spriteManager.draw(window, "entrance_onepiece");
    _spriteManager.draw(window, "entrance_assassination-classroom");
    _spriteManager.draw(window, "entrance_dragon-ball");
    _spriteManager.draw(window, "entrance_bleach");

    _entranceTextManager.draw(window, "entrance_onepiece");
    _entranceTextManager.draw(window, "entrance_assassination-classroom");
    _entranceTextManager.draw(window, "entrance_dragon-ball");
    _entranceTextManager.draw(window, "entrance_bleach");

}

HomeScene::~HomeScene()
{
}
