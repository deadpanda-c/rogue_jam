#include "Scenes/MenuScene.hpp"

MenuScene::MenuScene()
{
    // ctor
}

void MenuScene::init()
{
    std::cout << "Menu is init" << std::endl;
}

void MenuScene::update()
{
    std::cout << "Menu is updating" << std::endl;
}

void MenuScene::draw(std::shared_ptr<sf::RenderWindow> &window)
{
    std::cout << "Menu is drawing" << std::endl;
}

MenuScene::~MenuScene()
{
}
