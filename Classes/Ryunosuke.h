//
// Created by AntonioMontana on 14/03/2017.
//

#ifndef NINJANOMEIYO_RYUNOSUKE_H
#define NINJANOMEIYO_RYUNOSUKE_H

#include <string>
#include "cocos2d.h"
#include "./Character.h"

namespace NinjaM{

    class Ryunosuke : public NinjaM::Character
    {
    public:
        Ryunosuke();
		Ryunosuke(cocos2d::Size visibleSize, cocos2d::Vec2 position, cocos2d::Vec2 anchorPoint, std::string texture, float rotation);
        virtual ~Ryunosuke();

        virtual void spawn(cocos2d::Layer *layer);
		void setEventDispatcher(cocos2d::Layer *layer);

    private:
		//EventListenerTouchOneByOne::cocos2d* listener;
		void movePlayer(cocos2d::Touch* touch, cocos2d::Event* event);
	protected:
    };
}

#endif //NINJANOMEIYO_RYUNOSUKE_H
