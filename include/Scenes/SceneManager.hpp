#pragma once
#include "Scene.hpp"
#include <memory>
#include <string>

class SceneManager {
    public:
        SceneManager();
        ~SceneManager();

        void addScene(const std::string &name, std::shared_ptr<Scene> scene);
        void removeScene(const std::string &name);
        void changeScene(const std::string &name);
        std::string getCurrentSceneName() const;
        void update();
        void draw();
    private:
        std::pair<std::shared_ptr<Scene>, std::string> _currentScene;
        std::map<std::string, std::shared_ptr<Scene>> _scenes;
};
