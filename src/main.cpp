#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

#include <memory>
#include <iostream>

#include "Scenes/SceneManager.hpp"
#include "Scenes/MenuScene.hpp"

typedef enum {
    MENU,
    GAME,
    PAUSE,
    GAMEOVER,
    WIN
} GameState;

static const int WINDOW_WIDTH = 800;
static const int WINDOW_HEIGHT = 600;

int main(void)
{
    std::shared_ptr<sf::RenderWindow> window = std::make_shared<sf::RenderWindow>(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Dungeon Odyssey");
    window->setFramerateLimit(60);
    GameState gameState = MENU;

    SceneManager sceneManager;

    sceneManager.addScene("menu", std::make_shared<MenuScene>());

    sceneManager.changeScene("menu");
    while (window->isOpen()) {

        sceneManager.update();
        window->clear();
        sceneManager.draw(window);
        window->display();
    }
    return 0;
}
