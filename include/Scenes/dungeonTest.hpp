#pragma once
#include "Scene.hpp"
#include "Sprite/SpriteManager.hpp"
#include "Text/TextManager.hpp"

#define TITLE_FONT "../assets/fonts/PERRYGOT.TTF"

class DungeonTest : public Scene {
public:
    DungeonTest() = default;

    void init() override;
    void update(std::shared_ptr<sf::RenderWindow> &window, std::string &scene) override;
    void draw(std::shared_ptr<sf::RenderWindow> &window) override;
    void handleEvent(std::shared_ptr<sf::RenderWindow> &window, std::string &scene) override;
private:
    SpriteManager _spriteManager;
    TextManager _textManager;
};
