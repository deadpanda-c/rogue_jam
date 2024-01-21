//
// Created by apolline on 20/01/24.
//

#include "Scenes/dungeonTest.hpp"

void DungeonTest::init() {

    std::cout << "Init of Dungeon Test" << std::endl;
    _textManager.addText("DungeonName", "Dungeon Test", TITLE_FONT);
    _textManager.getText("DungeonName")->setCharacterSize(200);
    _textManager.getText("DungeonName")->setPosition((sf::Vector2f){100, 100});
    _textManager.getText("DungeonName")->setFillColor((sf::Color){211, 211, 211});
}

void DungeonTest::update(std::shared_ptr<sf::RenderWindow> &window, std::string &scene) {
    window->clear();
    handleEvent(window, scene);
    //call mon update anim avec son offset
}

void DungeonTest::draw(std::shared_ptr<sf::RenderWindow> &window) {
    _textManager.draw(window, "DungeonName");
    //draw l'animation
}

void DungeonTest::handleEvent(std::shared_ptr<sf::RenderWindow> &window, std::string &scene) {
    sf::Event event{};

    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window->close();
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Escape)
                window->close();
            if (event.key.code == sf::Keyboard::B)
                scene = "level_map";
        }
    }
}
