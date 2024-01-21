#pragma once

#include "Entity.hpp"

#define PLAYER_IDLE "../assets/characters/zoro_idle.png"
#define PLAYER_WALK "../assets/characters/zoro_walk.png"
#define PLAYER_ATTACK "../assets/characters/zoro_attack.png"

class Player : public Entity {
    public:
        typedef enum {
            IDLE,
            WALK,
            ATTACK,
            DIE,
        } Animations;
        Player();
        ~Player();

        void init();
        void update(std::shared_ptr<sf::RenderWindow> &window);
        void attack();
        void draw(std::shared_ptr<sf::RenderWindow> &window);
    private:
        Animations _currentAnimation;
        int _animationIndexAttack;
        int _animationIndexWalk;
        int _animationIndexIdle;

};
