//
// Created by AntonioMontana on 14/03/2017.
//

#ifndef NINJANOMEIYO_MOVEMENT_TOUCH_H
#define NINJANOMEIYO_MOVEMENT_TOUCH_H

#include <string>
#include "cocos2d.h"
#include "./Node.h"

namespace NinjaM{

    class MovementTouch : public NinjaM::Node
    {
    public:
        MovementTouch();
		MovementTouch(cocos2d::Size visibleSize, cocos2d::Vec2 position, cocos2d::Vec2 anchorPoint, std::string texture, float rotation, int sense, NinjaM::Ryunosuke* ryunosuke);
        virtual ~MovementTouch();

        virtual void spawn(cocos2d::Layer *layer);
		void setEventDispatcher(cocos2d::Layer *layer);

    private:
        NinjaM::Ryunosuke *ryunosuke;
        int sense;
	protected:
		bool getInitialTouchValues(cocos2d::Touch* touch, cocos2d::Event* event);
		void movePlayer(cocos2d::Touch* touch, cocos2d::Event* event);
		void endMovement(cocos2d::Touch* touch, cocos2d::Event* event);
    };
}

#endif //NINJANOMEIYO_MOVEMENT_TOUCH_H
