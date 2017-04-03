//
// Created by AntonioMontana on 14/03/2017.
//

#ifndef NINJANOMEIYO_TERRAIN_H
#define NINJANOMEIYO_TERRAIN_H

#include <string>
#include "cocos2d.h"
#include "./Node.h"

namespace NinjaM{

    class Terrain : public NinjaM::Node
    {
    public:
        Terrain();
        Terrain(std::string texture, cocos2d::Vec2 position);
        virtual ~Terrain();

        virtual void spawn(cocos2d::Layer *layer);

    private:
    };
}

#endif //NINJANOMEIYO_TERRAIN_H
