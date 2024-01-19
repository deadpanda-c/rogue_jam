#include <iostream>
#include "Scenes/SceneManager.hpp"
#include "Scenes/MenuScene.hpp"

int main(void)
{
    SceneManager manager;

    manager.addScene("menu", std::make_shared<MenuScene>());
    manager.changeScene("menu");
    std::cout << "The current scene is " << manager.getCurrentSceneName() << std::endl;
    manager.removeScene("menu");
    return 0;
}
