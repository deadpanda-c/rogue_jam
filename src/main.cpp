#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

#include <memory>
#include <iostream>

#include "Scenes/SceneManager.hpp"
#include "Scenes/MenuScene.hpp"
#include "Scenes/HomeScene.hpp"

#include "Dungeons/AssassinationClassroomDungeon.hpp"
#include "Dungeons/BleachDungeon.hpp"
#include "Dungeons/OnePieceDungeon.hpp"
#include "Dungeons/DragonBallDungeon.hpp"
#include "Dungeons/KurokoNoBasketDungeon.hpp"

static const int WINDOW_WIDTH = 1920;
static const int WINDOW_HEIGHT = 1080;

int main(void)
{
    std::shared_ptr<sf::RenderWindow> window = std::make_shared<sf::RenderWindow>(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Dungeon Odyssey");
    window->setFramerateLimit(60);

    // scene management
    SceneManager sceneManager;
    std::string currentScene = "menu";
    sceneManager.addScene("menu", std::make_shared<MenuScene>());
    sceneManager.addScene("game", std::make_shared<HomeScene>());
    sceneManager.addScene("assassinationClassroom", std::make_shared<AssassinationClassroomDungeon>());
    sceneManager.addScene("bleach", std::make_shared<BleachDungeon>());
    sceneManager.addScene("onePiece", std::make_shared<OnePieceDungeon>());
    sceneManager.addScene("dragonBall", std::make_shared<DragonBallDungeon>());
    sceneManager.addScene("kurokoNoBasket", std::make_shared<KurokoNoBasketDungeon>());

    sceneManager.changeScene("menu");
    while (window->isOpen()) {

        // transition between scenes
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
