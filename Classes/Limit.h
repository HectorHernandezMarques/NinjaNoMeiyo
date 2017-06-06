//
// Created by AntonioMontana on 14/03/2017.
//

#ifndef NINJANOMEIYO_LIMIT_H
#define NINJANOMEIYO_LIMIT_H

#include <string>
#include "Definitions.h"
#include "cocos2d.h"
#include "./PhysicNode.h"

namespace NinjaM{

    class Limit : public NinjaM::PhysicNode
    {
    public:
        Limit();
        Limit(cocos2d::Size visibleSize, cocos2d::Vec2 position, cocos2d::Vec2 anchorPoint, std::string texture, float rotation, cocos2d::Size contentSize, int count);
        virtual ~Limit();

		void setPoints(cocos2d::Vec2 p0, cocos2d::Vec2 p1, cocos2d::Vec2 p2, cocos2d::Vec2 p3);
        virtual void spawn(cocos2d::Layer *layer, int limitBitmask);

    private:
		cocos2d::Size contentSize;
		cocos2d::Vec2 points[4];
		int count;
    };
}

#endif //NINJANOMEIYO_LIMIT_H
