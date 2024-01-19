#pragma once
#include "Scene.hpp"

class MenuScene : public Scene {
    public:
        MenuScene();
        virtual ~MenuScene();

        virtual void init();
        virtual void update();
        virtual void draw();
    private:
};
