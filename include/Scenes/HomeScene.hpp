#pragma once
#include "Scene.hpp"
#include "Player.hpp"

#include "Sprite/SpriteManager.hpp"
#include "Text/TextManager.hpp"

#define HOME_MAP "../assets/img/home.png"

#define START_BUTTON "../assets/img/start_btn.png"
#define START_BUTTON_HOVER "../assets/img/start_btn_hover.png"

#define MUSIC_MAP "../assets/musics/intermediary_map_music.ogg"
#define SOUND_SELECTION "../assets/sounds/ting.wav"

#define FONT_TEXT  "../assets/fonts/PERRYGOT.TTF"
#define ARIAL_FONT "../assets/fonts/Arial.ttf"

#define ONEPIECE 0
#define DRAGONBALL 1
#define ASSASSINATION_CLASSROOM 2
#define BLEACH 3

class HomeScene : public Scene {
    public:
        HomeScene();
        ~HomeScene();

        void init();
        void update(std::shared_ptr<sf::RenderWindow> &window, std::string &scene);
        void draw(std::shared_ptr<sf::RenderWindow> &window);
        void switchDungeon(std::string &scene);
        void handleEvent(std::shared_ptr<sf::RenderWindow> &window, std::string &scene);
    private:
        sf::SoundBuffer _soundBuffer;
        sf::Sound _sound;
        sf::Music _music;
        bool _isStartBtnHover;
        unsigned int _currentSold;
        SpriteManager _spriteManager;
        TextManager _entranceTextManager;
        TextManager _dungeonTextManager;
        int _currentIndex;
};
