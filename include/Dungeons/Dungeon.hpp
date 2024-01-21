/*
** EPITECH PROJECT, 2024
** rogue_jam
** File description:
** Dungeon
*/

#ifndef DUNGEON_HPP_
#define DUNGEON_HPP_
#include <string>
#include <iostream>
#include <memory>
#include <map>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>

#include "Scenes/Scene.hpp"
#include "Sprite/SpriteManager.hpp"
#include "Text/TextManager.hpp"

#define CARD_BUTTON "../assets/img/start_btn.png"
#define CARD_BUTTON_HOVER "../assets/img/start_btn_hover.png"
#define FONT "../assets/fonts/PERRYGOT.TTF"

class Dungeon : public Scene {
    public:
        Dungeon();
        ~Dungeon();

        void init();
        void update(std::shared_ptr<sf::RenderWindow> &window, std::string &dungeon);
        void handleEvent(std::shared_ptr<sf::RenderWindow> &window, std::string &dungeon);
        void draw(std::shared_ptr<sf::RenderWindow> &window);
    protected:
        bool _isHoverAttack;
        bool _isHoverRun;
        SpriteManager _spriteManager;
        TextManager _textManager;
    private:
};

#endif /* !DUNGEON_HPP_ */
