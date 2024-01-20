#pragma once
#include <string>
#include <iostream>
#include <memory>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>

class Text {
    public:
        Text();
        Text(const std::string &text);
        ~Text();

        void init(const std::string &font_path);
        void init(const std::string &font_path, const std::string &text);
        void draw(std::shared_ptr<sf::RenderWindow> &window);
        void setCharacterSize(const unsigned int &size);
        void setPosition(const sf::Vector2f &position);
        void setFillColor(const sf::Color &color);
        void setFont(const std::string &font_path);
        void setString(const std::string &text);

        sf::Text &getText();
    private:
        sf::Font _font;
        sf::Text _text;
        std::string _text_string;

};
