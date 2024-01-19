#include "Scenes/SceneManager.hpp"

SceneManager::SceneManager()
{
    //ctor
}

SceneManager::~SceneManager()
{
    //dtor
}

void SceneManager::addScene(const std::string &name, std::shared_ptr<Scene> scene)
{
    if (_scenes.find(name) != _scenes.end())
        throw std::runtime_error("Scene already exists");
    _scenes[name] = scene;
    _scenes[name]->init();
}

void SceneManager::removeScene(const std::string &name)
{
    if (_scenes.find(name) == _scenes.end())
        throw std::runtime_error("Scene not found");
    _scenes.erase(name);
}

void SceneManager::changeScene(const std::string &name)
{
    if (_scenes.find(name) == _scenes.end())
        throw std::runtime_error("Scene not found");
    _currentScene.first = _scenes[name];
    _currentScene.second = name;
}

void SceneManager::update(std::shared_ptr<sf::RenderWindow> &window, std::string &scene)
{
    _currentScene.first->update(window, scene);
}

void SceneManager::draw(std::shared_ptr<sf::RenderWindow> &window)
{
    _currentScene.first->draw(window);
}

std::string SceneManager::getCurrentSceneName() const
{
    return _currentScene.second;
}
