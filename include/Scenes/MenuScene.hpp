#pragma once
#include "Scene.hpp"
#include "Sprite/SpriteManager.hpp"
#include "Text/TextManager.hpp"

#define DEFAULT_PLAY_BTN "../assets/img/play_default.png"
#define HOVER_PLAY_BTN "../assets/img/play_hover.png"

#define BACKGROUND_MENU "../assets/img/menu.png"

#define MUSIC_MENU "../assets/musics/menu_song.ogg"
#define PLAY_SOUND "../assets/sounds/play_sound.wav"

#define TITLE_FONT "../assets/fonts/PERRYGOT.TTF"

class MenuScene : public Scene {
    public:
        MenuScene();
        ~MenuScene();

        void init();
        void update(std::shared_ptr<sf::RenderWindow> &window, std::string &scene);
        void draw(std::shared_ptr<sf::RenderWindow> &window);
        void handleEvent(std::shared_ptr<sf::RenderWindow> &window, std::string &scene);
    private:
        sf::Music _music;
        sf::SoundBuffer _playSoundBuffer;
        sf::Sound _playSound;
        SpriteManager _spriteManager;
        TextManager _textManager;
        bool _isHoverPlayBtn;
};
