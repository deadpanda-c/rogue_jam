#include "Scenes/MenuScene.hpp"

MenuScene::MenuScene()
{
    // ctor
}

void MenuScene::init()
{
    std::cout << "[*] Menu is init" << std::endl;
    _spriteManager.addSprite("default_play_btn", DEFAULT_PLAY_BTN);
    _spriteManager.getSprite("default_play_btn")->setPosition((sf::Vector2f){800, 500});
    _spriteManager.getSprite("default_play_btn")->setScale((sf::Vector2f){1.5, 1.5});

    _spriteManager.addSprite("hover_play_btn", HOVER_PLAY_BTN);
    _spriteManager.getSprite("hover_play_btn")->setPosition((sf::Vector2f){800, 500});
    _spriteManager.getSprite("hover_play_btn")->setScale((sf::Vector2f){1.5, 1.5});
    _isHoverPlayBtn = false;
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
                scene = "game";
            }
        }
        if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                if (_isHoverPlayBtn) {
                    std::cout << "Play button pressed" << std::endl;
                    scene = "game";
                }
            }
        }
    }
}

void MenuScene::update(std::shared_ptr<sf::RenderWindow> &window, std::string &scene)
{
    window->clear();
    handleEvent(window, scene);
    _isHoverPlayBtn = _spriteManager.getSprite("default_play_btn")->getGlobalBounds().contains(sf::Mouse::getPosition(*window).x, sf::Mouse::getPosition(*window).y);
}

void MenuScene::draw(std::shared_ptr<sf::RenderWindow> &window)
{
    if (_isHoverPlayBtn)
        _spriteManager.draw(window, "hover_play_btn");
    else
        _spriteManager.draw(window, "default_play_btn");
}

MenuScene::~MenuScene()
{
    // dtor
}
