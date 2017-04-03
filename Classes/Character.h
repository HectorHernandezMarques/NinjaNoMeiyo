//
// Created by AntonioMontana on 14/03/2017.
//

#ifndef NINJANOMEIYO_CHARACTER_H
#define NINJANOMEIYO_CHARACTER_H

#include <string>
#include "cocos2d.h"
#include "./Node.h"

namespace NinjaM{

    class Character : public NinjaM::Node
    {
    public:
        Character();
		Character(cocos2d::Size visibleSize, cocos2d::Vec2 position, cocos2d::Vec2 anchorPoint, std::string texture, float rotation);
        virtual ~Character();

        virtual void spawn(cocos2d::Layer *layer);

    private:
	protected:
    };
}

#endif //NINJANOMEIYO_CHARACTER_H
