#include "Scenes/HomeScene.hpp"

HomeScene::HomeScene()
{
    // ctor
}

void HomeScene::init()
{
    std::cout << "[*] Home is init" << std::endl;
    _spriteManager.addSprite("home_map", HOME_MAP);
    _spriteManager.getSprite("home_map")->setScale((sf::Vector2f){2, 2});
    _spriteManager.getSprite("home_map")->setPosition((sf::Vector2f){800, 100});
}

void HomeScene::handleEvent(std::shared_ptr<sf::RenderWindow> &window, std::string &scene)
{
    sf::Event event;

    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window->close();
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
}

HomeScene::~HomeScene()
{
}
