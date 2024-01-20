#include "Text/Text.hpp"

Text::Text()
{

}

Text::Text(const std::string &text)
{
    _text_string = text;
}

Text::~Text()
{

}

void Text::init(const std::string &font_path)
{
    if (!_font.loadFromFile(font_path)) {
        std::cout << "Error loading font" << std::endl;
        return;
    }
    std::cout << "[*] Text::init - Text '" << _text_string << "' is initialized" << std::endl;
    _text.setFont(_font);
    _text.setString(_text_string);
    _text.setCharacterSize(24);
    _text.setFillColor(sf::Color::White);
    _text.setStyle(sf::Text::Bold);
    _text.setPosition(0, 0);
}

sf::Text &Text::getText()
{
    return _text;
}

void Text::init(const std::string &font_path, const std::string &text)
{
    _text_string = text;
    return init(font_path);
}

void Text::setCharacterSize(const unsigned int &size)
{
    _text.setCharacterSize(size);
}

void Text::setPosition(const sf::Vector2f &position)
{
    _text.setPosition(position);
}

void Text::setFillColor(const sf::Color &color)
{
    _text.setFillColor(color);
}

void Text::setFont(const std::string &font_path)
{
    if (!_font.loadFromFile(font_path)) {
        std::cout << "Error loading font" << std::endl;
        return;
    }
    _text.setFont(_font);
}

void Text::setString(const std::string &text)
{
    _text.setString(text);
}

void Text::draw(std::shared_ptr<sf::RenderWindow> &window)
{
    window->draw(_text);
}
