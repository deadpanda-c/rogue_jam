#pragma once
#include <string>
#include <iostream>
#include <memory>
#include <map>

class Scene {
    public:
        Scene();
        virtual ~Scene() = default;

        virtual void init() = 0;
        virtual void update() = 0;
        virtual void draw() = 0;
};
