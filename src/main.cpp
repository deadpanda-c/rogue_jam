#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

#include <memory>
#include <iostream>

#include "Scenes/SceneManager.hpp"
#include "Scenes/MenuScene.hpp"
#include "Scenes/GameScene.hpp"

static const int WINDOW_WIDTH = 800;
static const int WINDOW_HEIGHT = 600;

int main(void)
{
    std::shared_ptr<sf::RenderWindow> window = std::make_shared<sf::RenderWindow>(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Dungeon Odyssey");
    window->setFramerateLimit(60);
    std::string currentScene = "menu";

    SceneManager sceneManager;

    sceneManager.addScene("menu", std::make_shared<MenuScene>());
    sceneManager.addScene("game", std::make_shared<GameScene>());

    sceneManager.changeScene("menu");
    while (window->isOpen()) {

        if (currentScene != sceneManager.getCurrentSceneName()) {
            sceneManager.changeScene(currentScene);
            std::cout << "Scene changed to " << currentScene << std::endl;
        }
        sceneManager.update(window, currentScene);
        sceneManager.draw(window);
        window->display();
    }
    return 0;
}
