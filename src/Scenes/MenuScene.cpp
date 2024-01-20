#include "Scenes/MenuScene.hpp"

MenuScene::MenuScene()
{
    // ctor
}

void MenuScene::init()
{
    std::cout << "[*] Menu is init" << std::endl;
    _spriteManager.addSprite("default_play_btn", DEFAULT_PLAY_BTN);
    _spriteManager.getSprite("default_play_btn")->setPosition((sf::Vector2f){100, 100});
    _spriteManager.getSprite("default_play_btn")->setScale((sf::Vector2f){2, 2});

    _spriteManager.addSprite("hover_play_btn", HOVER_PLAY_BTN);
    _spriteManager.getSprite("hover_play_btn")->setPosition((sf::Vector2f){100, 100});
    _spriteManager.getSprite("hover_play_btn")->setScale((sf::Vector2f){2, 2});
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
    }
}

void MenuScene::update(std::shared_ptr<sf::RenderWindow> &window, std::string &scene)
{
    window->clear();
    handleEvent(window, scene);
}

void MenuScene::draw(std::shared_ptr<sf::RenderWindow> &window)
{
    _spriteManager.draw(window); // draw every sprites registered in the spritemanager
}

MenuScene::~MenuScene()
{
    // dtor
}
