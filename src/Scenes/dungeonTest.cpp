//
// Created by apolline on 20/01/24.
//

#include "Scenes/dungeonTest.hpp"

void DungeonTest::init() {

    test = 0;
    std::cout << "Init of Dungeon Test" << std::endl;
    // prefill vector
    std::vector<sf::IntRect> rect = {
        sf::IntRect(7, 41, 70, 89),
        sf::IntRect(102, 41, 70, 89),
        sf::IntRect(196, 42, 70, 89),
        sf::IntRect(281, 42, 70, 89)
    };

    std::string name = "renji";
    _spriteManager.addSprite("renji", "../assets/characters/renji_standby.png");
    _spriteManager.getSprite("renji")->setScale((sf::Vector2f){2, 2});
    _spriteManager.addAnimation("animate_renji", name, rect, 0.5);
}

void DungeonTest::update(std::shared_ptr<sf::RenderWindow> &window, std::string &scene) {
    window->clear();
    handleEvent(window, scene);
    _spriteManager.playAnimation("animate_renji", test);
    test += (test == 3) ? -3 : 1;
}

void DungeonTest::draw(std::shared_ptr<sf::RenderWindow> &window)
{
    _spriteManager.draw(window);
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
