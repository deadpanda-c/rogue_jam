#include "Scenes/GameScene.hpp"

GameScene::GameScene()
{
    // ctor
}

void GameScene::init()
{
    std::cout << "[*] Game is init" << std::endl;
}

void GameScene::handleEvent(std::shared_ptr<sf::RenderWindow> &window, std::string &scene)
{
    sf::Event event;

    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window->close();
    }
}

void GameScene::update(std::shared_ptr<sf::RenderWindow> &window, std::string &scene)
{
    window->clear(sf::Color::Red);
    handleEvent(window, scene);
}

void GameScene::draw(std::shared_ptr<sf::RenderWindow> &window)
{
}

GameScene::~GameScene()
{
}
