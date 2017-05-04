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
		void toMove(float velocity);
		void toStop(float velocity);
		void toJump(float velocity);

		void setEventDispatcher();

    private:
        std::mutex mNextJump;

		bool rightMovement = false;
		bool leftMovement = false;
		float lastXVelocity = 0.0;
		bool onTheFloor = false;
		bool onTheRightWall = false; //0x000003
		bool onTheLeftWall = false; //0x000004
		float nextJump = 0.0;
		unsigned int jumpCounter = 0;

		void jumpCleaner(unsigned int dt, unsigned int jumpCounter);
	protected:
		bool onContactBegin(cocos2d::PhysicsContact &contact);
		bool onContactSeparate(cocos2d::PhysicsContact &contact);


    };
}

#endif //NINJANOMEIYO_RYUNOSUKE_H
