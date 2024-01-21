#pragma once
#include "Scene.hpp"
#include <memory>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include "Dungeons/DungeonManager.hpp"

class SceneManager {
    public:
        SceneManager();
        ~SceneManager();

        void addScene(const std::string &name, std::shared_ptr<Scene> scene);
        void removeScene(const std::string &name);
        void changeScene(const std::string &name);
        std::string getCurrentSceneName() const;
        void update(std::shared_ptr<sf::RenderWindow> &window, std::string &scene);
        void draw(std::shared_ptr<sf::RenderWindow> &window);
    private:
        std::pair<std::shared_ptr<Scene>, std::string> _currentScene;
        std::map<std::string, std::shared_ptr<Scene>> _scenes;
        DungeonManager _dungeons;
};
