//
// Created by AntonioMontana on 14/03/2017.
//

#ifndef NINJANOMEIYO_RYUNOSUKE_H
#define NINJANOMEIYO_RYUNOSUKE_H

#include <string>
#include "Definitions.h"
#include "cocos2d.h"
#include "./Character.h"

namespace NinjaM{

    class Ryunosuke : public NinjaM::Character
    {
    public:
        Ryunosuke();
		Ryunosuke(cocos2d::Size visibleSize, cocos2d::Vec2 position, cocos2d::Vec2 anchorPoint, std::string texture, float rotation, cocos2d::Size boxSize);
        virtual ~Ryunosuke();

        virtual void spawn(cocos2d::Layer *layer);
		void toMove(float velocity);
		void toStop(float velocity);
		void toJump(float velocity);

		void setEventDispatcher();

    private:
        std::mutex mNextJump, mWallDetection, mJumpTrigger;

		bool rightMovement = false;
		bool leftMovement = false;
		float lastXVelocity = 0.0;
		bool onTheFloor = false;
		
		bool onTheRightWall = false; //0x000030 0x000031
		bool onTheLeftWall = false; //0x000040 0x000041

		bool onTheOilRightWall = false; //0x000033 0x000034
		bool onTheOilLeftWall = false; //0x000043 0x000044

		bool onTheEdgeFloor = false; //0x000024
		bool onTheEdgeRightWall = false; //0x000034
		bool onTheEdgeLeftWall = false; //0x000044

		cocos2d::Node* edgeFloorNode;
		cocos2d::Node* rightEdgeWallNode;
		cocos2d::Node* leftEdgeWallNode;

        cocos2d::Size boxSize;

		bool nextJump = false;
		float nextJumpVelocity = 0.0;
		unsigned int jumpCounter = 0;

		void jumpCleaner(unsigned int jumpCounter);
	protected:
		bool onContactBegin(cocos2d::PhysicsContact &contact);
		bool onContactSeparate(cocos2d::PhysicsContact &contact);


    };
}

#endif //NINJANOMEIYO_RYUNOSUKE_H
