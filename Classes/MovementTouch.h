//
// Created by AntonioMontana on 14/03/2017.
//

#ifndef NINJANOMEIYO_MOVEMENT_TOUCH_H
#define NINJANOMEIYO_MOVEMENT_TOUCH_H

#include <string>
#include "Definitions.h"
#include "cocos2d.h"
#include "./Touch.h"
#include "./Ryunosuke.h"

namespace NinjaM{

    class MovementTouch : public NinjaM::Touch
    {
    public:
        MovementTouch();
		MovementTouch(cocos2d::Size visibleSize, cocos2d::Vec2 position, cocos2d::Vec2 anchorPoint, float rotation, int sense, NinjaM::Ryunosuke* ryunosuke);
        virtual ~MovementTouch();

        virtual void spawn(cocos2d::Layer *layer);
		void setEventDispatcher();

    private:
		std::mutex mDoubleTouch, mForcingUntouch, mGestureMade;
		/*we want to avoid the user touching the same touch detector twice*/
		/*we want to force the user to stop to touch the screen once he has made a gesture*/

        NinjaM::Ryunosuke *ryunosuke;
        int sense;
		cocos2d::Vec2 initialVelocity;
		cocos2d::Sequence *jumpCleanerSequence;
		cocos2d::Action *movingAction;
	protected:
	    void toMoveAfterWait(float sense);

		bool getInitialTouchValues(cocos2d::Touch* touch, cocos2d::Event* event);
		void moveTouch(cocos2d::Touch* touch, cocos2d::Event* event);
		void endMovement(cocos2d::Touch* touch, cocos2d::Event* event);
    };
}

#endif //NINJANOMEIYO_MOVEMENT_TOUCH_H
