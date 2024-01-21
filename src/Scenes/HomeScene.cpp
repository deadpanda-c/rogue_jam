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

void HomeScene::initLevel(std::vector<bool> &levelUnlocked)
{
    levelUnlocked.push_back(true);
    levelUnlocked.push_back(false);
    levelUnlocked.push_back(false);
}

void HomeScene::init()
{
    initLevel(_dungeonLevelUnlocked[ONEPIECE]);
    initLevel(_dungeonLevelUnlocked[KUROKO]);
    initLevel(_dungeonLevelUnlocked[DRAGONBALL]);
    initLevel(_dungeonLevelUnlocked[BLEACH]);
    initLevel(_dungeonLevelUnlocked[ASSASSINATION_CLASSROOM]);

    _dungeonLevelPrice[ONEPIECE] = std::make_pair(BEGGINER, 100);
    _dungeonLevelPrice[ONEPIECE] = std::make_pair(INTERMEDIATE, 300);
    _dungeonLevelPrice[ONEPIECE] = std::make_pair(ADVANCED, 500);

    _dungeonLevelPrice[KUROKO] = std::make_pair(BEGGINER, 200);
    _dungeonLevelPrice[KUROKO] = std::make_pair(INTERMEDIATE, 400);
    _dungeonLevelPrice[KUROKO] = std::make_pair(ADVANCED, 600);

    _dungeonLevelPrice[DRAGONBALL] = std::make_pair(BEGGINER, 300);
    _dungeonLevelPrice[DRAGONBALL] = std::make_pair(INTERMEDIATE, 500);
    _dungeonLevelPrice[DRAGONBALL] = std::make_pair(ADVANCED, 700);

    _dungeonLevelPrice[BLEACH] = std::make_pair(BEGGINER, 400);
    _dungeonLevelPrice[BLEACH] = std::make_pair(INTERMEDIATE, 600);
    _dungeonLevelPrice[BLEACH] = std::make_pair(ADVANCED, 800);

    _dungeonLevelPrice[ASSASSINATION_CLASSROOM] = std::make_pair(BEGGINER, 500);
    _dungeonLevelPrice[ASSASSINATION_CLASSROOM] = std::make_pair(INTERMEDIATE, 700);
    _dungeonLevelPrice[ASSASSINATION_CLASSROOM] = std::make_pair(ADVANCED, 900);

    _isStartBtnHover = false;
    _currentSold = 1000;
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
    _spriteManager.addSprite("entrance_kuroko-no-basket", "");

    // create the sprite for the highscore of each dungeon
    _spriteManager.addSprite("highScore_onepiece", "");
    _spriteManager.addSprite("highScore_assassination-classroom", "");
    _spriteManager.addSprite("highScore_dragon-ball", "");
    _spriteManager.addSprite("highScore_bleach", "");
    _spriteManager.addSprite("highScore_kuroko-no-basket", "");

    // create the zone for the shop
    _spriteManager.addSprite("shop", "");
    _spriteManager.addSprite("shopCellOne", "");
    _spriteManager.addSprite("shopCellTwo", "");
    _spriteManager.addSprite("buyItemOne", "");
    _spriteManager.addSprite("buyItemTwo", "");

    // create the sprite for the start button
    _spriteManager.addSprite("start", START_BUTTON);
    _spriteManager.addSprite("start_hover", START_BUTTON_HOVER);
    // set the scale and position of the sprites
    _spriteManager.getSprite("entrance_onepiece")->setScale((sf::Vector2f){0.5, 0.5});
    _spriteManager.getSprite("entrance_onepiece")->setPosition((sf::Vector2f){300, 140});

    _spriteManager.getSprite("entrance_assassination-classroom")->setScale((sf::Vector2f){0.5, 0.5});
    _spriteManager.getSprite("entrance_assassination-classroom")->setPosition((sf::Vector2f){100,  950});

    _spriteManager.getSprite("entrance_dragon-ball")->setScale((sf::Vector2f){0.5, 0.5});
    _spriteManager.getSprite("entrance_dragon-ball")->setPosition((sf::Vector2f){300, 580});

    _spriteManager.getSprite("entrance_bleach")->setScale((sf::Vector2f){0.5, 0.5});
    _spriteManager.getSprite("entrance_bleach")->setPosition((sf::Vector2f){1300, 580});

    _spriteManager.getSprite("entrance_kuroko-no-basket")->setScale((sf::Vector2f){0.5, 0.5});
    _spriteManager.getSprite("entrance_kuroko-no-basket")->setPosition((sf::Vector2f){950, 300});

    _spriteManager.getSprite("highScore_onepiece")->setScale((sf::Vector2f){2, 2});
    _spriteManager.getSprite("highScore_onepiece")->setPosition((sf::Vector2f){1550, 200});

    _spriteManager.getSprite("highScore_assassination-classroom")->setScale((sf::Vector2f){2, 2});
    _spriteManager.getSprite("highScore_assassination-classroom")->setPosition((sf::Vector2f){1550, 200});

    _spriteManager.getSprite("highScore_dragon-ball")->setScale((sf::Vector2f){2, 2});
    _spriteManager.getSprite("highScore_dragon-ball")->setPosition((sf::Vector2f){1550, 200});

    _spriteManager.getSprite("highScore_bleach")->setScale((sf::Vector2f){2, 2});
    _spriteManager.getSprite("highScore_bleach")->setPosition((sf::Vector2f){1550, 200});

    _spriteManager.getSprite("highScore_kuroko-no-basket")->setScale((sf::Vector2f){2, 2});
    _spriteManager.getSprite("highScore_kuroko-no-basket")->setPosition((sf::Vector2f){1550, 200});

    _spriteManager.getSprite("shop")->setScale((sf::Vector2f){5, 4.5});
    _spriteManager.getSprite("shop")->setPosition((sf::Vector2f){1400, 450});
    _spriteManager.getSprite("shop")->setColor(sf::Color::White);

    _spriteManager.getSprite("shopCellOne")->setScale((sf::Vector2f){1.5, 1.5});
    _spriteManager.getSprite("shopCellOne")->setPosition((sf::Vector2f){1450, 600});

    _spriteManager.getSprite("shopCellTwo")->setScale((sf::Vector2f){1.5, 1.5});
    _spriteManager.getSprite("shopCellTwo")->setPosition((sf::Vector2f){1700, 600});

    _spriteManager.getSprite("start")->setScale((sf::Vector2f){1, 0.75});
    _spriteManager.getSprite("start")->setPosition((sf::Vector2f){1500, 950});

    _spriteManager.getSprite("start_hover")->setScale((sf::Vector2f){1, 0.75});
    _spriteManager.getSprite("start_hover")->setPosition((sf::Vector2f){1500, 950});

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
    _entranceTextManager.addText("entrance_kuroko-no-basket", "Kuroko no Basket", FONT_TEXT);

    // create the Text for the name of each dungeon (as title on the right of the screen)
    _dungeonTextManager.addText("dungeonName_onepiece", "One Piece", FONT_TEXT);
    _dungeonTextManager.addText("dungeonName_assassination-classroom", "Assassination Classroom", FONT_TEXT);
    _dungeonTextManager.addText("dungeonName_dragon-ball", "Dragon Ball", FONT_TEXT);
    _dungeonTextManager.addText("dungeonName_bleach", "Bleach", FONT_TEXT);
    _dungeonTextManager.addText("dungeonName_kuroko-no-basket", "Kuroko no Basket", FONT_TEXT);
    _dungeonTextManager.addText("shopTitle", "Shop", FONT_TEXT);
    _dungeonTextManager.addText("current_sold", convertIntToString(_currentSold) + " {E}", ARIAL_FONT);
    _dungeonTextManager.addText("buyCellOne", "Buy", FONT_TEXT);
    _dungeonTextManager.addText("buyCellTwo", "Buy", FONT_TEXT);


    // add text for the start btn
    _dungeonTextManager.addText("start", "Start", FONT_TEXT);

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
    sf::Vector2f currentPosKurokoNoBasketTwo = _spriteManager.getSprite("entrance_kuroko-no-basket")->getPosition();

    _entranceTextManager.getText("entrance_onepiece")->setPosition((sf::Vector2f){currentPosOnePiece.x - 20, currentPosOnePiece.y - 50});
    _entranceTextManager.getText("entrance_assassination-classroom")->setPosition((sf::Vector2f){currentPosAssassinationClassroom.x - 80, currentPosAssassinationClassroom.y - 50});
    _entranceTextManager.getText("entrance_dragon-ball")->setPosition((sf::Vector2f){currentPosKurokoNoBasket.x - 40, currentPosKurokoNoBasket.y - 50});
    _entranceTextManager.getText("entrance_bleach")->setPosition((sf::Vector2f){currentPosBleach.x - 20, currentPosBleach.y - 50});
    _entranceTextManager.getText("entrance_kuroko-no-basket")->setPosition((sf::Vector2f){currentPosKurokoNoBasketTwo.x - 70, currentPosKurokoNoBasketTwo.y - 50});

    // set the font size and color of the text for the name of each dungeon
    _dungeonTextManager.getText("dungeonName_onepiece")->setCharacterSize(50);
    _dungeonTextManager.getText("dungeonName_onepiece")->setPosition((sf::Vector2f){1500, 100});

    _dungeonTextManager.getText("dungeonName_assassination-classroom")->setCharacterSize(30);
    _dungeonTextManager.getText("dungeonName_assassination-classroom")->setPosition((sf::Vector2f){1400, 100});

    _dungeonTextManager.getText("dungeonName_dragon-ball")->setCharacterSize(40);
    _dungeonTextManager.getText("dungeonName_dragon-ball")->setPosition((sf::Vector2f){1500, 100});

    _dungeonTextManager.getText("dungeonName_bleach")->setCharacterSize(60);
    _dungeonTextManager.getText("dungeonName_bleach")->setPosition((sf::Vector2f){1500, 100});

    _dungeonTextManager.getText("dungeonName_kuroko-no-basket")->setCharacterSize(30);
    _dungeonTextManager.getText("dungeonName_kuroko-no-basket")->setPosition((sf::Vector2f){1500, 100});

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

    // set the font size and color of the text for the start btn
    _dungeonTextManager.getText("start")->setCharacterSize(30);
    _dungeonTextManager.getText("start")->setPosition((sf::Vector2f){1620, 990});
    _dungeonTextManager.getText("start")->setFillColor(sf::Color::White);


//  _spriteManager.getSprite("shopCellOne")->setPosition((sf::Vector2f){1450, 600});
// _spriteManager.getSprite("shopCellTwo")->setPosition((sf::Vector2f){1700, 600});
    _dungeonSpriteManager[ONEPIECE] = std::make_shared<SpriteManager>();
    _dungeonSpriteManager[KUROKO] = std::make_shared<SpriteManager>();
    _dungeonSpriteManager[DRAGONBALL] = std::make_shared<SpriteManager>();
    _dungeonSpriteManager[BLEACH] = std::make_shared<SpriteManager>();
    _dungeonSpriteManager[ASSASSINATION_CLASSROOM] = std::make_shared<SpriteManager>();

    _dungeonSpriteManager[ONEPIECE]->addSprite("onePieceHat", ONEPIECE_HAT);
    _dungeonSpriteManager[ONEPIECE]->addSprite("onePieceDials", ONEPIECE_DIALS);
    _dungeonSpriteManager[ONEPIECE]->addSprite("onePieceGomuGomu", ONEPIECE_GOMUGOMU);

    _dungeonSpriteManager[ONEPIECE]->getSprite("onePieceHat")->setPosition((sf::Vector2f){1450, 600});
    _dungeonSpriteManager[ONEPIECE]->getSprite("onePieceDials")->setPosition((sf::Vector2f){1450, 600});
    _dungeonSpriteManager[ONEPIECE]->getSprite("onePieceGomuGomu")->setPosition((sf::Vector2f){1450, 600});

    _dungeonSpriteManager[ONEPIECE]->addSprite("onePieceItoIto", ONEPIECE_ITOITO);
    _dungeonSpriteManager[ONEPIECE]->addSprite("onePieceLogPose", ONEPIECE_LOGPOSE);
    _dungeonSpriteManager[ONEPIECE]->addSprite("onePieceMeraMera", ONEPIECE_MERA);

    _dungeonSpriteManager[ONEPIECE]->getSprite("onePieceItoIto")->setPosition((sf::Vector2f){1700, 600});
    _dungeonSpriteManager[ONEPIECE]->getSprite("onePieceLogPose")->setPosition((sf::Vector2f){1700, 600});
    _dungeonSpriteManager[ONEPIECE]->getSprite("onePieceMeraMera")->setPosition((sf::Vector2f){1700, 600});

    _dungeonItems[ONEPIECE].first.push("onePieceHat");
    _dungeonItems[ONEPIECE].first.push("onePieceDials");
    _dungeonItems[ONEPIECE].first.push("onePieceGomuGomu");
    _dungeonItems[ONEPIECE].second.push("onePieceItoIto");
    _dungeonItems[ONEPIECE].second.push("onePieceLogPose");
    _dungeonItems[ONEPIECE].second.push("onePieceMeraMera");


    _dungeonSpriteManager[KUROKO]->addSprite("kurokoBasket", KUROKO_BASKET);
    _dungeonSpriteManager[KUROKO]->addSprite("kuokoKaijo", KUROKO_KAIJO);
    _dungeonSpriteManager[KUROKO]->addSprite("kurokoZone", KUROKO_ZONE);

    _dungeonSpriteManager[KUROKO]->getSprite("kurokoBasket")->setPosition((sf::Vector2f){1450, 600});
    _dungeonSpriteManager[KUROKO]->getSprite("kuokoKaijo")->setPosition((sf::Vector2f){1450, 600});
    _dungeonSpriteManager[KUROKO]->getSprite("kurokoZone")->setPosition((sf::Vector2f){1450, 600});

    _dungeonSpriteManager[KUROKO]->addSprite("kurokoSeirin", KUROKO_SEIRIN);
    _dungeonSpriteManager[KUROKO]->addSprite("kurokoWristband", KUROKO_WRISTBAND);
    _dungeonSpriteManager[KUROKO]->addSprite("kurokoYosen", KUROKO_YOSEN);

    _dungeonSpriteManager[KUROKO]->getSprite("kurokoSeirin")->setPosition((sf::Vector2f){1700, 600});
    _dungeonSpriteManager[KUROKO]->getSprite("kurokoWristband")->setPosition((sf::Vector2f){1700, 600});
    _dungeonSpriteManager[KUROKO]->getSprite("kurokoYosen")->setPosition((sf::Vector2f){1700, 600});

    _dungeonItems[KUROKO].first.push("kurokoBasket");
    _dungeonItems[KUROKO].first.push("kuokoKaijo");
    _dungeonItems[KUROKO].first.push("kurokoZone");
    _dungeonItems[KUROKO].second.push("kurokoSeirin");
    _dungeonItems[KUROKO].second.push("kurokoWristband");
    _dungeonItems[KUROKO].second.push("kurokoYosen");


    _dungeonSpriteManager[DRAGONBALL]->addSprite("dragonBallBarrier", DRAGONBALL_BARRIER);
    _dungeonSpriteManager[DRAGONBALL]->addSprite("dragonBallCapsule", DRAGONBALL_CAPSULE);
    _dungeonSpriteManager[DRAGONBALL]->addSprite("dragonBallEscape", DRAGONBALL_ESCAPE);

    _dungeonSpriteManager[DRAGONBALL]->getSprite("dragonBallBarrier")->setPosition((sf::Vector2f){1450, 600});
    _dungeonSpriteManager[DRAGONBALL]->getSprite("dragonBallCapsule")->setPosition((sf::Vector2f){1450, 600});
    _dungeonSpriteManager[DRAGONBALL]->getSprite("dragonBallEscape")->setPosition((sf::Vector2f){1450, 600});

    _dungeonSpriteManager[DRAGONBALL]->addSprite("dragonBallPowerKey", DRAGONBALL_POWERKEY);
    _dungeonSpriteManager[DRAGONBALL]->addSprite("dragonBallEnergyCube", DRAGONBALL_ENERGYCUBE);
    _dungeonSpriteManager[DRAGONBALL]->addSprite("dragonBallBall", DRAGONBALL_BALL);

    _dungeonSpriteManager[DRAGONBALL]->getSprite("dragonBallPowerKey")->setPosition((sf::Vector2f){1700, 600});
    _dungeonSpriteManager[DRAGONBALL]->getSprite("dragonBallEnergyCube")->setPosition((sf::Vector2f){1700, 600});
    _dungeonSpriteManager[DRAGONBALL]->getSprite("dragonBallBall")->setPosition((sf::Vector2f){1700, 600});

    _dungeonItems[DRAGONBALL].first.push("dragonBallBarrier");
    _dungeonItems[DRAGONBALL].first.push("dragonBallCapsule");
    _dungeonItems[DRAGONBALL].first.push("dragonBallEscape");
    _dungeonItems[DRAGONBALL].second.push("dragonBallPowerKey");
    _dungeonItems[DRAGONBALL].second.push("dragonBallEnergyCube");
    _dungeonItems[DRAGONBALL].second.push("dragonBallBall");

    _dungeonSpriteManager[BLEACH]->addSprite("bleachArcuryu", BLEACH_ARCURYU);
    _dungeonSpriteManager[BLEACH]->addSprite("bleachGokkontekko", BLEACH_GOKKONTEKKO);
    _dungeonSpriteManager[BLEACH]->addSprite("bleachHougyoku", BLEACH_HOUGYOKU);

    _dungeonSpriteManager[BLEACH]->getSprite("bleachArcuryu")->setPosition((sf::Vector2f){1450, 600});
    _dungeonSpriteManager[BLEACH]->getSprite("bleachGokkontekko")->setPosition((sf::Vector2f){1450, 600});
    _dungeonSpriteManager[BLEACH]->getSprite("bleachHougyoku")->setPosition((sf::Vector2f){1450, 600});

    _dungeonSpriteManager[BLEACH]->addSprite("bleachSodenoshirayuki", BLEACH_SODENOSHIRAYUKI);
    _dungeonSpriteManager[BLEACH]->addSprite("bleachSoulcandy", BLEACH_SOULCANDY);
    _dungeonSpriteManager[BLEACH]->addSprite("bleachZangetsu", BLEACH_ZANGETSU);

    _dungeonSpriteManager[BLEACH]->getSprite("bleachSodenoshirayuki")->setPosition((sf::Vector2f){1700, 600});
    _dungeonSpriteManager[BLEACH]->getSprite("bleachSoulcandy")->setPosition((sf::Vector2f){1700, 600});
    _dungeonSpriteManager[BLEACH]->getSprite("bleachZangetsu")->setPosition((sf::Vector2f){1700, 600});

    _dungeonItems[BLEACH].first.push("bleachArcuryu");
    _dungeonItems[BLEACH].first.push("bleachGokkontekko");
    _dungeonItems[BLEACH].first.push("bleachHougyoku");
    _dungeonItems[BLEACH].second.push("bleachSodenoshirayuki");
    _dungeonItems[BLEACH].second.push("bleachSoulcandy");
    _dungeonItems[BLEACH].second.push("bleachZangetsu");

    _dungeonSpriteManager[ASSASSINATION_CLASSROOM]->addSprite("deathnote", ASSASSINATION_CLASSROOM_DEATHNOTE);
    _dungeonSpriteManager[ASSASSINATION_CLASSROOM]->addSprite("matraque", ASSASSINATION_CLASSROOM_MATRAQUE);
    _dungeonSpriteManager[ASSASSINATION_CLASSROOM]->addSprite("regle", ASSASSINATION_CLASSROOM_REGLE);

    _dungeonSpriteManager[ASSASSINATION_CLASSROOM]->getSprite("deathnote")->setPosition((sf::Vector2f){1450, 600});
    _dungeonSpriteManager[ASSASSINATION_CLASSROOM]->getSprite("matraque")->setPosition((sf::Vector2f){1450, 600});
    _dungeonSpriteManager[ASSASSINATION_CLASSROOM]->getSprite("regle")->setPosition((sf::Vector2f){1450, 600});

    _dungeonSpriteManager[ASSASSINATION_CLASSROOM]->addSprite("knifeo", ASSASSINATION_CLASSROOM_SAAUSKNIFEO);
    _dungeonSpriteManager[ASSASSINATION_CLASSROOM]->addSprite("stylo", ASSASSINATION_CLASSROOM_STYLO);
    _dungeonSpriteManager[ASSASSINATION_CLASSROOM]->addSprite("gun", ASSASSINATION_CLASSROOM_SAAUSGUN);

    _dungeonSpriteManager[ASSASSINATION_CLASSROOM]->getSprite("knifeo")->setPosition((sf::Vector2f){1700, 600});
    _dungeonSpriteManager[ASSASSINATION_CLASSROOM]->getSprite("stylo")->setPosition((sf::Vector2f){1700, 600});
    _dungeonSpriteManager[ASSASSINATION_CLASSROOM]->getSprite("gun")->setPosition((sf::Vector2f){1700, 600});

    _dungeonItems[ASSASSINATION_CLASSROOM].first.push("deathnote");
    _dungeonItems[ASSASSINATION_CLASSROOM].first.push("matraque");
    _dungeonItems[ASSASSINATION_CLASSROOM].first.push("regle");
    _dungeonItems[ASSASSINATION_CLASSROOM].second.push("knifeo");
    _dungeonItems[ASSASSINATION_CLASSROOM].second.push("stylo");
    _dungeonItems[ASSASSINATION_CLASSROOM].second.push("gun");

    // init the musics and the sounds
    if (!_music.openFromFile(MUSIC_MAP))
        std::cout << "Error while loading the music" << std::endl;
    _music.setVolume(30);
    _music.setLoop(true);

    if (_soundBuffer.loadFromFile(SOUND_SELECTION)) {
        _sound.setBuffer(_soundBuffer);
        std::cout << "[*] Sound " << SOUND_SELECTION << " is initialized" << std::endl;
    } else
        std::cout << "Error while loading the sound" << std::endl;

    if (_soundMoneyBuffer.loadFromFile(NO_MONEY_SOUND)) {
        _soundMoney.setBuffer(_soundMoneyBuffer);
        std::cout << "[*] Sound " << NO_MONEY_SOUND << " is initialized" << std::endl;
    } else
        std::cout << "Error while loading the sound" << std::endl;

    if (_soundPayBuffer.loadFromFile(PAY_SOUND)) {
        _soundPay.setBuffer(_soundPayBuffer);
        std::cout << "[*] Sound " << PAY_SOUND << " is initialized" << std::endl;
    }
}

