//
// Created by apolline on 20/01/24.
//

#include "Scenes/dungeonTest.hpp"

void DungeonTest::init() {

    std::cout << "Init of Dungeon Test" << std::endl;
}

void DungeonTest::update(std::shared_ptr<sf::RenderWindow> &window, std::string &scene) {
    window->clear();
    handleEvent(window, scene);
}

void DungeonTest::draw(std::shared_ptr<sf::RenderWindow> &window) {
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
