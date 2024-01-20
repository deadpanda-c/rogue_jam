#pragma once
#include <string>
#include <iostream>
#include <map>
#include <memory>
#include <sstream>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>

#include "Text/Text.hpp"

class TextManager {
    public:
        TextManager();
        ~TextManager();

        void addText(const std::string &name, const std::string &text, const std::string &font_path);
        void addText(const std::string &name, size_t nb, const std::string &font_path);
        void draw(std::shared_ptr<sf::RenderWindow> &window, const std::string &name);
        std::map<std::string, std::shared_ptr<Text>> getTexts() const { return _texts; }
        std::shared_ptr<Text> getText(const std::string &name) const { return _texts.at(name); }
    private:
        std::map<std::string, std::shared_ptr<Text>> _texts;
};
