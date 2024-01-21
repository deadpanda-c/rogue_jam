#pragma once
#include <stack>

#include "Scene.hpp"
#include "Player.hpp"

#include "Sprite/SpriteManager.hpp"
#include "Text/TextManager.hpp"

#define HOME_MAP "../assets/img/home.png"


#define ONEPIECE_LOGO "../assets/img/onepiece/logo.png"
#define DRAGONBALL_LOGO "../assets/img/dragon_ball/logo.png"
#define KUROKO_LOGO "../assets/img/kuroko/logo.png"
#define ASSASSINATION_CLASSROOM_LOGO "../assets/img/assassination_classroom/logo.png"
#define BLEACH_LOGO "../assets/img/bleach/logo.png"

#define START_BUTTON "../assets/img/start_btn.png"
#define START_BUTTON_HOVER "../assets/img/start_btn_hover.png"

#define MUSIC_MAP "../assets/musics/intermediary_map_music.ogg"
#define SOUND_SELECTION "../assets/sounds/ting.wav"
#define NO_MONEY_SOUND "../assets/sounds/bonhomme.wav"
#define PAY_SOUND "../assets/sounds/pay.wav"

#define FONT_TEXT  "../assets/fonts/PERRYGOT.TTF"
#define ARIAL_FONT "../assets/fonts/Arial.ttf"

#define ONEPIECE_HAT "../assets/img/onepiece/chapeau.png"
#define ONEPIECE_DIALS "../assets/img/onepiece/dials.png"
#define ONEPIECE_GOMUGOMU "../assets/img/onepiece/gomugomu.png"
#define ONEPIECE_ITOITO "../assets/img/onepiece/itoito.png"
#define ONEPIECE_LOGPOSE "../assets/img/onepiece/logpose.png"
#define ONEPIECE_MERA "../assets/img/onepiece/meramera.png"

#define KUROKO_BASKET "../assets/img/kuroko/Basketball.png"
#define KUROKO_KAIJO "../assets/img/kuroko/Kaijo.png"
#define KUROKO_ZONE "../assets/img/kuroko/Zone.png"
#define KUROKO_SEIRIN "../assets/img/kuroko/seirin.png"
#define KUROKO_WRISTBAND "../assets/img/kuroko/wristband.png"
#define KUROKO_YOSEN "../assets/img/kuroko/yosen.png"

#define DRAGONBALL_BARRIER "../assets/img/dragon_ball/Barrier_Recover_Device.png"
#define DRAGONBALL_BALL "../assets/img/dragon_ball/Dragon_ball.png"
#define DRAGONBALL_CAPSULE "../assets/img/dragon_ball/Capsule_Corps.png"
#define DRAGONBALL_ESCAPE "../assets/img/dragon_ball/Escape_Pod.png"
#define DRAGONBALL_POWERKEY "../assets/img/dragon_ball/Power_Key.png"
#define DRAGONBALL_ENERGYCUBE "../assets/img/dragon_ball/Small_Energy_Cube.png"

#define BLEACH_ARCURYU "../assets/img/bleach/arcuryu.png"
#define BLEACH_GOKKONTEKKO "../assets/img/bleach/gokkontekko.png"
#define BLEACH_HOUGYOKU "../assets/img/bleach/hogyuku.png"
#define BLEACH_SODENOSHIRAYUKI "../assets/img/bleach/sodenoshirayuki.png"
#define BLEACH_SOULCANDY "../assets/img/bleach/soulcandy.png"
#define BLEACH_ZANGETSU "../assets/img/bleach/zangetsu.png"

#define ASSASSINATION_CLASSROOM_DEATHNOTE "../assets/img/assassination_classroom/deathnote.png"
#define ASSASSINATION_CLASSROOM_MATRAQUE "../assets/img/assassination_classroom/matraqueelectique.png"
#define ASSASSINATION_CLASSROOM_REGLE "../assets/img/assassination_classroom/regle.png"
#define ASSASSINATION_CLASSROOM_SAAUSKNIFEO "../assets/img/assassination_classroom/saausknifeo.png"
#define ASSASSINATION_CLASSROOM_STYLO "../assets/img/assassination_classroom/stylo.png"
#define ASSASSINATION_CLASSROOM_SAAUSGUN "../assets/img/assassination_classroom/saausogun.png"

#define BEGGINER 0
#define INTERMEDIATE 1
#define ADVANCED 2

class HomeScene : public Scene {
    public:
        typedef enum {
            ONEPIECE,
            ASSASSINATION_CLASSROOM,
            DRAGONBALL,
            KUROKO,
            BLEACH
        } Dungeon;
        HomeScene();
        ~HomeScene();

        void init();
        void initLevel(std::vector<bool> &levelUnlocked);
        void update(std::shared_ptr<sf::RenderWindow> &window, std::string &scene);
        void draw(std::shared_ptr<sf::RenderWindow> &window);
        void switchDungeon(std::string &scene);
        void handleEvent(std::shared_ptr<sf::RenderWindow> &window, std::string &scene);
    private:
        sf::SoundBuffer _soundBuffer;
        sf::SoundBuffer _soundMoneyBuffer;
        sf::SoundBuffer _soundPayBuffer;
        sf::Sound _sound;
        sf::Sound _soundMoney;
        sf::Sound _soundPay;
        sf::Music _music;
        bool _isStartBtnHover;
        unsigned int _currentSold;
        SpriteManager _spriteManager;
        TextManager _entranceTextManager;
        TextManager _dungeonTextManager;
        int _currentIndex;
        std::map<Dungeon, std::shared_ptr<SpriteManager>> _dungeonSpriteManager;
        std::map<Dungeon, std::pair<int, int>> _dungeonLevelPrice;
        std::map<Dungeon, std::vector<bool>> _dungeonLevelUnlocked;

        std::map<Dungeon, std::pair<std::stack<std::string>, std::stack<std::string>>> _dungeonItems;
};