void HomeScene::switchDungeon(std::string &scene)
{
    scene = (_currentIndex == 0) ? "onePiece" :
            (_currentIndex == 1) ? "assassinationClassroom" :
            (_currentIndex == 2) ? "dragonBall" :
            (_currentIndex == 3) ? "kurokoNoBasket" :
            "bleach";
    _music.stop();
}

void HomeScene::handleEvent(std::shared_ptr<sf::RenderWindow> &window, std::string &scene)
{
    sf::Event event;

    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window->close();
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Right) {
                _currentIndex += (_currentIndex < 4) ? 1 : -4;
                _sound.play();
            }
            else if (event.key.code == sf::Keyboard::Left) {
                _currentIndex -= (_currentIndex > 0) ? 1 : -4;
                _sound.play();
            }

            // press enter
            if (event.key.code == sf::Keyboard::Return) {
                switchDungeon(scene);
            }
        }
        // check mouse event
        if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                if (_spriteManager.getSprite("buyItemOne")->getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                    if (_currentSold >= 50) {
                        if (!_dungeonItems[(Dungeon)_currentIndex].first.empty()) {
                            _currentSold -= 50;
                            _dungeonTextManager.getText("current_sold")->setString(convertIntToString(_currentSold) + " {E}");
                            std::cout << "buy item one" << std::endl;
                            _dungeonItems[(Dungeon)_currentIndex].first.pop();
                            _soundPay.play();
                        } else {
                            _soundMoney.play();
                        }
                    } else {
                        std::cout << "not enough money" << std::endl;
                        _soundMoney.play();

                    }
                    _dungeonTextManager.getText("current_sold")->setString(convertIntToString(_currentSold) + " {E}");
                } else if (_spriteManager.getSprite("buyItemTwo")->getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                    if (_currentSold >= 100) {
                        if (!_dungeonItems[(Dungeon)_currentIndex].second.empty()) {
                            _currentSold -= 100;
                            _dungeonTextManager.getText("current_sold")->setString(convertIntToString(_currentSold) + " {E}");
                            _dungeonItems[(Dungeon)_currentIndex].second.pop();
                            std::cout << "buy item two" << std::endl;
                            _soundPay.play();
                        } else {
                            _soundMoney.play();
                        }
                    } else {
                        std::cout << "not enough money" << std::endl;
                        _soundMoney.play();
                    }
                    _dungeonTextManager.getText("current_sold")->setString(convertIntToString(_currentSold) + " {E}");
                }
            }
            // get the position of the mouse and click on the start btn
            if (_spriteManager.getSprite("start")->getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                switchDungeon(scene);
            // detect if the mouse is on the entrance of a dungeon
            if (_spriteManager.getSprite("entrance_onepiece")->getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                _currentIndex = 0;
                _sound.play();
            } else if (_spriteManager.getSprite("entrance_assassination-classroom")->getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                _currentIndex = 1;
                _sound.play();
            } else if (_spriteManager.getSprite("entrance_dragon-ball")->getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                _currentIndex = 2;
                _sound.play();
            } else if (_spriteManager.getSprite("entrance_kuroko-no-basket")->getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                _currentIndex = 3;
                _sound.play();
            } else if (_spriteManager.getSprite("entrance_bleach")->getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                _currentIndex = 4;
                _sound.play();
            }
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
            _entranceTextManager.getText("entrance_kuroko-no-basket")->setFillColor(sf::Color::White);
            break;
        case 1:
            _entranceTextManager.getText("entrance_assassination-classroom")->setFillColor(sf::Color::Red);
            _entranceTextManager.getText("entrance_onepiece")->setFillColor(sf::Color::White);
            _entranceTextManager.getText("entrance_dragon-ball")->setFillColor(sf::Color::White);
            _entranceTextManager.getText("entrance_bleach")->setFillColor(sf::Color::White);
            _entranceTextManager.getText("entrance_kuroko-no-basket")->setFillColor(sf::Color::White);
            break;
        case 2:
            _entranceTextManager.getText("entrance_dragon-ball")->setFillColor(sf::Color::Red);
            _entranceTextManager.getText("entrance_onepiece")->setFillColor(sf::Color::White);
            _entranceTextManager.getText("entrance_assassination-classroom")->setFillColor(sf::Color::White);
            _entranceTextManager.getText("entrance_bleach")->setFillColor(sf::Color::White);
            _entranceTextManager.getText("entrance_kuroko-no-basket")->setFillColor(sf::Color::White);
            break;
        case 3:
            _entranceTextManager.getText("entrance_kuroko-no-basket")->setFillColor(sf::Color::Red);
            _entranceTextManager.getText("entrance_bleach")->setFillColor(sf::Color::White);
            _entranceTextManager.getText("entrance_onepiece")->setFillColor(sf::Color::White);
            _entranceTextManager.getText("entrance_assassination-classroom")->setFillColor(sf::Color::White);
            _entranceTextManager.getText("entrance_dragon-ball")->setFillColor(sf::Color::White);
            break;
        case 4:
            _entranceTextManager.getText("entrance_bleach")->setFillColor(sf::Color::Red);
            _entranceTextManager.getText("entrance_onepiece")->setFillColor(sf::Color::White);
            _entranceTextManager.getText("entrance_assassination-classroom")->setFillColor(sf::Color::White);
            _entranceTextManager.getText("entrance_dragon-ball")->setFillColor(sf::Color::White);
            _entranceTextManager.getText("entrance_kuroko-no-basket")->setFillColor(sf::Color::White);
    }

    _isStartBtnHover = (_spriteManager.getSprite("start")->getGlobalBounds().contains(sf::Mouse::getPosition(*window).x, sf::Mouse::getPosition(*window).y)) ? true : false;

    if (_music.getStatus() != sf::SoundSource::Status::Playing)
        _music.play();
}

