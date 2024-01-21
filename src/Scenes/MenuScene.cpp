#include "Scenes/MenuScene.hpp"

MenuScene::MenuScene()
{
    // ctor
}

void MenuScene::init()
{
    std::cout << "[*] Menu is init" << std::endl;
    _spriteManager.addSprite("background", BACKGROUND_MENU);
    _spriteManager.getSprite("background")->setScale((sf::Vector2f){1, 1});

    _spriteManager.addSprite("default_play_btn", DEFAULT_PLAY_BTN);
    _spriteManager.getSprite("default_play_btn")->setPosition((sf::Vector2f){800, 500});
    _spriteManager.getSprite("default_play_btn")->setScale((sf::Vector2f){1.5, 1.5});

    _spriteManager.addSprite("hover_play_btn", HOVER_PLAY_BTN);
    _spriteManager.getSprite("hover_play_btn")->setPosition((sf::Vector2f){800, 500});
    _spriteManager.getSprite("hover_play_btn")->setScale((sf::Vector2f){1.5, 1.5});
    _isHoverPlayBtn = false;

    _textManager.addText("title", "Dungeon Odyssey", TITLE_FONT);
    _textManager.getText("title")->setCharacterSize(100);
    _textManager.getText("title")->setPosition((sf::Vector2f){400, 100});
    _textManager.getText("title")->setFillColor((sf::Color){211, 211, 211});

    if (!_music.openFromFile(MUSIC_MENU))
        std::cout << "Error while loading music" << std::endl;
    _music.setLoop(true);

    if (!_playSoundBuffer.loadFromFile(PLAY_SOUND))
        std::cout << "Error while loading sound: " << PLAY_SOUND << std::endl;

    _playSound.setBuffer(_playSoundBuffer);
    std::cout << "playsound status: " << _playSound.getStatus() << std::endl;
    std::cout << "[*] Menu is init done" << std::endl;
}

void MenuScene::handleEvent(std::shared_ptr<sf::RenderWindow> &window, std::string &scene)
{
    sf::Event event;

    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window->close();
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Space) { // switch from scene Menu to scene Game
                std::cout << "Space pressed" << std::endl;
                _playSound.play();
                scene = "level_map";
            }
        }
        if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                if (_isHoverPlayBtn) {
                    std::cout << "Play button pressed" << std::endl;
                    _playSound.play();
                    scene = "level_map";
                }
            }
        }
        if (scene == "game") {
            _music.stop();
        }
    }
}

void MenuScene::update(std::shared_ptr<sf::RenderWindow> &window, std::string &scene)
{
    if (!_music.getStatus()) {
        _music.play();
    }
    window->clear();
    handleEvent(window, scene);
    _isHoverPlayBtn = _spriteManager.getSprite("default_play_btn")->getGlobalBounds().contains(sf::Mouse::getPosition(*window).x, sf::Mouse::getPosition(*window).y);
}

void MenuScene::draw(std::shared_ptr<sf::RenderWindow> &window)
{
    // sprite draw
    _spriteManager.draw(window, "background");
    if (_isHoverPlayBtn)
        _spriteManager.draw(window, "hover_play_btn");
    else
        _spriteManager.draw(window, "default_play_btn");

    // text draw
    _textManager.draw(window, "title");
}

MenuScene::~MenuScene()
{
    // dtor
}
