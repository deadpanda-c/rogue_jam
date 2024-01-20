#include "Scenes/HomeScene.hpp"

HomeScene::HomeScene()
{
    // ctor
}

void HomeScene::init()
{
    std::cout << "[*] Home is init" << std::endl;
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
    window->clear(sf::Color::Red);
    handleEvent(window, scene);
}

void HomeScene::draw(std::shared_ptr<sf::RenderWindow> &window)
{
}

HomeScene::~HomeScene()
{
}
