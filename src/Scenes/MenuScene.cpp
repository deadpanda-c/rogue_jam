#include "Scenes/MenuScene.hpp"

MenuScene::MenuScene()
{
    // ctor
}

void MenuScene::init()
{
    std::cout << "[*] Menu is init" << std::endl;
    _spriteManager.addSprite("test", ""); // add a sprite into the sprites manager. If the path (second arg) is empty, a rectangle is going to be set instead
    _spriteManager.getSprite("test")->setScale((sf::Vector2f){2, 2}); // by default, the size and the position are up to 0, 0. You should change it like that
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
    window->clear(sf::Color::Blue);
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
