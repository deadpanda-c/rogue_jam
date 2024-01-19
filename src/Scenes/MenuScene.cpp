#include "Scenes/MenuScene.hpp"

MenuScene::MenuScene()
{
    // ctor
}

void MenuScene::init()
{
    std::cout << "[*] Menu is init" << std::endl;
}

void MenuScene::handleEvent(std::shared_ptr<sf::RenderWindow> &window, std::string &scene)
{
    sf::Event event;

    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window->close();
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Space) {
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
}

MenuScene::~MenuScene()
{
}
