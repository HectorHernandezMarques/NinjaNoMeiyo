//
// Created by AntonioMontana on 14/03/2017.
//

#ifndef NINJANOMEIYO_RYUNOSUKE_H
#define NINJANOMEIYO_RYUNOSUKE_H

#include <string>
#include <set>
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
		void toMove(float velocity, bool waitWallDetection);
		void toStop(float velocity);
		void toJump(float velocity, bool waitWallDetection);

		void setEventDispatcher();

    private:
        std::mutex mNextJump, mWallDetection, mJumpTrigger, mSingleMovement;

		bool rightMovement = false;
		bool leftMovement = false;
		float lastXVelocity = 0.0;
		
		std::set <cocos2d::Node*> floors; //0x000020


		std::set <cocos2d::Node*> rightWalls; //0x000030 0x000031
		std::set <cocos2d::Node*> leftWalls; //0x000040 0x000041

		std::set <cocos2d::Node*> oilRightWalls; //0x000033 0x000034
		std::set <cocos2d::Node*> oilLeftWalls; //0x000043 0x000044

		std::set <cocos2d::Node*> edgeFloors; //0x000024
		std::set <cocos2d::Node*> edgeRightWalls; //0x000034
		std::set <cocos2d::Node*> edgeLeftWalls; //0x000044

        cocos2d::Size boxSize;

		bool nextJump = false;
		float nextJumpVelocity = 0.0;
		unsigned int jumpCounter = 0;

		void jumpCleaner(unsigned int jumpCounter);
	protected:
		bool onContactBegin(cocos2d::PhysicsContact &contact);
		bool onContactSeparate(cocos2d::PhysicsContact &contact);

		cocos2d::Node* searchForCorrespondenceFloor(std::set <cocos2d::Node*> edgeRightWalls, std::set <cocos2d::Node*> edgeFloors);
		cocos2d::Node* searchForCorrespondenceWall(std::set <cocos2d::Node*> edgeRightWalls, std::set <cocos2d::Node*> edgeFloors);
    };
}

#endif //NINJANOMEIYO_RYUNOSUKE_H