void HomeScene::draw(std::shared_ptr<sf::RenderWindow> &window)
{
    // display the sprites
    _spriteManager.draw(window, "home_map");
    _spriteManager.draw(window, "entrance_onepiece");
    _spriteManager.draw(window, "entrance_assassination-classroom");
    _spriteManager.draw(window, "entrance_dragon-ball");
    _spriteManager.draw(window, "entrance_bleach");
    _spriteManager.draw(window, "entrance_kuroko-no-basket");
    _spriteManager.draw(window,
            (_currentIndex == 0) ? "highScore_onepiece" :
            (_currentIndex == 1) ? "highScore_assassination-classroom" :
            (_currentIndex == 2) ? "highScore_dragon-ball" :
            (_currentIndex == 3) ? "highScore_kuroko-no-basket" :
            "highScore_bleach");
    _spriteManager.draw(window, "shop");
    //_spriteManager.draw(window, "shopCellOne");
    //_spriteManager.draw(window, "shopCellTwo");
    _spriteManager.draw(window, "buyItemOne");
    _spriteManager.draw(window, "buyItemTwo");
    _spriteManager.draw(window, (_isStartBtnHover) ? "start_hover" : "start");


    // draw the items of the shop from the stack
    if (!_dungeonItems[(Dungeon)_currentIndex].first.empty()) {
        _dungeonSpriteManager[(Dungeon)_currentIndex]->draw(window, _dungeonItems[(Dungeon)_currentIndex].first.top());
    }
    if (!_dungeonItems[(Dungeon)_currentIndex].second.empty())
        _dungeonSpriteManager[(Dungeon)_currentIndex]->draw(window, _dungeonItems[(Dungeon)_currentIndex].second.top());

    // display the text (labels)
    _entranceTextManager.draw(window, "entrance_onepiece");
    _entranceTextManager.draw(window, "entrance_assassination-classroom");
    _entranceTextManager.draw(window, "entrance_dragon-ball");
    _entranceTextManager.draw(window, "entrance_bleach");
    _entranceTextManager.draw(window, "entrance_kuroko-no-basket");

    // display the text (title)
    _dungeonTextManager.draw(window,
            (_currentIndex == 0) ? "dungeonName_onepiece" :
            (_currentIndex == 1) ? "dungeonName_assassination-classroom" :
            (_currentIndex == 2) ? "dungeonName_dragon-ball" :
            (_currentIndex == 3) ? "dungeonName_kuroko-no-basket" :
            "dungeonName_bleach");
    _dungeonTextManager.draw(window, "shopTitle");
    _dungeonTextManager.draw(window, "current_sold");
    _dungeonTextManager.draw(window, "buyCellOne");
    _dungeonTextManager.draw(window, "buyCellTwo");
    _dungeonTextManager.draw(window, "start");
}

HomeScene::~HomeScene()
{
}
