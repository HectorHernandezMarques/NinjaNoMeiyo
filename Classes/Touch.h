//
// Created by AntonioMontana on 14/03/2017.
//

#ifndef NINJANOMEIYO_TOUCH_H
#define NINJANOMEIYO_TOUCH_H

#include <string>
#include "cocos2d.h"
#include "./Node.h"

namespace NinjaM{

    class Touch : public NinjaM::Node
    {
    public:
        Touch();
		Touch(cocos2d::Size visibleSize, cocos2d::Vec2 position, cocos2d::Vec2 anchorPoint, std::string texture, float rotation);
        virtual ~Touch();

        virtual void spawn(cocos2d::Layer *layer);
		void setEventDispatcher(cocos2d::Layer *layer);

    private:
	protected:
		//EventListenerTouchOneByOne::cocos2d* listener;
		cocos2d::Vec2 positionVariation;
		cocos2d::Vec2 initialTouchPosition;

		virtual bool getInitialTouchValues(cocos2d::Touch* touch, cocos2d::Event* event);
		virtual void movePlayer(cocos2d::Touch* touch, cocos2d::Event* event);
		virtual void endMovement(cocos2d::Touch* touch, cocos2d::Event* event);
    };
}

#endif //NINJANOMEIYO_TOUCH_H
