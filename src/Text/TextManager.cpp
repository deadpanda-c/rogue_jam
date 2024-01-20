#include "Text/TextManager.hpp"

TextManager::TextManager()
{

}

TextManager::~TextManager()
{

}

void TextManager::addText(const std::string &name, const std::string &text, const std::string &font_path)
{
    if (_texts.find(name) != _texts.end())
        throw std::runtime_error("TextManager::addText: Text already exists");
    _texts[name] = std::make_shared<Text>(text);
    _texts[name]->init(font_path);
}

void TextManager::addText(const std::string &name, size_t nb, const std::string &font_path)
{
    if (_texts.find(name) != _texts.end())
        throw std::runtime_error("TextManager::addText: Text already exists");
    std::stringstream ss;
    ss << nb;
    _texts[name] = std::make_shared<Text>(ss.str());
    _texts[name]->init(font_path);
}

void TextManager::draw(std::shared_ptr<sf::RenderWindow> &window, const std::string &name)
{
    if (_texts.find(name) == _texts.end())
        throw std::runtime_error("TextManager::draw: Text doesn't exist");
    _texts[name]->draw(window);
}
