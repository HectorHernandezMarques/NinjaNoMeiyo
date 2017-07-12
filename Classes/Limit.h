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
        Limit(cocos2d::Size visibleSize, cocos2d::Vec2 position, cocos2d::Vec2 anchorPoint, std::string texture, float rotation, std::vector<cocos2d::Vec2> points, int count);
        virtual ~Limit();

		void setPoints(std::vector<cocos2d::Vec2> points);
        virtual void spawn(cocos2d::Layer *layer, int limitBitmask);

    private:
		std::vector<cocos2d::Vec2> points;
		int count;
    };
}

#endif //NINJANOMEIYO_LIMIT_H
