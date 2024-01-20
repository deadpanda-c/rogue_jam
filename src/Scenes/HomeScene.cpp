#include "Scenes/HomeScene.hpp"

HomeScene::HomeScene()
{
    // ctor
}

std::string convertIntToString(unsigned int  number)
{
    std::string result;
    std::stringstream ss;
    ss << number;
    ss >> result;
    return result;
}

void HomeScene::init()
{
    _currentIndex = 0;
    std::cout << "[*] Home is init" << std::endl;
    // create the background
    _spriteManager.addSprite("home_map", HOME_MAP);
    _spriteManager.getSprite("home_map")->setScale((sf::Vector2f){1, 1});

    // create the sprite for the entrance to the dungeons
    _spriteManager.addSprite("entrance_onepiece", "");
    _spriteManager.addSprite("entrance_assassination-classroom", "");
    _spriteManager.addSprite("entrance_dragon-ball", "");
    _spriteManager.addSprite("entrance_bleach", "");

    // create the sprite for the highscore of each dungeon
    _spriteManager.addSprite("highScore_onepiece", "");
    _spriteManager.addSprite("highScore_assassination-classroom", "");
    _spriteManager.addSprite("highScore_dragon-ball", "");
    _spriteManager.addSprite("highScore_bleach", "");

    // create the zone for the shop
    _spriteManager.addSprite("shop", "");
    _spriteManager.addSprite("shopCellOne", "");
    _spriteManager.addSprite("shopCellTwo", "");
    _spriteManager.addSprite("buyItemOne", "");
    _spriteManager.addSprite("buyItemTwo", "");
    // set the scale and position of the sprites
    _spriteManager.getSprite("entrance_onepiece")->setScale((sf::Vector2f){0.5, 0.5});
    _spriteManager.getSprite("entrance_onepiece")->setPosition((sf::Vector2f){300, 140});

    _spriteManager.getSprite("entrance_assassination-classroom")->setScale((sf::Vector2f){0.5, 0.5});
    _spriteManager.getSprite("entrance_assassination-classroom")->setPosition((sf::Vector2f){100,  950});

    _spriteManager.getSprite("entrance_dragon-ball")->setScale((sf::Vector2f){0.5, 0.5});
    _spriteManager.getSprite("entrance_dragon-ball")->setPosition((sf::Vector2f){300, 580});

    _spriteManager.getSprite("entrance_bleach")->setScale((sf::Vector2f){0.5, 0.5});
    _spriteManager.getSprite("entrance_bleach")->setPosition((sf::Vector2f){1300, 580});

    _spriteManager.getSprite("highScore_onepiece")->setScale((sf::Vector2f){2, 2});
    _spriteManager.getSprite("highScore_onepiece")->setPosition((sf::Vector2f){1550, 200});

    _spriteManager.getSprite("highScore_assassination-classroom")->setScale((sf::Vector2f){2, 2});
    _spriteManager.getSprite("highScore_assassination-classroom")->setPosition((sf::Vector2f){1550, 200});

    _spriteManager.getSprite("highScore_dragon-ball")->setScale((sf::Vector2f){2, 2});
    _spriteManager.getSprite("highScore_dragon-ball")->setPosition((sf::Vector2f){1550, 200});

    _spriteManager.getSprite("highScore_bleach")->setScale((sf::Vector2f){2, 2});
    _spriteManager.getSprite("highScore_bleach")->setPosition((sf::Vector2f){1550, 200});

    _spriteManager.getSprite("shop")->setScale((sf::Vector2f){5, 4.5});
    _spriteManager.getSprite("shop")->setPosition((sf::Vector2f){1400, 450});
    _spriteManager.getSprite("shop")->setColor(sf::Color::White);

    _spriteManager.getSprite("shopCellOne")->setScale((sf::Vector2f){1.5, 1.5});
    _spriteManager.getSprite("shopCellOne")->setPosition((sf::Vector2f){1450, 600});

    _spriteManager.getSprite("shopCellTwo")->setScale((sf::Vector2f){1.5, 1.5});
    _spriteManager.getSprite("shopCellTwo")->setPosition((sf::Vector2f){1700, 600});
    sf::Vector2f currentPos = _spriteManager.getSprite("shopCellOne")->getPosition();
    sf::Vector2f currentPosTwo = _spriteManager.getSprite("shopCellTwo")->getPosition();

    _spriteManager.getSprite("buyItemOne")->setPosition((sf::Vector2f){currentPos.x, currentPos.y + 175});
    _spriteManager.getSprite("buyItemOne")->setScale((sf::Vector2f){1.5, 0.5});

    _spriteManager.getSprite("buyItemTwo")->setPosition((sf::Vector2f){currentPosTwo.x, currentPosTwo.y + 175});
    _spriteManager.getSprite("buyItemTwo")->setScale((sf::Vector2f){1.5, 0.5});
    // create the text for the entrance to the dungeons (as labels)
    _entranceTextManager.addText("entrance_onepiece", "One Piece", FONT_TEXT);
    _entranceTextManager.addText("entrance_assassination-classroom", "Assassination Classroom", FONT_TEXT);
    _entranceTextManager.addText("entrance_dragon-ball", "Dragon Ball", FONT_TEXT);
    _entranceTextManager.addText("entrance_bleach", "Bleach", FONT_TEXT);

    // create the Text for the name of each dungeon (as title on the right of the screen)
    _dungeonTextManager.addText("dungeonName_onepiece", "One Piece", FONT_TEXT);
    _dungeonTextManager.addText("dungeonName_assassination-classroom", "Assassination Classroom", FONT_TEXT);
    _dungeonTextManager.addText("dungeonName_dragon-ball", "Dragon Ball", FONT_TEXT);
    _dungeonTextManager.addText("dungeonName_bleach", "Bleach", FONT_TEXT);
    _dungeonTextManager.addText("shopTitle", "Shop", FONT_TEXT);
    _dungeonTextManager.addText("current_sold", convertIntToString(1000) + " {E}", ARIAL_FONT);
    _dungeonTextManager.addText("buyCellOne", "Buy", FONT_TEXT);
    _dungeonTextManager.addText("buyCellTwo", "Buy", FONT_TEXT);

    // set the font size and color of the text for the entrance to the dungeons
    for (auto &text : _entranceTextManager.getTexts()) {
        text.second->setCharacterSize(20);
        text.second->setFillColor(sf::Color::White);
    }


    // get the position of the entrance sprites and set the position of the text
    sf::Vector2f currentPosOnePiece = _spriteManager.getSprite("entrance_onepiece")->getPosition();
    sf::Vector2f currentPosAssassinationClassroom = _spriteManager.getSprite("entrance_assassination-classroom")->getPosition();
    sf::Vector2f currentPosKurokoNoBasket = _spriteManager.getSprite("entrance_dragon-ball")->getPosition();
    sf::Vector2f currentPosBleach = _spriteManager.getSprite("entrance_bleach")->getPosition();

    _entranceTextManager.getText("entrance_onepiece")->setPosition((sf::Vector2f){currentPosOnePiece.x - 20, currentPosOnePiece.y - 50});
    _entranceTextManager.getText("entrance_assassination-classroom")->setPosition((sf::Vector2f){currentPosAssassinationClassroom.x - 80, currentPosAssassinationClassroom.y - 50});
    _entranceTextManager.getText("entrance_dragon-ball")->setPosition((sf::Vector2f){currentPosKurokoNoBasket.x - 40, currentPosKurokoNoBasket.y - 50});
    _entranceTextManager.getText("entrance_bleach")->setPosition((sf::Vector2f){currentPosBleach.x - 20, currentPosBleach.y - 50});

    // set the font size and color of the text for the name of each dungeon
    _dungeonTextManager.getText("dungeonName_onepiece")->setCharacterSize(50);
    _dungeonTextManager.getText("dungeonName_onepiece")->setPosition((sf::Vector2f){1500, 100});

    _dungeonTextManager.getText("dungeonName_assassination-classroom")->setCharacterSize(30);
    _dungeonTextManager.getText("dungeonName_assassination-classroom")->setPosition((sf::Vector2f){1400, 100});

    _dungeonTextManager.getText("dungeonName_dragon-ball")->setCharacterSize(40);
    _dungeonTextManager.getText("dungeonName_dragon-ball")->setPosition((sf::Vector2f){1500, 100});

    _dungeonTextManager.getText("dungeonName_bleach")->setCharacterSize(60);
    _dungeonTextManager.getText("dungeonName_bleach")->setPosition((sf::Vector2f){1500, 100});

    _dungeonTextManager.getText("shopTitle")->setCharacterSize(60);
    _dungeonTextManager.getText("shopTitle")->setPosition((sf::Vector2f){1425, 475});
    _dungeonTextManager.getText("shopTitle")->setFillColor(sf::Color::Black);
    _dungeonTextManager.getText("current_sold")->setCharacterSize(30);
    _dungeonTextManager.getText("current_sold")->setPosition((sf::Vector2f){1750, 500});
    _dungeonTextManager.getText("current_sold")->setFillColor(sf::Color::Black);
    _dungeonTextManager.getText("buyCellOne")->setCharacterSize(30);
    _dungeonTextManager.getText("buyCellOne")->setPosition((sf::Vector2f){currentPos.x + 30, currentPos.y + 185});
    _dungeonTextManager.getText("buyCellOne")->setFillColor(sf::Color::Black);
    _dungeonTextManager.getText("buyCellTwo")->setCharacterSize(30);
    _dungeonTextManager.getText("buyCellTwo")->setPosition((sf::Vector2f){currentPosTwo.x + 30, currentPos.y + 185});
    _dungeonTextManager.getText("buyCellTwo")->setFillColor(sf::Color::Black);
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
    // highlight the labels selected
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
    // display the sprites
    _spriteManager.draw(window, "home_map");
    _spriteManager.draw(window, "entrance_onepiece");
    _spriteManager.draw(window, "entrance_assassination-classroom");
    _spriteManager.draw(window, "entrance_dragon-ball");
    _spriteManager.draw(window, "entrance_bleach");
    _spriteManager.draw(window,
            (_currentIndex == 0) ? "highScore_onepiece" :
            (_currentIndex == 1) ? "highScore_assassination-classroom" :
            (_currentIndex == 2) ? "highScore_dragon-ball" :
            "highScore_bleach");
    _spriteManager.draw(window, "shop");
    _spriteManager.draw(window, "shopCellOne");
    _spriteManager.draw(window, "shopCellTwo");
    _spriteManager.draw(window, "buyItemOne");
    _spriteManager.draw(window, "buyItemTwo");

    // display the text (labels)
    _entranceTextManager.draw(window, "entrance_onepiece");
    _entranceTextManager.draw(window, "entrance_assassination-classroom");
    _entranceTextManager.draw(window, "entrance_dragon-ball");
    _entranceTextManager.draw(window, "entrance_bleach");

    // display the text (title)
    _dungeonTextManager.draw(window,
            (_currentIndex == 0) ? "dungeonName_onepiece" :
            (_currentIndex == 1) ? "dungeonName_assassination-classroom" :
            (_currentIndex == 2) ? "dungeonName_dragon-ball" :
            "dungeonName_bleach");
    _dungeonTextManager.draw(window, "shopTitle");
    _dungeonTextManager.draw(window, "current_sold");
    _dungeonTextManager.draw(window, "buyCellOne");
    _dungeonTextManager.draw(window, "buyCellTwo");
}

HomeScene::~HomeScene()
{
}
