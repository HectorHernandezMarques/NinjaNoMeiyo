//
// Created by AntonioMontana on 14/03/2017.
//

#include <unistd.h>
#include "./Ryunosuke.h"

#include <sstream>
#include <string>
#include <iostream>

std::string to_string(int num) {
	std::ostringstream ss;
	ss << num;
	return ss.str();
}

NinjaM::Ryunosuke::Ryunosuke()
{

}

NinjaM::Ryunosuke::Ryunosuke(cocos2d::Size visibleSize, cocos2d::Vec2 position, cocos2d::Vec2 anchorPoint, std::string texture, float rotation, cocos2d::Size boxSize) : Character(visibleSize, position, anchorPoint, texture, rotation)
{
    this->boxSize = boxSize;
	CCLOG("Ryunosuke builder");
}

NinjaM::Ryunosuke::~Ryunosuke()
{

}

void NinjaM::Ryunosuke::spawn(cocos2d::Layer *layer)
{
    NinjaM::Node::spawn(layer);
	auto material = cocos2d::PHYSICSBODY_MATERIAL_DEFAULT;
	material.density = 0.0f;
	material.restitution = 0.0f;
	material.friction = 0.0f;
	this->nodeBody = cocos2d::PhysicsBody::createBox(this->nodeSprite->getContentSize(), material);
	this->nodeBody->setDynamic(true);
	this->nodeBody->setCollisionBitmask(RYUNOSUKE_BITMASK);
	this->nodeBody->setContactTestBitmask(true);
	this->nodeBody->setRotationEnable(false);
    this->nodeSprite->setPhysicsBody(nodeBody);
	auto followTheSprite = cocos2d::Follow::create(this->nodeSprite, cocos2d::Rect::ZERO);
	layer->runAction(followTheSprite);
}

void NinjaM::Ryunosuke::toMoveAnimation(float velocity)
{
	this->mSetAnimation.lock();

	if (this->moveAnimationSense != velocity) {
		this->setAnimationSense(0.0);
		this->moveAnimationSense = velocity;
		if (this->animationAction != nullptr) { this->nodeSprite->stopAction(this->animationAction); }
		this->lastAnimation = velocity;

		this->animationAction = cocos2d::RepeatForever::create(cocos2d::Sequence::create(cocos2d::CallFunc::create(CC_CALLBACK_0(NinjaM::Ryunosuke::toMoveAnimationFunction, this, velocity)), cocos2d::DelayTime::create(RYUNOSUKE_MOVE_ANIMATION_DELAY), nullptr));
		this->lastAnimation = velocity;
		this->nodeSprite->runAction(this->animationAction);
	}

	this->mSetAnimation.unlock();
}

void NinjaM::Ryunosuke::toMoveAnimationFunction(float velocity)
{
	std::string nameAnimation;
	if (velocity > 0.0)
	{
		nameAnimation.append("RyunosukeMove");
		nameAnimation.append(to_string(this->numberAnimation++%RYUNOSUKE_MOVE_ANIMATION_NUMBER));
		nameAnimation.append("D.png");
	}
	else
	{
		nameAnimation.append("RyunosukeMove");
		nameAnimation.append(to_string(this->numberAnimation++%RYUNOSUKE_MOVE_ANIMATION_NUMBER));
		nameAnimation.append("I.png");
	}
	this->nodeSprite->setTexture(nameAnimation);
}

void NinjaM::Ryunosuke::toStopAnimation(float velocity)
{
	this->mSetAnimation.lock();

	velocity = velocity == 0.0 ? this->lastAnimation : velocity;

	if (this->stopAnimationSense != velocity) {
		this->setAnimationSense(0.0);
		this->stopAnimationSense = velocity;
		if (this->animationAction != nullptr) { this->nodeSprite->stopAction(this->animationAction); }
		this->lastAnimation = velocity;

		this->animationAction = cocos2d::RepeatForever::create(cocos2d::Sequence::create(cocos2d::CallFunc::create(CC_CALLBACK_0(NinjaM::Ryunosuke::toStopAnimationFunction, this, velocity)), cocos2d::DelayTime::create(RYUNOSUKE_STOP_ANIMATION_DELAY), nullptr));
		this->nodeSprite->runAction(this->animationAction);
	}

	this->mSetAnimation.unlock();
}

void NinjaM::Ryunosuke::toStopAnimationFunction(float velocity)
{
	std::string nameAnimation;
	if (velocity > 0.0)
	{
		nameAnimation.append("RyunosukeStop");
		nameAnimation.append(to_string(this->numberAnimation++%RYUNOSUKE_STOP_ANIMATION_NUMBER));
		nameAnimation.append("D.png");
	}
	else
	{
		nameAnimation.append("RyunosukeStop");
		nameAnimation.append(to_string(this->numberAnimation++%RYUNOSUKE_STOP_ANIMATION_NUMBER));
		nameAnimation.append("I.png");
	}
	this->nodeSprite->setTexture(nameAnimation);
}

void NinjaM::Ryunosuke::toJumpAnimation(float velocity)
{
	this->mSetAnimation.lock();

	if (this->jumpAnimationSense != velocity) {
		this->setAnimationSense(0.0);
		this->jumpAnimationSense = velocity;
		if (this->animationAction != nullptr) { this->nodeSprite->stopAction(this->animationAction); }
		this->lastAnimation = velocity;
		this->numberJumpAnimation = 0;

		this->animationAction = cocos2d::RepeatForever::create(cocos2d::Sequence::create(cocos2d::CallFunc::create(CC_CALLBACK_0(NinjaM::Ryunosuke::toJumpAnimationFunction, this, velocity)), cocos2d::DelayTime::create(RYUNOSUKE_JUMP_ANIMATION_DELAY), nullptr));
		this->nodeSprite->runAction(this->animationAction);
	}

	this->mSetAnimation.unlock();
}

void NinjaM::Ryunosuke::toJumpAnimationFunction(float velocity)
{
	if (this->numberJumpAnimation < RYUNOSUKE_JUMP_ANIMATION_NUMBER)
	{
		std::string nameAnimation;
		if (velocity > 0.0)
		{
			nameAnimation.append("RyunosukeJump");
			nameAnimation.append(to_string(this->numberJumpAnimation++%RYUNOSUKE_JUMP_ANIMATION_NUMBER));
			nameAnimation.append("D.png");
		}
		else
		{
			nameAnimation.append("RyunosukeJump");
			nameAnimation.append(to_string(this->numberJumpAnimation++%RYUNOSUKE_JUMP_ANIMATION_NUMBER));
			nameAnimation.append("I.png");
		}
		this->nodeSprite->setTexture(nameAnimation);
	}
}

void NinjaM::Ryunosuke::toJumpWallAnimation(float velocity, bool separate)
{
	this->mSetAnimation.lock();

	if (this->jumpAnimationSense != velocity) {
		this->setAnimationSense(0.0);
		this->jumpAnimationSense = velocity;
		if (this->animationAction != nullptr) { this->nodeSprite->stopAction(this->animationAction); }
		this->lastAnimation = velocity;
		this->numberJumpWallAnimation = 0;

		this->animationAction = cocos2d::RepeatForever::create(cocos2d::Sequence::create(cocos2d::CallFunc::create(CC_CALLBACK_0(NinjaM::Ryunosuke::toJumpWallAnimationFunction, this, velocity, separate)), cocos2d::DelayTime::create(RYUNOSUKE_JUMP_WALL_ANIMATION_DELAY), nullptr));
		this->nodeSprite->runAction(this->animationAction);
	}

	this->mSetAnimation.unlock();
}

void NinjaM::Ryunosuke::toJumpWallAnimationFunction(float velocity, bool separate)
{
	if (this->numberJumpWallAnimation < RYUNOSUKE_JUMP_WALL_ANIMATION_NUMBER)
	{
		std::string nameAnimation;
		if (velocity > 0.0)
		{
			if (separate) {
				nameAnimation.append("RyunosukeJumpWallSeparate");
				nameAnimation.append(to_string(this->numberJumpWallAnimation++%RYUNOSUKE_JUMP_WALL_ANIMATION_NUMBER));
				nameAnimation.append("D.png");
			}
			else
			{
				nameAnimation.append("RyunosukeJumpWall");
				nameAnimation.append(to_string(this->numberJumpWallAnimation++%RYUNOSUKE_JUMP_WALL_ANIMATION_NUMBER));
				nameAnimation.append("D.png");
			}
		}
		else
		{
			if (separate) {
				nameAnimation.append("RyunosukeJumpWallSeparate");
				nameAnimation.append(to_string(this->numberJumpWallAnimation++%RYUNOSUKE_JUMP_WALL_ANIMATION_NUMBER));
				nameAnimation.append("I.png");
			}
			else
			{
				nameAnimation.append("RyunosukeJumpWall");
				nameAnimation.append(to_string(this->numberJumpWallAnimation++%RYUNOSUKE_JUMP_WALL_ANIMATION_NUMBER));
				nameAnimation.append("I.png");
			}
		}
		this->nodeSprite->setTexture(nameAnimation);
	}
}


void NinjaM::Ryunosuke::toFallAnimation()
{
	this->mSetAnimation.lock();

	this->setAnimationSense(0.0);
	if (this->animationAction != nullptr) { this->nodeSprite->stopAction(this->animationAction); }
	this->numberFallAnimation = 0;

	this->animationAction = cocos2d::RepeatForever::create(cocos2d::Sequence::create(cocos2d::CallFunc::create(CC_CALLBACK_0(NinjaM::Ryunosuke::toFallAnimationFunction, this)), cocos2d::DelayTime::create(RYUNOSUKE_FALL_ANIMATION_DELAY), nullptr));
	this->nodeSprite->runAction(this->animationAction);

	this->mSetAnimation.unlock();
}

void NinjaM::Ryunosuke::toFallAnimationFunction()
{
	std::string nameAnimation;
	if (this->lastAnimation > 0.0)
	{
		if (this->numberFallAnimation < (RYUNOSUKE_FALL_ANIMATION_NUMBER))
		{
			nameAnimation.append("RyunosukeFall");
			nameAnimation.append(to_string(this->numberAnimation++%RYUNOSUKE_FALL_ANIMATION_NUMBER));
			nameAnimation.append("D.png");
		}
		else
		{
			nameAnimation.append("RyunosukeFall");
			nameAnimation.append(to_string((RYUNOSUKE_FALL_ANIMATION_NUMBER - RYUNOSUKE_FALL_ANIMATION_NUMBER_SECOND - 1) + this->numberAnimation++%RYUNOSUKE_FALL_ANIMATION_NUMBER_SECOND));
			nameAnimation.append("D.png");
		}
	}
	else
	{
		if (this->numberFallAnimation < (RYUNOSUKE_FALL_ANIMATION_NUMBER - RYUNOSUKE_FALL_ANIMATION_NUMBER_SECOND))
		{
			nameAnimation.append("RyunosukeFall");
			nameAnimation.append(to_string(this->numberAnimation++%RYUNOSUKE_FALL_ANIMATION_NUMBER));
			nameAnimation.append("I.png");
		}
		else
		{
			nameAnimation.append("RyunosukeFall");
			nameAnimation.append(to_string((RYUNOSUKE_FALL_ANIMATION_NUMBER - RYUNOSUKE_FALL_ANIMATION_NUMBER_SECOND - 1) + this->numberAnimation++%RYUNOSUKE_FALL_ANIMATION_NUMBER_SECOND));
			nameAnimation.append("I.png");
		}
	}
	this->nodeSprite->setTexture(nameAnimation);
}

void NinjaM::Ryunosuke::toClimbAnimation(float velocity)
{
	this->mSetAnimation.lock();

	if (this->climbAnimationSense != velocity) {
		this->setAnimationSense(0.0);
		this->climbAnimationSense = velocity;
		if (this->animationAction != nullptr) { this->nodeSprite->stopAction(this->animationAction); }
		this->lastAnimation = velocity;

		this->animationAction = cocos2d::RepeatForever::create(cocos2d::Sequence::create(cocos2d::CallFunc::create(CC_CALLBACK_0(NinjaM::Ryunosuke::toClimbAnimationFunction, this, velocity)), cocos2d::DelayTime::create(RYUNOSUKE_CLIMB_ANIMATION_DELAY), nullptr));
		this->nodeSprite->runAction(this->animationAction);
	}

	this->mSetAnimation.unlock();
}

void NinjaM::Ryunosuke::toClimbAnimationFunction(float velocity)
{
	std::string nameAnimation;
	if (velocity > 0.0)
	{
		nameAnimation.append("RyunosukeClimb");
		nameAnimation.append(to_string(this->numberAnimation++%RYUNOSUKE_CLIMB_ANIMATION_NUMBER));
		nameAnimation.append("D.png");
	}
	else
	{
		nameAnimation.append("RyunosukeClimb");
		nameAnimation.append(to_string(this->numberAnimation++%RYUNOSUKE_CLIMB_ANIMATION_NUMBER));
		nameAnimation.append("I.png");
	}
	this->nodeSprite->setTexture(nameAnimation);
}

void NinjaM::Ryunosuke::setAnimationSense(float animationSense)
{
	this->moveAnimationSense = animationSense;
	this->stopAnimationSense = animationSense;
	this->jumpAnimationSense = animationSense;
	this->climbAnimationSense = animationSense;
}

void NinjaM::Ryunosuke::toMove(float velocity, bool waitWallDetection)
{
	this->mContiniousMovement.lock();
	if (this->movementAction != nullptr) { this->nodeSprite->stopAction(this->movementAction); }

	if (velocity > 0.0)
	{
		this->rightMovement = true;
	}
	else
	{
		this->leftMovement = true;
	}
	this->movementAction = cocos2d::RepeatForever::create(cocos2d::Sequence::create(cocos2d::CallFunc::create(CC_CALLBACK_0(NinjaM::Ryunosuke::toMoveSingle, this , velocity, waitWallDetection)), nullptr));
	this->nodeSprite->runAction(this->movementAction);

	this->mContiniousMovement.unlock();
}

void NinjaM::Ryunosuke::toMoveSingle(float velocity, bool waitWallDetection)
{
	CCLOG("(toMove)");
	if (waitWallDetection)
	{
		this->mWallDetection.lock();
	}
	this->mSingleMovement.lock();
	if (velocity>0.0)
	{
		mJumpTrigger.lock();
		if (this->rightWalls.empty() && this->edgeRightWalls.empty() && this->oilRightWalls.empty())
	    {
		    mJumpTrigger.unlock();
		    this->nodeBody->setVelocityLimit(cocos2d::PHYSICS_INFINITY);
	        this->lastXVelocity = fabs(velocity);
	        this->nodeBody->setVelocity(cocos2d::Vec2(velocity, this->nodeBody->getVelocity().y));
			this->toMoveAnimation(velocity);
			CCLOG("(toMove) Right Move -- Not in wall, hence, in either floor or air.");
	    }
	    else if (this->floors.empty() && this->edgeFloors.empty())
	    {
			if (!this->rightWalls.empty() || !this->edgeRightWalls.empty())
			{
				mJumpTrigger.unlock();
				//Holding wall position
				this->lastXVelocity = fabs(velocity);
				this->nodeBody->setVelocityLimit(RYUNOSUKE_WALL_SPEED);
				this->nodeBody->setVelocity(cocos2d::Vec2(0.0, this->nodeBody->getVelocity().y));
				this->toClimbAnimation(velocity);
				CCLOG("(toMove) Right Move -- In wall but not in Floor");
			}
			else
			{
				mJumpTrigger.unlock();
				//Holding wall position
				this->lastXVelocity = fabs(velocity);
				this->nodeBody->setVelocity(cocos2d::Vec2(0.0, this->nodeBody->getVelocity().y));
				this->toClimbAnimation(velocity);
				CCLOG("(toMove) Right Move -- In oil wall but not in Floor");
			}
	    }
		else if (!this->edgeRightWalls.empty() && !this->edgeFloors.empty())
		{
		    mJumpTrigger.unlock();
			cocos2d::Node* corner = this->searchForCorrespondenceFloor(this->edgeRightWalls, this->edgeFloors);
			if (corner != nullptr)
			{
				//    |x|
				//    |x|
				//    |\| | |
				//    | |\| |
				//    | | | |
				if (fabs((this->nodeSprite->getPosition().x + this->nodeSprite->getContentSize().width) - (corner->getPosition().x + this->boxSize.width/2)) < fabs(this->nodeSprite->getPosition().y - (corner->getPosition().y - this->boxSize.height)))
				{
					if (this->rightWalls.empty())
					{
						this->nodeBody->setVelocityLimit(cocos2d::PHYSICS_INFINITY);
						this->lastXVelocity = fabs(velocity);
						this->nodeBody->setVelocity(cocos2d::Vec2(velocity, this->nodeBody->getVelocity().y));
						this->toMoveAnimation(velocity);
						CCLOG("(toMove) Right Move -- In the Edge corner OVER the floor.");
					}
					else
					{
						//Holding wall position
						this->lastXVelocity = fabs(velocity);
						this->nodeBody->setVelocityLimit(cocos2d::PHYSICS_INFINITY);
						this->nodeBody->setVelocity(cocos2d::Vec2(0.0, this->nodeBody->getVelocity().y));

						this->mContiniousMovement.lock();

						this->nodeSprite->stopAction(this->movementAction);
						this->toStopAnimation(velocity);

						this->mContiniousMovement.unlock();

						CCLOG("(toMove) Right Move -- In the Edge corner OVER the floor. Near the Right Wall though");
					}
				}
				else
				{
					//Holding wall position
					this->lastXVelocity = fabs(velocity);
					this->nodeBody->setVelocityLimit(RYUNOSUKE_WALL_SPEED);
					this->nodeBody->setVelocity(cocos2d::Vec2(0.0, this->nodeBody->getVelocity().y));
					this->toClimbAnimation(velocity);
					CCLOG("(toMove) Right Move -- In the Edge corner UNDER the floor.");
				}
			}
			else
			{
				this->lastXVelocity = fabs(velocity);
				this->nodeBody->setVelocityLimit(cocos2d::PHYSICS_INFINITY);
				this->nodeBody->setVelocity(cocos2d::Vec2(0.0, this->nodeBody->getVelocity().y));

				this->mContiniousMovement.lock();

				this->nodeSprite->stopAction(this->movementAction);
				this->toStopAnimation(velocity);

				this->mContiniousMovement.unlock();

				CCLOG("(toMove) Right Move -- In the Edge corner OVER the floor. Internal Corner though");

			}
		}
		else
		{
			mJumpTrigger.unlock();
		}
		//this->nodeSprite->setTexture("Ryunosuke1D.png");
	}
	else
	{
		mJumpTrigger.lock();
		if (this->leftWalls.empty() && this->edgeLeftWalls.empty() && this->oilLeftWalls.empty())
		{
		    mJumpTrigger.unlock();
		    this->nodeBody->setVelocityLimit(cocos2d::PHYSICS_INFINITY);
	        this->lastXVelocity = fabs(velocity);
	        this->nodeBody->setVelocity(cocos2d::Vec2(velocity, this->nodeBody->getVelocity().y));
			this->toMoveAnimation(velocity);
			CCLOG("(toMove) Left Move -- Not in wall, hence, in either floor or air.");
	    }
		else if (this->floors.empty() && this->edgeFloors.empty())
		{
			if (!this->leftWalls.empty() || !this->edgeLeftWalls.empty())
			{
				mJumpTrigger.unlock();
				//Holding wall position
				this->lastXVelocity = fabs(velocity);
				this->nodeBody->setVelocityLimit(RYUNOSUKE_WALL_SPEED);
				this->nodeBody->setVelocity(cocos2d::Vec2(0.0, this->nodeBody->getVelocity().y));
				this->toClimbAnimation(velocity);
				CCLOG("(toMove) Left Move -- In wall but not in Floor");
			}
			else
			{
				mJumpTrigger.unlock();
				//Holding wall position
				this->lastXVelocity = fabs(velocity);
				this->nodeBody->setVelocity(cocos2d::Vec2(0.0, this->nodeBody->getVelocity().y));
				this->toClimbAnimation(velocity);
				CCLOG("(toMove) Left Move -- In oil wall but not in Floor");
			}
	    }
		else if (!this->edgeLeftWalls.empty() && !this->edgeFloors.empty())
		{
		    mJumpTrigger.unlock();
			cocos2d::Node* corner = this->searchForCorrespondenceFloor(this->edgeLeftWalls, this->edgeFloors);
			if (corner != nullptr)
			{
				//     |x|
				//     |x|
				// | | |/|
				// | |/| |
				// | | | |
				if (fabs(this->nodeSprite->getPosition().x - (corner->getPosition().x - this->boxSize.width / 2)) < fabs(this->nodeSprite->getPosition().y - (corner->getPosition().y - this->boxSize.height)))
				{
					if (this->leftWalls.empty())
					{
						this->nodeBody->setVelocityLimit(cocos2d::PHYSICS_INFINITY);
						this->lastXVelocity = fabs(velocity);
						this->nodeBody->setVelocity(cocos2d::Vec2(velocity, this->nodeBody->getVelocity().y));
						this->toMoveAnimation(velocity);
						CCLOG("(toMove) Left Move -- In the Edge corner OVER the floor.");
					}
					else
					{
						this->lastXVelocity = fabs(velocity);
						this->nodeBody->setVelocityLimit(cocos2d::PHYSICS_INFINITY);
						this->nodeBody->setVelocity(cocos2d::Vec2(0.0, this->nodeBody->getVelocity().y));

						this->mContiniousMovement.lock();

						this->nodeSprite->stopAction(this->movementAction);
						this->toStopAnimation(velocity);

						this->mContiniousMovement.unlock();

						CCLOG("(toMove) Left Move -- In the Edge corner OVER the floor. Near the Left Wall though");
					}
				}
				else
				{
					//Holding wall position
					this->lastXVelocity = fabs(velocity);
					this->nodeBody->setVelocityLimit(RYUNOSUKE_WALL_SPEED);
					this->nodeBody->setVelocity(cocos2d::Vec2(0.0, this->nodeBody->getVelocity().y));
					this->toClimbAnimation(velocity);
					CCLOG("(toMove) Left Move -- In the Edge corner UNDER the floor.");
				}
			}
			else
			{
				this->lastXVelocity = fabs(velocity);
				this->nodeBody->setVelocityLimit(cocos2d::PHYSICS_INFINITY);
				this->nodeBody->setVelocity(cocos2d::Vec2(0.0, this->nodeBody->getVelocity().y));

				this->mContiniousMovement.lock();

				this->nodeSprite->stopAction(this->movementAction);
				this->toStopAnimation(velocity);

				this->mContiniousMovement.unlock();

				CCLOG("(toMove) Left Move -- In the Edge corner OVER the floor. Internal Corner though");
			}
		}
		else
		{
			mJumpTrigger.unlock();
		}
		//this->nodeSprite->setTexture("Ryunosuke1I.png");
	}

	this->mSingleMovement.unlock();
	if (waitWallDetection)
	{
		this->mWallDetection.unlock();
	}
}

void NinjaM::Ryunosuke::toStop(float velocity)
{
	CCLOG("(toStop)");
	this->mWallDetection.lock();
    this->nodeBody->setVelocityLimit(cocos2d::PHYSICS_INFINITY);
	if (velocity>0.0)
	{
		this->mContiniousMovement.lock();
		this->nodeSprite->stopAction(this->movementAction);
		this->rightMovement = false;

		if (!this->leftMovement)
		{

		    mJumpTrigger.lock();
			if (!this->floors.empty() || !this->edgeFloors.empty())
			{
		        mJumpTrigger.unlock();
				if (this->nodeBody->getVelocity().y < RYUNOSUKE_JUMP_ON_FLOOR/2)
				{
					this->toStopAnimation(velocity);
					this->mContiniousMovement.unlock();

					this->nodeBody->setVelocity(cocos2d::Vec2(0.0, this->nodeBody->getVelocity().y));
					this->toStopAnimation(velocity);
				}
				CCLOG("(toStop) From Right -- On the floor");
			}
			else
			{
				//TODO NOANIM
				//this->setAnimationSense(0.0);
				this->mContiniousMovement.unlock();

		        mJumpTrigger.unlock();
				CCLOG("(toStop) From Right -- On the air");
			}
		}
		else
		{
			this->mContiniousMovement.unlock();
		    this->toMove(-this->lastXVelocity, false);
			CCLOG("(toStop) From Right -- BackMovement");
		}
	}
	else
	{
		this->mContiniousMovement.lock();
		this->nodeSprite->stopAction(this->movementAction);
		this->leftMovement = false;

		if (!this->rightMovement)
		{
		    mJumpTrigger.lock();
			if (!this->floors.empty() || !this->edgeFloors.empty())
			{
		        mJumpTrigger.unlock();
				if (this->nodeBody->getVelocity().y < RYUNOSUKE_JUMP_ON_FLOOR/2)
				{
					this->toStopAnimation(velocity);
					this->mContiniousMovement.unlock();

					this->nodeBody->setVelocity(cocos2d::Vec2(0.0, this->nodeBody->getVelocity().y));
					this->toStopAnimation(velocity);
				}
				CCLOG("(toStop) From Left -- On the floor");
			}
			else
			{
				//TODO NOANIM
				//this->setAnimationSense(0.0);
				this->mContiniousMovement.unlock();

		        mJumpTrigger.unlock();
				CCLOG("(toStop) From Left -- On the air");
			}
		}
		else
		{
			this->mContiniousMovement.unlock();

		    this->toMove(this->lastXVelocity, false);
			CCLOG("(toStop) From Left -- BackMovement");
		}
	}
	this->mWallDetection.unlock();
}

void NinjaM::Ryunosuke::toJump(float velocity, bool waitWallDetection)
{
	CCLOG("(toJump)");
	if (waitWallDetection)
	{
		this->mWallDetection.lock();
	}
	if (!this->floors.empty() || !this->edgeFloors.empty())
	{
		mJumpTrigger.unlock();
		//toStop() needs to know if ryunosuke is in the air in order to either stop or let him go

		if (!this->rightWalls.empty() || !this->edgeRightWalls.empty() || !this->oilRightWalls.empty())
		{
			if (!this->edgeRightWalls.empty())
			{
				cocos2d::Node* corner = this->searchForCorrespondenceWall(this->edgeRightWalls, this->edgeFloors);
				mJumpTrigger.lock();
				this->floors.clear();
				this->edgeFloors.clear();
				mJumpTrigger.unlock();
				if (corner != nullptr)
				{
					//Check if ryunosuke is over the floor detected.
					bool ryunosukeOverRightEdgeFloor = false;
					if (fabs((this->nodeSprite->getPosition().x + this->nodeSprite->getContentSize().width) - (corner->getPosition().x + this->boxSize.width)) < fabs(this->nodeSprite->getPosition().y - (corner->getPosition().y - this->boxSize.height / 2)))
					{
						ryunosukeOverRightEdgeFloor = true;
					}

					if (!ryunosukeOverRightEdgeFloor)
					{
						this->nodeBody->setVelocityLimit(cocos2d::PHYSICS_INFINITY);
						if (velocity >= 0.0)
						{
							getNodeSprite()->getPhysicsBody()->setVelocity(cocos2d::Vec2(0.0, RYUNOSUKE_JUMP_ON_WALL));
							this->toJumpWallAnimation(velocity, false);
							CCLOG("(toJump) - Right Jump - In the Right Edge corner UNDER the floor.");
						}
						else if (velocity < 0.0)
						{
							getNodeSprite()->getPhysicsBody()->setVelocity(cocos2d::Vec2(velocity, RYUNOSUKE_JUMP_ON_WALL));
							this->toJumpWallAnimation(velocity, true);
							CCLOG("(toJump) - Leftt Jump - In the Right Edge corner UNDER the floor.");
						}
					}
					else
					{
						this->nodeBody->setVelocityLimit(cocos2d::PHYSICS_INFINITY);
						if (velocity > 0.0)
						{
							getNodeSprite()->getPhysicsBody()->setVelocity(cocos2d::Vec2(velocity, RYUNOSUKE_JUMP_ON_FLOOR));
							this->toJumpAnimation(velocity);
							CCLOG("(toJump) - Right Jump - In the Right Edge corner OVER the floor.");
						}
						else if (velocity < 0.0)
						{
							getNodeSprite()->getPhysicsBody()->setVelocity(cocos2d::Vec2(velocity, RYUNOSUKE_JUMP_ON_FLOOR));
							this->toJumpAnimation(velocity);
							CCLOG("(toJump) - Left Jump - In the Right Edge corner OVER the floor.");
						}
						else
						{
							getNodeSprite()->getPhysicsBody()->setVelocity(cocos2d::Vec2(velocity, RYUNOSUKE_JUMP_ON_FLOOR));
							this->toJumpAnimation(velocity);
							CCLOG("(toJump) - Center Jump - In the Right Edge corner OVER the floor.");
						}
					}
				}
				else
				{
					this->nodeBody->setVelocityLimit(cocos2d::PHYSICS_INFINITY);
					if (velocity >= 0.0)
					{
						getNodeSprite()->getPhysicsBody()->setVelocity(cocos2d::Vec2(0.0, RYUNOSUKE_JUMP_ON_WALL));
						this->toJumpWallAnimation(velocity, false);
						CCLOG("(toJump) - Right Jump - In the Edge Right Wall UNDER the floor.");
					}
					else if (velocity < 0.0)
					{
						getNodeSprite()->getPhysicsBody()->setVelocity(cocos2d::Vec2(velocity, RYUNOSUKE_JUMP_ON_WALL));
						this->toJumpWallAnimation(velocity, true);
						CCLOG("(toJump) - Left Jump - In the Edge Right Wall UNDER the floor.");
					}
				}
			}
			else
			{
				mJumpTrigger.lock();
				this->floors.clear();
				this->edgeFloors.clear();
				mJumpTrigger.unlock();
				this->nodeBody->setVelocityLimit(cocos2d::PHYSICS_INFINITY);
				if (velocity >= 0.0)
				{
					getNodeSprite()->getPhysicsBody()->setVelocity(cocos2d::Vec2(0.0, RYUNOSUKE_JUMP_ON_WALL));
					this->toJumpWallAnimation(velocity, false);
					CCLOG("(toJump) - Right Jump - In the Right Wall");
				}
				else if (velocity < 0.0)
				{
					getNodeSprite()->getPhysicsBody()->setVelocity(cocos2d::Vec2(velocity, RYUNOSUKE_JUMP_ON_WALL));
					this->toJumpWallAnimation(velocity, true);
					CCLOG("(toJump) - Left Jump - In the Right Wall");
				}
			}
		}
		else if (!this->leftWalls.empty() || !this->edgeLeftWalls.empty() || !this->oilLeftWalls.empty())
		{
			if (!this->edgeLeftWalls.empty())
			{
				cocos2d::Node* corner = this->searchForCorrespondenceWall(this->edgeLeftWalls, this->edgeFloors);
				mJumpTrigger.lock();
				this->floors.clear();
				this->edgeFloors.clear();
				mJumpTrigger.unlock();
				if (corner != nullptr)
				{
					//Check if ryunosuke is over the floor detected.
					bool ryunosukeOverLeftEdgeFloor = false;
					if (fabs(this->nodeSprite->getPosition().x - (corner->getPosition().x - this->boxSize.width)) < fabs(this->nodeSprite->getPosition().y - (corner->getPosition().y - this->boxSize.height / 2)))
					{
						ryunosukeOverLeftEdgeFloor = true;
					}

					if (!ryunosukeOverLeftEdgeFloor)
					{
						this->nodeBody->setVelocityLimit(cocos2d::PHYSICS_INFINITY);
						if (velocity > 0.0)
						{
							getNodeSprite()->getPhysicsBody()->setVelocity(cocos2d::Vec2(velocity, RYUNOSUKE_JUMP_ON_WALL));
							this->toJumpWallAnimation(velocity, true);
							CCLOG("(toJump) - Right Jump - In the Left Edge corner UNDER the floor.");
						}
						else if (velocity <= 0.0)
						{
							getNodeSprite()->getPhysicsBody()->setVelocity(cocos2d::Vec2(0.0, RYUNOSUKE_JUMP_ON_WALL));
							this->toJumpWallAnimation(velocity, false);
							CCLOG("(toJump) - Leftt Jump - In the Left Edge corner UNDER the floor.");
						}
					}
					else
					{
						this->nodeBody->setVelocityLimit(cocos2d::PHYSICS_INFINITY);
						if (velocity > 0.0)
						{
							getNodeSprite()->getPhysicsBody()->setVelocity(cocos2d::Vec2(velocity, RYUNOSUKE_JUMP_ON_FLOOR));
							this->toJumpAnimation(velocity);
							CCLOG("(toJump) - Right Jump - In the Left Edge corner OVER the floor.");
						}
						else if (velocity < 0.0)
						{
							getNodeSprite()->getPhysicsBody()->setVelocity(cocos2d::Vec2(velocity, RYUNOSUKE_JUMP_ON_FLOOR));
							this->toJumpAnimation(velocity);
							CCLOG("(toJump) - Left Jump - In the Left Edge corner OVER the floor.");
						}
						else
						{
							getNodeSprite()->getPhysicsBody()->setVelocity(cocos2d::Vec2(velocity, RYUNOSUKE_JUMP_ON_FLOOR));
							this->toJumpAnimation(velocity);
							CCLOG("(toJump) - Center Jump - In the Left Edge corner OVER the floor.");
						}
					}
				}
				else
				{
					this->nodeBody->setVelocityLimit(cocos2d::PHYSICS_INFINITY);
					if (velocity > 0.0)
					{
						getNodeSprite()->getPhysicsBody()->setVelocity(cocos2d::Vec2(velocity, RYUNOSUKE_JUMP_ON_WALL));
						this->toJumpWallAnimation(velocity, true);
						CCLOG("(toJump) - Right Jump - In the Edge Left Wall UNDER the floor.");
					}
					else if (velocity <= 0.0)
					{
						getNodeSprite()->getPhysicsBody()->setVelocity(cocos2d::Vec2(0.0, RYUNOSUKE_JUMP_ON_WALL));
						this->toJumpWallAnimation(velocity, false);
						CCLOG("(toJump) - Left Jump - In the Edge Left Wall UNDER the floor.");
					}
				}

			}
			else
			{
				mJumpTrigger.lock();
				this->floors.clear();
				this->edgeFloors.clear();
				mJumpTrigger.unlock();
				this->nodeBody->setVelocityLimit(cocos2d::PHYSICS_INFINITY);
				if (velocity > 0.0)
				{
					getNodeSprite()->getPhysicsBody()->setVelocity(cocos2d::Vec2(velocity, RYUNOSUKE_JUMP_ON_WALL));
					this->toJumpWallAnimation(velocity, true);
					CCLOG("(toJump) - Right Jump - In the Left Wall");
				}
				else if (velocity <= 0.0)
				{
					getNodeSprite()->getPhysicsBody()->setVelocity(cocos2d::Vec2(0.0, RYUNOSUKE_JUMP_ON_WALL));
					this->toJumpWallAnimation(velocity, false);
					CCLOG("(toJump) - Left Jump - In the Left Wall");
				}
			}
		}
		else
		{
			mJumpTrigger.lock();
			this->floors.clear();
			this->edgeFloors.clear();
			mJumpTrigger.unlock();
			this->nodeBody->setVelocityLimit(cocos2d::PHYSICS_INFINITY);
			getNodeSprite()->getPhysicsBody()->setVelocity(cocos2d::Vec2(velocity, RYUNOSUKE_JUMP_ON_FLOOR));
			this->toJumpAnimation(velocity);
			CCLOG("(toJump) On the floor");
		}
	}
	else if (!this->rightWalls.empty() || !this->edgeRightWalls.empty() || !this->oilRightWalls.empty())
	{
		mJumpTrigger.unlock();
		this->nodeBody->setVelocityLimit(cocos2d::PHYSICS_INFINITY);
		if (velocity >= 0.0)
		{
			getNodeSprite()->getPhysicsBody()->setVelocity(cocos2d::Vec2(0.0, RYUNOSUKE_JUMP_ON_WALL));
			this->toJumpWallAnimation(velocity, false);
		}
		else if (velocity < 0.0)
		{
			getNodeSprite()->getPhysicsBody()->setVelocity(cocos2d::Vec2(velocity, RYUNOSUKE_JUMP_ON_WALL));
			this->toJumpWallAnimation(velocity, true);
		}
		CCLOG("(toJump) On the right wall");
	}
	else if (!this->leftWalls.empty() || !this->edgeLeftWalls.empty() || !this->oilLeftWalls.empty())
	{
		mJumpTrigger.unlock();
		this->nodeBody->setVelocityLimit(cocos2d::PHYSICS_INFINITY);
		if (velocity > 0.0)
		{
			getNodeSprite()->getPhysicsBody()->setVelocity(cocos2d::Vec2(velocity, RYUNOSUKE_JUMP_ON_WALL));
			this->toJumpWallAnimation(velocity, true);
		}
		else if (velocity <= 0.0)
		{
			getNodeSprite()->getPhysicsBody()->setVelocity(cocos2d::Vec2(0.0, RYUNOSUKE_JUMP_ON_WALL));
			this->toJumpWallAnimation(velocity, false);
		}
		CCLOG("(toJump) On the left wall");
	}
	else
	{
		mJumpTrigger.unlock();

		this->mNextJump.lock();
		this->nextJumpVelocity = velocity;
		this->nextJump = true;
		cocos2d::DelayTime *delayAction = cocos2d::DelayTime::create(RYUNOSUKE_JUMP_TIME_REMEMBER);
		cocos2d::CallFunc *jumpCleanerAction = cocos2d::CallFunc::create(CC_CALLBACK_0(NinjaM::Ryunosuke::jumpCleaner, this, ++this->jumpCounter));
		this->nodeSprite->runAction(cocos2d::Sequence::create(delayAction, jumpCleanerAction, nullptr));
		this->mNextJump.unlock();

		CCLOG("(toJump) On the air");
	}
	if (waitWallDetection)
	{
		this->mWallDetection.unlock();
	}
}

void NinjaM::Ryunosuke::jumpCleaner(unsigned int jumpCounter)
{

	this->mNextJump.lock();
	if (jumpCounter == this->jumpCounter)
	{
	    this->nextJump = false;
	}
	this->mNextJump.unlock();
}

void NinjaM::Ryunosuke::setEventDispatcher()
{
	auto contactListener = cocos2d::EventListenerPhysicsContact::create();
	contactListener->onContactBegin = CC_CALLBACK_1(NinjaM::Ryunosuke::onContactBegin, this);
	contactListener->onContactSeparate = CC_CALLBACK_1(NinjaM::Ryunosuke::onContactSeparate, this);
	this->nodeSprite->getEventDispatcher()->addEventListenerWithSceneGraphPriority(contactListener, this->nodeSprite);
}

bool NinjaM::Ryunosuke::onContactBegin(cocos2d::PhysicsContact &contact)
{
	CCLOG("(onContactBegin)");
	cocos2d::PhysicsBody *a = contact.getShapeA()->getBody();
	cocos2d::PhysicsBody *b = contact.getShapeB()->getBody();

	if ((a->getCollisionBitmask() != RYUNOSUKE_BITMASK && b->getCollisionBitmask() != RYUNOSUKE_BITMASK))
	{
		return false;
	}
	if ((a->getCollisionBitmask() == RYUNOSUKE_BITMASK && b->getCollisionBitmask() == FIXED_OBSTACLE_BITMASK) || (a->getCollisionBitmask() == FIXED_OBSTACLE_BITMASK && b->getCollisionBitmask() == RYUNOSUKE_BITMASK))
	{
		return true;
	}
	else if ((a->getCollisionBitmask() == RYUNOSUKE_BITMASK && b->getCollisionBitmask() == FLOOR_BITMASK) || (a->getCollisionBitmask() == FLOOR_BITMASK && b->getCollisionBitmask() == RYUNOSUKE_BITMASK))
	{
		this->mWallDetection.lock();
		CCLOG("(ContactBegion) - Floor");
		if (a->getCollisionBitmask() == RYUNOSUKE_BITMASK)
		{
			this->floors.insert(b->getLinkedNode());
		}
		else
		{
			this->floors.insert(a->getLinkedNode());
		}
		this->nodeBody->setVelocityLimit(cocos2d::PHYSICS_INFINITY);
        if (!this->rightMovement && !this->leftMovement)
        {
			if (this->nodeBody->getVelocity().y < RYUNOSUKE_JUMP_ON_FLOOR/2)
			{
				this->mContiniousMovement.lock();

				//this->nodeSprite->stopAction(this->movementAction);
				this->toStopAnimation(0.0);

				this->mContiniousMovement.unlock();

				this->nodeBody->setVelocity(cocos2d::Vec2(0.0, 0.0));

				this->mNextJump.lock();
				if (this->nextJump)
				{
					this->toJump(nextJumpVelocity, false);
					this->nextJump = false;
				}
				this->mNextJump.unlock();

			}
        }/*
		else if (this->rightMovement)
		{
			this->toMove(RYUNOSUKE_SPEED, false);

			this->mNextJump.lock();
			this->nextJump = false;
			this->mNextJump.unlock();

		}
		else if (this->leftMovement)
		{
			this->toMove(-RYUNOSUKE_SPEED, false);

			this->mNextJump.lock();
			this->nextJump = false;
			this->mNextJump.unlock();

		}*/
		else
		{
			this->mNextJump.lock();
			this->nextJump = false;
			this->mNextJump.unlock();
		}
		this->mWallDetection.unlock();
	}
	else if ((a->getCollisionBitmask() == RYUNOSUKE_BITMASK && b->getCollisionBitmask() == RIGHT_OBSTACLE_BITMASK) || (a->getCollisionBitmask() == RIGHT_OBSTACLE_BITMASK && b->getCollisionBitmask() == RYUNOSUKE_BITMASK))
	{
		this->mWallDetection.lock();
		if (a->getCollisionBitmask() == RYUNOSUKE_BITMASK)
		{
			this->rightWalls.insert(b->getLinkedNode());
		}
		else
		{
			this->rightWalls.insert(a->getLinkedNode());
		}
		if (this->floors.empty() && this->edgeFloors.empty())
		{
			if (!this->rightMovement && !this->leftMovement)
			{
				this->mContiniousMovement.lock();

				this->nodeSprite->stopAction(this->movementAction);
				this->toClimbAnimation(RYUNOSUKE_SPEED);

				this->mContiniousMovement.unlock();

				this->nodeBody->setVelocity(cocos2d::Vec2(0.0, this->nodeBody->getVelocity().y));

				this->mNextJump.lock();
				if (this->nextJump)
				{
					this->toJump(nextJumpVelocity, false);
					this->nextJump = false;
				}
				this->mNextJump.unlock();

			}/*
			else if (this->rightMovement)
			{
				this->toClimbAnimation(RYUNOSUKE_SPEED);
				this->nodeBody->setVelocityLimit(RYUNOSUKE_WALL_SPEED);
				this->nodeBody->setVelocity(cocos2d::Vec2(0.0, this->nodeBody->getVelocity().y));

				this->mNextJump.lock();
				this->nextJump = false;
				this->mNextJump.unlock();

			}
			else if (this->leftMovement)
			{
				this->toClimbAnimation(RYUNOSUKE_SPEED);
				this->nodeBody->setVelocityLimit(RYUNOSUKE_WALL_SPEED);
				this->nodeBody->setVelocity(cocos2d::Vec2(0.0, this->nodeBody->getVelocity().y));

				this->mNextJump.lock();
				this->nextJump = false;
				this->mNextJump.unlock();

			}
			else
			{
				this->toClimbAnimation(RYUNOSUKE_SPEED);
				this->nodeBody->setVelocityLimit(RYUNOSUKE_WALL_SPEED);
				this->nodeBody->setVelocity(cocos2d::Vec2(0.0, this->nodeBody->getVelocity().y));

				this->mNextJump.lock();
				this->nextJump = false;
				this->mNextJump.unlock();

			}*/
			else
			{
				this->nodeBody->setVelocityLimit(RYUNOSUKE_WALL_SPEED);
				this->nodeBody->setVelocity(cocos2d::Vec2(0.0, this->nodeBody->getVelocity().y));

				this->mNextJump.lock();
				this->nextJump = false;
				this->mNextJump.unlock();
			}
			CCLOG("(ContactBegion) - Right Wall - Not on the floor");
		}
		else
		{
			if (!this->rightMovement && !this->leftMovement)
			{
				this->nodeBody->setVelocity(cocos2d::Vec2(0.0, this->nodeBody->getVelocity().y));

				this->mNextJump.lock();
				if (this->nextJump)
				{
					this->toJump(nextJumpVelocity, false);
					this->nextJump = false;
				}
				this->mNextJump.unlock();

			}/*
			else if (this->rightMovement)
			{
				this->toClimbAnimation(RYUNOSUKE_SPEED);
				this->nodeBody->setVelocityLimit(RYUNOSUKE_WALL_SPEED);
				this->nodeBody->setVelocity(cocos2d::Vec2(0.0, this->nodeBody->getVelocity().y));

				this->mNextJump.lock();
				this->nextJump = false;
				this->mNextJump.unlock();

			}
			else if (this->leftMovement)
			{
				this->toClimbAnimation(RYUNOSUKE_SPEED);
				this->nodeBody->setVelocityLimit(RYUNOSUKE_WALL_SPEED);
				this->nodeBody->setVelocity(cocos2d::Vec2(0.0, this->nodeBody->getVelocity().y));

				this->mNextJump.lock();
				this->nextJump = false;
				this->mNextJump.unlock();

			}
			else
			{
				this->toClimbAnimation(RYUNOSUKE_SPEED);
				this->nodeBody->setVelocityLimit(RYUNOSUKE_WALL_SPEED);
				this->nodeBody->setVelocity(cocos2d::Vec2(0.0, this->nodeBody->getVelocity().y));

				this->mNextJump.lock();
				this->nextJump = false;
				this->mNextJump.unlock();

			}*/
			else
			{
				this->nodeBody->setVelocityLimit(RYUNOSUKE_WALL_SPEED);
				this->nodeBody->setVelocity(cocos2d::Vec2(0.0, this->nodeBody->getVelocity().y));

				this->mNextJump.lock();
				this->nextJump = false;
				this->mNextJump.unlock();

			}
			CCLOG("(ContactBegion) - Right Wall - On the floor");
		}
		this->mWallDetection.unlock();
	}
	else if ((a->getCollisionBitmask() == RYUNOSUKE_BITMASK && b->getCollisionBitmask() == LEFT_OBSTACLE_BITMASK) || (a->getCollisionBitmask() == LEFT_OBSTACLE_BITMASK && b->getCollisionBitmask() == RYUNOSUKE_BITMASK))
	{
		this->mWallDetection.lock();
		if (a->getCollisionBitmask() == RYUNOSUKE_BITMASK)
		{
			this->leftWalls.insert(b->getLinkedNode());
		}
		else
		{
			this->leftWalls.insert(a->getLinkedNode());
		}
		if (this->floors.empty() && this->floors.empty())
		{
			if (!this->rightMovement && !this->leftMovement)
			{
				this->mContiniousMovement.lock();

				this->nodeSprite->stopAction(this->movementAction);
				this->toClimbAnimation(RYUNOSUKE_SPEED);

				this->mContiniousMovement.unlock();

				this->nodeBody->setVelocity(cocos2d::Vec2(0.0, this->nodeBody->getVelocity().y));

				this->mNextJump.lock();
				if (this->nextJump)
				{
					this->toJump(nextJumpVelocity, false);
					this->nextJump = false;
				}
				this->mNextJump.unlock();

			}/*
			else if (this->rightMovement)
			{
				this->toClimbAnimation(RYUNOSUKE_SPEED);
				this->nodeBody->setVelocityLimit(RYUNOSUKE_WALL_SPEED);
				this->nodeBody->setVelocity(cocos2d::Vec2(0.0, this->nodeBody->getVelocity().y));

				this->mNextJump.lock();
				this->nextJump = false;
				this->mNextJump.unlock();

			}
			else if (this->leftMovement)
			{
				this->toClimbAnimation(RYUNOSUKE_SPEED);
				this->nodeBody->setVelocityLimit(RYUNOSUKE_WALL_SPEED);
				this->nodeBody->setVelocity(cocos2d::Vec2(0.0, this->nodeBody->getVelocity().y));

				this->mNextJump.lock();
				this->nextJump = false;
				this->mNextJump.unlock();

			}
			else
			{
				this->toClimbAnimation(RYUNOSUKE_SPEED);
				this->nodeBody->setVelocityLimit(RYUNOSUKE_WALL_SPEED);
				this->nodeBody->setVelocity(cocos2d::Vec2(0.0, this->nodeBody->getVelocity().y));

				this->mNextJump.lock();
				this->nextJump = false;
				this->mNextJump.unlock();

			}*/
			else
			{
				this->nodeBody->setVelocityLimit(RYUNOSUKE_WALL_SPEED);
				this->nodeBody->setVelocity(cocos2d::Vec2(0.0, this->nodeBody->getVelocity().y));

				this->mNextJump.lock();
				this->nextJump = false;
				this->mNextJump.unlock();

			}
			CCLOG("(ContactBegin) - Left Wall - Not on the floor");
		}
		else
		{
			if (!this->rightMovement && !this->leftMovement)
			{

				this->mContiniousMovement.lock();

				this->nodeSprite->stopAction(this->movementAction);
				this->toClimbAnimation(RYUNOSUKE_SPEED);

				this->mContiniousMovement.unlock();

				this->nodeBody->setVelocity(cocos2d::Vec2(0.0, this->nodeBody->getVelocity().y));

				this->mNextJump.lock();
				if (this->nextJump)
				{
					this->toJump(nextJumpVelocity, false);
					this->nextJump = false;
				}
				this->mNextJump.unlock();

			}/*
			else if (this->rightMovement)
			{
				this->toClimbAnimation(RYUNOSUKE_SPEED);
				this->nodeBody->setVelocityLimit(RYUNOSUKE_WALL_SPEED);
				this->nodeBody->setVelocity(cocos2d::Vec2(0.0, this->nodeBody->getVelocity().y));

				this->mNextJump.lock();
				this->nextJump = false;
				this->mNextJump.unlock();

			}
			else if (this->leftMovement)
			{
				this->toClimbAnimation(RYUNOSUKE_SPEED);
				this->nodeBody->setVelocityLimit(RYUNOSUKE_WALL_SPEED);
				this->nodeBody->setVelocity(cocos2d::Vec2(0.0, this->nodeBody->getVelocity().y));

				this->mNextJump.lock();
				this->nextJump = false;
				this->mNextJump.unlock();

			}
			else
			{
				this->toClimbAnimation(RYUNOSUKE_SPEED);
				this->nodeBody->setVelocityLimit(RYUNOSUKE_WALL_SPEED);
				this->nodeBody->setVelocity(cocos2d::Vec2(0.0, this->nodeBody->getVelocity().y));

				this->mNextJump.lock();
				this->nextJump = false;
				this->mNextJump.unlock();

			}*/
			else
			{
				this->nodeBody->setVelocityLimit(RYUNOSUKE_WALL_SPEED);
				this->nodeBody->setVelocity(cocos2d::Vec2(0.0, this->nodeBody->getVelocity().y));

				this->mNextJump.lock();
				this->nextJump = false;
				this->mNextJump.unlock();

			}
			CCLOG("(ContactBegin) - Left Wall - On the floor");
		}
		this->mWallDetection.unlock();
	}
	else if ((a->getCollisionBitmask() == RYUNOSUKE_BITMASK && b->getCollisionBitmask() == EDGE_FLOOR_RIGHT_BITMASK) || (a->getCollisionBitmask() == EDGE_FLOOR_RIGHT_BITMASK && b->getCollisionBitmask() == RYUNOSUKE_BITMASK))
	{
		this->mWallDetection.lock();

		cocos2d::Node *currentRyunosukeSprite;
		cocos2d::Node *edgeFloorNode;
		if (a->getCollisionBitmask() == RYUNOSUKE_BITMASK)
		{
			edgeFloorNode = b->getLinkedNode();
			this->edgeFloors.insert(edgeFloorNode);
			currentRyunosukeSprite = a->getLinkedNode();
		}
		else
		{
			edgeFloorNode = a->getLinkedNode();
			this->edgeFloors.insert(edgeFloorNode);
			currentRyunosukeSprite = b->getLinkedNode();
		}

		//Check if ryunosuke is over the floor detected.
		bool ryunosukeOverRightEdgeFloor = false;
		if (fabs((currentRyunosukeSprite->getPosition().x + this->nodeSprite->getContentSize().width) - (edgeFloorNode->getPosition().x + this->boxSize.width/2)) < fabs(currentRyunosukeSprite->getPosition().y - (edgeFloorNode->getPosition().y - this->boxSize.height)))
		{
			ryunosukeOverRightEdgeFloor = true;
		}

		if (ryunosukeOverRightEdgeFloor)
		{
			this->nodeBody->setVelocityLimit(cocos2d::PHYSICS_INFINITY);
			if (!this->rightMovement && !this->leftMovement)
			{
				if (this->nodeBody->getVelocity().y < RYUNOSUKE_JUMP_ON_FLOOR/2)
				{
					this->mContiniousMovement.lock();

					this->nodeSprite->stopAction(this->movementAction);
					this->toStopAnimation(0.0);

					this->mContiniousMovement.unlock();

					this->nodeBody->setVelocity(cocos2d::Vec2(0.0, this->nodeBody->getVelocity().y));

					this->mNextJump.lock();
					if (this->nextJump)
					{
						this->toJump(nextJumpVelocity, false);
						this->nextJump = false;
					}
					this->mNextJump.unlock();

				}
			}/*
			else if (this->rightMovement)
			{
				this->toMove(RYUNOSUKE_SPEED, false);

				this->mNextJump.lock();
				this->nextJump = false;
				this->mNextJump.unlock();

			}
			else if (this->leftMovement)
			{
				this->toMove(-RYUNOSUKE_SPEED, false);

				this->mNextJump.lock();
				this->nextJump = false;
				this->mNextJump.unlock();

			}*/
			else
			{
				this->mNextJump.lock();
				this->nextJump = false;
				this->mNextJump.unlock();
			}
			CCLOG("(ContactBegin) - Right Edge Floor - On the floor");
		}
		else
		{
			CCLOG("(ContactBegin) - Right Edge Floor - Not On the floor");
		    this->mWallDetection.unlock();
		    return false;
		}
        this->mWallDetection.unlock();
	}
	else if ((a->getCollisionBitmask() == RYUNOSUKE_BITMASK && b->getCollisionBitmask() == EDGE_FLOOR_LEFT_BITMASK) || (a->getCollisionBitmask() == EDGE_FLOOR_LEFT_BITMASK && b->getCollisionBitmask() == RYUNOSUKE_BITMASK))
	{
		this->mWallDetection.lock();

		cocos2d::Node *currentRyunosukeSprite;
		cocos2d::Node *edgeFloorNode;

		if (a->getCollisionBitmask() == RYUNOSUKE_BITMASK)
		{
			edgeFloorNode = b->getLinkedNode();
			this->edgeFloors.insert(edgeFloorNode);
			currentRyunosukeSprite = a->getLinkedNode();
		}
		else
		{
			edgeFloorNode = a->getLinkedNode();
			this->edgeFloors.insert(edgeFloorNode);
			currentRyunosukeSprite = b->getLinkedNode();
		}

		//Check if ryunosuke is over the floor detected.
        bool ryunosukeOverLeftEdgeFloor = false;
        if (fabs(currentRyunosukeSprite->getPosition().x - (edgeFloorNode->getPosition().x - this->boxSize.width/2)) < fabs(currentRyunosukeSprite->getPosition().y - (edgeFloorNode->getPosition().y - this->boxSize.height)))
        {
            ryunosukeOverLeftEdgeFloor = true;
        }

		if (ryunosukeOverLeftEdgeFloor)
		{
			this->nodeBody->setVelocityLimit(cocos2d::PHYSICS_INFINITY);
			if (!this->rightMovement && !this->leftMovement)
			{
				if (this->nodeBody->getVelocity().y < RYUNOSUKE_JUMP_ON_FLOOR/2)
				{
					this->mContiniousMovement.lock();

					this->nodeSprite->stopAction(this->movementAction);
					this->toStopAnimation(0.0);

					this->mContiniousMovement.unlock();

					this->nodeBody->setVelocity(cocos2d::Vec2(0.0, this->nodeBody->getVelocity().y));

					this->mNextJump.lock();
					if (this->nextJump)
					{
						this->toJump(nextJumpVelocity, false);
						this->nextJump = false;
					}
					this->mNextJump.unlock();

				}
			}/*
			else if (this->rightMovement)
			{
				this->toMove(RYUNOSUKE_SPEED, false);

				this->mNextJump.lock();
				this->nextJump = false;
				this->mNextJump.unlock();

			}
			else if (this->leftMovement)
			{
				this->toMove(-RYUNOSUKE_SPEED, false);

				this->mNextJump.lock();
				this->nextJump = false;
				this->mNextJump.unlock();

			}*/
			else
			{
				this->mNextJump.lock();
				this->nextJump = false;
				this->mNextJump.unlock();
			}
			CCLOG("(ContactBegion) - Left Edge Floor - On the floor");
		}
		else
		{
			CCLOG("(ContactBegion) - Left Edge Floor - Not On the floor");
		    this->mWallDetection.unlock();
		    return false;
		}
        this->mWallDetection.unlock();
	}
	else if ((a->getCollisionBitmask() == RYUNOSUKE_BITMASK && b->getCollisionBitmask() == EDGE_RIGHT_OBSTACLE_BITMASK) || (a->getCollisionBitmask() == EDGE_RIGHT_OBSTACLE_BITMASK && b->getCollisionBitmask() == RYUNOSUKE_BITMASK))
	{
		this->mWallDetection.lock();

		cocos2d::Node *currentRyunosukeSprite;
		cocos2d::Node *rightEdgeWallNode;

		if (a->getCollisionBitmask() == RYUNOSUKE_BITMASK)
		{
			rightEdgeWallNode = b->getLinkedNode();
			this->edgeRightWalls.insert(rightEdgeWallNode);
			currentRyunosukeSprite = a->getLinkedNode();
		}
		else
		{
			rightEdgeWallNode = a->getLinkedNode();
			this->edgeRightWalls.insert(rightEdgeWallNode);
			currentRyunosukeSprite = b->getLinkedNode();
		}

		//Check if ryunosuke is over the floor detected.
        bool ryunosukeOverRightEdgeFloor = false;
        if (fabs((currentRyunosukeSprite->getPosition().x + this->nodeSprite->getContentSize().width) - (rightEdgeWallNode->getPosition().x + this->boxSize.width)) < fabs(currentRyunosukeSprite->getPosition().y - (rightEdgeWallNode->getPosition().y - this->boxSize.height/2)))
        {
            ryunosukeOverRightEdgeFloor = true;
        }

        if (!ryunosukeOverRightEdgeFloor)
        {
            if (this->floors.empty() && this->edgeFloors.empty())
            {
                if (!this->rightMovement && !this->leftMovement)
                {
					this->toClimbAnimation(RYUNOSUKE_SPEED);
					this->nodeBody->setVelocity(cocos2d::Vec2(0.0, this->nodeBody->getVelocity().y));
					this->mNextJump.lock();
                    if (this->nextJump)
                    {
                        this->toJump(nextJumpVelocity, false);
                        this->nextJump = false;
                    }
                    this->mNextJump.unlock();

                }/*
                else if (this->rightMovement)
                {
					this->toClimbAnimation(RYUNOSUKE_SPEED);
                    this->nodeBody->setVelocityLimit(RYUNOSUKE_WALL_SPEED);
                    this->nodeBody->setVelocity(cocos2d::Vec2(0.0, this->nodeBody->getVelocity().y));

					this->mNextJump.lock();
                    this->nextJump = false;
                    this->mNextJump.unlock();

                }
                else if (this->leftMovement)
                {
					this->toClimbAnimation(RYUNOSUKE_SPEED);
                    this->nodeBody->setVelocityLimit(RYUNOSUKE_WALL_SPEED);
                    this->nodeBody->setVelocity(cocos2d::Vec2(0.0, this->nodeBody->getVelocity().y));

					this->mNextJump.lock();
                    this->nextJump = false;
                    this->mNextJump.unlock();

                }
                else
                {
					this->toClimbAnimation(RYUNOSUKE_SPEED);
                    this->nodeBody->setVelocityLimit(RYUNOSUKE_WALL_SPEED);
                    this->nodeBody->setVelocity(cocos2d::Vec2(0.0, this->nodeBody->getVelocity().y));

					this->mNextJump.lock();
                    this->nextJump = false;
                    this->mNextJump.unlock();

                }*/
				else
				{
					this->nodeBody->setVelocityLimit(RYUNOSUKE_WALL_SPEED);
					this->nodeBody->setVelocity(cocos2d::Vec2(0.0, this->nodeBody->getVelocity().y));

					this->mNextJump.lock();
					this->nextJump = false;
					this->mNextJump.unlock();
				}
				CCLOG("(ContactBegion) - Right Edge Wall - Under the upper edge floor - Not On the floor");
            }
            else
            {
                if (!this->rightMovement && !this->leftMovement)
                {
					this->mContiniousMovement.lock();

					this->nodeSprite->stopAction(this->movementAction);
					this->toStopAnimation(0.0);

					this->mContiniousMovement.unlock();

					this->nodeBody->setVelocity(cocos2d::Vec2(0.0, this->nodeBody->getVelocity().y));

					this->mNextJump.lock();
                    if (this->nextJump)
                    {
                        this->toJump(nextJumpVelocity, false);
                        this->nextJump = false;
                    }
                    this->mNextJump.unlock();

                }/*
                else if (this->rightMovement)
                {
					this->toClimbAnimation(RYUNOSUKE_SPEED);
                    this->nodeBody->setVelocityLimit(RYUNOSUKE_WALL_SPEED);
                    this->nodeBody->setVelocity(cocos2d::Vec2(0.0, 0.0));

					this->mNextJump.lock();
                    this->nextJump = false;
                    this->mNextJump.unlock();

                }
                else if (this->leftMovement)
                {
					this->toClimbAnimation(RYUNOSUKE_SPEED);
                    this->nodeBody->setVelocityLimit(RYUNOSUKE_WALL_SPEED);
                    this->nodeBody->setVelocity(cocos2d::Vec2(0.0, 0.0));

					this->mNextJump.lock();
                    this->nextJump = false;
                    this->mNextJump.unlock();

                }
                else
                {
					this->toClimbAnimation(RYUNOSUKE_SPEED);
                    this->nodeBody->setVelocityLimit(RYUNOSUKE_WALL_SPEED);
                    this->nodeBody->setVelocity(cocos2d::Vec2(0.0, 0.0));

					this->mNextJump.lock();
                    this->nextJump = false;
                    this->mNextJump.unlock();

                }*/
				else
				{
					this->nodeBody->setVelocityLimit(RYUNOSUKE_WALL_SPEED);
					this->nodeBody->setVelocity(cocos2d::Vec2(0.0, 0.0));

					this->mNextJump.lock();
					this->nextJump = false;
					this->mNextJump.unlock();
				}
				CCLOG("(ContactBegion) - Right Edge Wall - Under the upper edge floor - On the floor");
            }
        }
        else
        {
			CCLOG("(ContactBegion) - Right Edge Wall - Over the upper edge floor");
            this->mWallDetection.unlock();
            return false;
        }
		this->mWallDetection.unlock();
	}
	else if ((a->getCollisionBitmask() == RYUNOSUKE_BITMASK && b->getCollisionBitmask() == EDGE_LEFT_OBSTACLE_BITMASK) || (a->getCollisionBitmask() == EDGE_LEFT_OBSTACLE_BITMASK && b->getCollisionBitmask() == RYUNOSUKE_BITMASK))
	{
		this->mWallDetection.lock();

		cocos2d::Node *currentRyunosukeSprite;
		cocos2d::Node *leftEdgeWallNode;

		if (a->getCollisionBitmask() == RYUNOSUKE_BITMASK)
		{
			leftEdgeWallNode = b->getLinkedNode();
			this->edgeLeftWalls.insert(leftEdgeWallNode);
			currentRyunosukeSprite = a->getLinkedNode();
		}
		else
		{
			leftEdgeWallNode = a->getLinkedNode();
			this->edgeLeftWalls.insert(leftEdgeWallNode);
			currentRyunosukeSprite = b->getLinkedNode();
		}

		//Check if ryunosuke is over the floor detected.
        bool ryunosukeOverLeftEdgeFloor = false;
        if (fabs(currentRyunosukeSprite->getPosition().x - (leftEdgeWallNode->getPosition().x - this->boxSize.width)) < fabs(currentRyunosukeSprite->getPosition().y - (leftEdgeWallNode->getPosition().y - this->boxSize.height/2)))
        {
            ryunosukeOverLeftEdgeFloor = true;
        }

        if (!ryunosukeOverLeftEdgeFloor)
        {
            if (this->floors.empty() && this->edgeFloors.empty())
            {
                if (!this->rightMovement && !this->leftMovement)
                {
					this->toClimbAnimation(RYUNOSUKE_SPEED);
                    this->nodeBody->setVelocity(cocos2d::Vec2(0.0, this->nodeBody->getVelocity().y));

					this->mNextJump.lock();
                    if (this->nextJump)
                    {
                        this->toJump(nextJumpVelocity, false);
                        this->nextJump = false;
                    }
                    this->mNextJump.unlock();

                }/*
                else if (this->rightMovement)
                {
					this->toClimbAnimation(RYUNOSUKE_SPEED);
                    this->nodeBody->setVelocityLimit(RYUNOSUKE_WALL_SPEED);
                    this->nodeBody->setVelocity(cocos2d::Vec2(0.0, this->nodeBody->getVelocity().y));

					this->mNextJump.lock();
                    this->nextJump = false;
                    this->mNextJump.unlock();

                }
                else if (this->leftMovement)
                {
					this->toClimbAnimation(RYUNOSUKE_SPEED);
                    this->nodeBody->setVelocityLimit(RYUNOSUKE_WALL_SPEED);
                    this->nodeBody->setVelocity(cocos2d::Vec2(0.0, this->nodeBody->getVelocity().y));

					this->mNextJump.lock();
                    this->nextJump = false;
                    this->mNextJump.unlock();

                }
                else
                {
					this->toClimbAnimation(RYUNOSUKE_SPEED);
                    this->nodeBody->setVelocityLimit(RYUNOSUKE_WALL_SPEED);
                    this->nodeBody->setVelocity(cocos2d::Vec2(0.0, this->nodeBody->getVelocity().y));

					this->mNextJump.lock();
                    this->nextJump = false;
                    this->mNextJump.unlock();

                }*/
				else
				{
					this->nodeBody->setVelocityLimit(RYUNOSUKE_WALL_SPEED);
					this->nodeBody->setVelocity(cocos2d::Vec2(0.0, this->nodeBody->getVelocity().y));

					this->mNextJump.lock();
					this->nextJump = false;
					this->mNextJump.unlock();

				}
				CCLOG("(ContactBegion) - Left Edge Wall - Under the upper edge floor - Not On the floor");
            }
            else
            {
                if (!this->rightMovement && !this->leftMovement)
                {
					this->mContiniousMovement.lock();

					this->nodeSprite->stopAction(this->movementAction);
					this->toStopAnimation(0.0);

					this->mContiniousMovement.unlock();

                    this->nodeBody->setVelocity(cocos2d::Vec2(0.0, 0.0));

					this->mNextJump.lock();
                    if (this->nextJump)
                    {
                        this->toJump(nextJumpVelocity, false);
                        this->nextJump = false;
                    }
                    this->mNextJump.unlock();

                }/*
                else if (this->rightMovement)
                {
					this->toClimbAnimation(RYUNOSUKE_SPEED);
                    this->nodeBody->setVelocityLimit(RYUNOSUKE_WALL_SPEED);
                    this->nodeBody->setVelocity(cocos2d::Vec2(0.0, 0.0));

					this->mNextJump.lock();
                    this->nextJump = false;
                    this->mNextJump.unlock();

                }
                else if (this->leftMovement)
                {
					this->toClimbAnimation(RYUNOSUKE_SPEED);
                    this->nodeBody->setVelocityLimit(RYUNOSUKE_WALL_SPEED);
                    this->nodeBody->setVelocity(cocos2d::Vec2(0.0, 0.0));

					this->mNextJump.lock();
                    this->nextJump = false;
                    this->mNextJump.unlock();

                }
                else
                {
					this->toClimbAnimation(RYUNOSUKE_SPEED);
                    this->nodeBody->setVelocityLimit(RYUNOSUKE_WALL_SPEED);
                    this->nodeBody->setVelocity(cocos2d::Vec2(0.0, 0.0));

					this->mNextJump.lock();
                    this->nextJump = false;
                    this->mNextJump.unlock();

                }*/
                else
                {
                    this->nodeBody->setVelocityLimit(RYUNOSUKE_WALL_SPEED);
                    this->nodeBody->setVelocity(cocos2d::Vec2(0.0, 0.0));

					this->mNextJump.lock();
                    this->nextJump = false;
                    this->mNextJump.unlock();

                }
				CCLOG("(ContactBegion) - Left Edge Wall - Under the upper edge floor - On the floor");
            }
        }
        else
        {
			CCLOG("(ContactBegion) - Left Edge Wall - Over the upper edge floor");
            this->mWallDetection.unlock();
            return false;
        }
		this->mWallDetection.unlock();
	}
	else if ((a->getCollisionBitmask() == RYUNOSUKE_BITMASK && b->getCollisionBitmask() == OIL_RIGHT_OBSTACLE_BITMASK) || (a->getCollisionBitmask() == OIL_RIGHT_OBSTACLE_BITMASK && b->getCollisionBitmask() == RYUNOSUKE_BITMASK))
	{
		this->mWallDetection.lock();

		cocos2d::Node *currentRyunosukeSprite;
		cocos2d::Node *rightOilWallNode;

		if (a->getCollisionBitmask() == RYUNOSUKE_BITMASK)
		{
			rightOilWallNode = b->getLinkedNode();
			this->oilRightWalls.insert(rightOilWallNode);
			currentRyunosukeSprite = a->getLinkedNode();
		}
		else
		{
			rightOilWallNode = a->getLinkedNode();
			this->oilRightWalls.insert(rightOilWallNode);
			currentRyunosukeSprite = b->getLinkedNode();
		}

		//Check if ryunosuke is over the floor detected.
		bool ryunosukeOverRightOilFloor = false;
		if (fabs((currentRyunosukeSprite->getPosition().x + this->nodeSprite->getContentSize().width) - (rightOilWallNode->getPosition().x + this->boxSize.width)) < fabs((currentRyunosukeSprite->getPosition().y + this->nodeSprite->getContentSize().height) - (rightOilWallNode->getPosition().y + this->boxSize.height / 2)))
		{
			ryunosukeOverRightOilFloor = true;
		}

		if (!ryunosukeOverRightOilFloor)
		{
			if (this->floors.empty() && this->edgeFloors.empty())
			{
				if (!this->rightMovement && !this->leftMovement)
				{
					this->toClimbAnimation(RYUNOSUKE_SPEED);
					this->nodeBody->setVelocity(cocos2d::Vec2(0.0, this->nodeBody->getVelocity().y));

					this->mNextJump.lock();
					if (this->nextJump)
					{
						this->toJump(nextJumpVelocity, false);
						this->nextJump = false;
					}
					this->mNextJump.unlock();

				}/*
				else if (this->rightMovement)
				{
					this->toClimbAnimation(RYUNOSUKE_SPEED);
					//this->nodeBody->setVelocityLimit(RYUNOSUKE_WALL_SPEED);
					this->nodeBody->setVelocity(cocos2d::Vec2(0.0, this->nodeBody->getVelocity().y));

					this->mNextJump.lock();
					this->nextJump = false;
					this->mNextJump.unlock();

				}
				else if (this->leftMovement)
				{
					this->toClimbAnimation(RYUNOSUKE_SPEED);
					//this->nodeBody->setVelocityLimit(RYUNOSUKE_WALL_SPEED);
					this->nodeBody->setVelocity(cocos2d::Vec2(0.0, this->nodeBody->getVelocity().y));

					this->mNextJump.lock();
					this->nextJump = false;
					this->mNextJump.unlock();

				}
				else
				{
					this->toClimbAnimation(RYUNOSUKE_SPEED);
					//this->nodeBody->setVelocityLimit(RYUNOSUKE_WALL_SPEED);
					this->nodeBody->setVelocity(cocos2d::Vec2(0.0, this->nodeBody->getVelocity().y));

					this->mNextJump.lock();
					this->nextJump = false;
					this->mNextJump.unlock();

				}*/
				else
				{
					this->nodeBody->setVelocity(cocos2d::Vec2(0.0, this->nodeBody->getVelocity().y));
					this->mNextJump.lock();
					this->nextJump = false;
					this->mNextJump.unlock();

				}
				CCLOG("(ContactBegion) - Oil Left Wall - Not on the floor");
			}
			else
			{
				if (!this->rightMovement && !this->leftMovement)
				{
					this->toClimbAnimation(RYUNOSUKE_SPEED);
					this->nodeBody->setVelocity(cocos2d::Vec2(0.0, this->nodeBody->getVelocity().y));

					this->mNextJump.lock();
					if (this->nextJump)
					{
						this->toJump(nextJumpVelocity, false);
						this->nextJump = false;
					}
					this->mNextJump.unlock();

				}/*
				else if (this->rightMovement)
				{
					this->toClimbAnimation(RYUNOSUKE_SPEED);
					//this->nodeBody->setVelocityLimit(RYUNOSUKE_WALL_SPEED);
					this->nodeBody->setVelocity(cocos2d::Vec2(0.0, this->nodeBody->getVelocity().y));

					this->mNextJump.lock();
					this->nextJump = false;
					this->mNextJump.unlock();

				}
				else if (this->leftMovement)
				{
					this->toClimbAnimation(RYUNOSUKE_SPEED);
					//this->nodeBody->setVelocityLimit(RYUNOSUKE_WALL_SPEED);
					this->nodeBody->setVelocity(cocos2d::Vec2(0.0, this->nodeBody->getVelocity().y));

					this->mNextJump.lock();
					this->nextJump = false;
					this->mNextJump.unlock();

				}
				else
				{
					this->toClimbAnimation(RYUNOSUKE_SPEED);
					//this->nodeBody->setVelocityLimit(RYUNOSUKE_WALL_SPEED);
					this->nodeBody->setVelocity(cocos2d::Vec2(0.0, this->nodeBody->getVelocity().y));

					this->mNextJump.lock();
					this->nextJump = false;
					this->mNextJump.unlock();

				}*/
				else
				{
					this->nodeBody->setVelocity(cocos2d::Vec2(0.0, this->nodeBody->getVelocity().y));

					this->mNextJump.lock();
					this->nextJump = false;
					this->mNextJump.unlock();

				}
				CCLOG("(ContactBegion) - Oil Right Wall - On the floor");
			}
		}
		else
		{
			CCLOG("(ContactBegion) - Right Oil Wall - Over the upper Oil floor");
			this->mWallDetection.unlock();
			return false;
		}
		this->mWallDetection.unlock();
	}
	else if ((a->getCollisionBitmask() == RYUNOSUKE_BITMASK && b->getCollisionBitmask() == OIL_LEFT_OBSTACLE_BITMASK) || (a->getCollisionBitmask() == OIL_LEFT_OBSTACLE_BITMASK && b->getCollisionBitmask() == RYUNOSUKE_BITMASK))
	{
		this->mWallDetection.lock();

		cocos2d::Node *currentRyunosukeSprite;
		cocos2d::Node *leftOilWallNode;

		if (a->getCollisionBitmask() == RYUNOSUKE_BITMASK)
		{
			leftOilWallNode = b->getLinkedNode();
			this->oilLeftWalls.insert(leftOilWallNode);
			currentRyunosukeSprite = a->getLinkedNode();
		}
		else
		{
			leftOilWallNode = a->getLinkedNode();
			this->oilLeftWalls.insert(leftOilWallNode);
			currentRyunosukeSprite = b->getLinkedNode();
		}

		//Check if ryunosuke is over the floor detected.
		bool ryunosukeOverLeftOilFloor = false;
		if (fabs(currentRyunosukeSprite->getPosition().x - (leftOilWallNode->getPosition().x - this->boxSize.width)) < fabs((currentRyunosukeSprite->getPosition().y + this->nodeSprite->getContentSize().height) - (leftOilWallNode->getPosition().y + this->boxSize.height / 2)))
		{
			ryunosukeOverLeftOilFloor = true;
		}

		if (!ryunosukeOverLeftOilFloor)
		{
			if (this->floors.empty() && this->edgeFloors.empty())
			{
				if (!this->rightMovement && !this->leftMovement)
				{
					this->toClimbAnimation(RYUNOSUKE_SPEED);
					this->nodeBody->setVelocity(cocos2d::Vec2(0.0, this->nodeBody->getVelocity().y));

					this->mNextJump.lock();
					if (this->nextJump)
					{
						this->toJump(nextJumpVelocity, false);
						this->nextJump = false;
					}
					this->mNextJump.unlock();

				}/*
				else if (this->rightMovement)
				{
					this->toClimbAnimation(RYUNOSUKE_SPEED);
					//this->nodeBody->setVelocityLimit(RYUNOSUKE_WALL_SPEED);
					this->nodeBody->setVelocity(cocos2d::Vec2(0.0, this->nodeBody->getVelocity().y));

					this->mNextJump.lock();
					this->nextJump = false;
					this->mNextJump.unlock();

				}
				else if (this->leftMovement)
				{
					this->toClimbAnimation(RYUNOSUKE_SPEED);
					//this->nodeBody->setVelocityLimit(RYUNOSUKE_WALL_SPEED);
					this->nodeBody->setVelocity(cocos2d::Vec2(0.0, this->nodeBody->getVelocity().y));

					this->mNextJump.lock();
					this->nextJump = false;
					this->mNextJump.unlock();

				}
				else
				{
					this->toClimbAnimation(RYUNOSUKE_SPEED);
					//this->nodeBody->setVelocityLimit(RYUNOSUKE_WALL_SPEED);
					this->nodeBody->setVelocity(cocos2d::Vec2(0.0, this->nodeBody->getVelocity().y));

					this->mNextJump.lock();
					this->nextJump = false;
					this->mNextJump.unlock();

				}*/
				else
				{
					this->nodeBody->setVelocity(cocos2d::Vec2(0.0, this->nodeBody->getVelocity().y));

					this->mNextJump.lock();
					this->nextJump = false;
					this->mNextJump.unlock();

				}
				CCLOG("(ContactBegion) - Oil Left Wall - Not on the floor");
			}
			else
			{
				if (!this->rightMovement && !this->leftMovement)
				{
					this->toClimbAnimation(RYUNOSUKE_SPEED);
					this->nodeBody->setVelocity(cocos2d::Vec2(0.0, this->nodeBody->getVelocity().y));

					this->mNextJump.lock();
					if (this->nextJump)
					{
						this->toJump(nextJumpVelocity, false);
						this->nextJump = false;
					}
					this->mNextJump.unlock();

				}/*
				else if (this->rightMovement)
				{
					this->toClimbAnimation(RYUNOSUKE_SPEED);
					//this->nodeBody->setVelocityLimit(RYUNOSUKE_WALL_SPEED);
					this->nodeBody->setVelocity(cocos2d::Vec2(0.0, this->nodeBody->getVelocity().y));

					this->mNextJump.lock();
					this->nextJump = false;
					this->mNextJump.unlock();

				}
				else if (this->leftMovement)
				{
					this->toClimbAnimation(RYUNOSUKE_SPEED);
					//this->nodeBody->setVelocityLimit(RYUNOSUKE_WALL_SPEED);
					this->nodeBody->setVelocity(cocos2d::Vec2(0.0, this->nodeBody->getVelocity().y));

					this->mNextJump.lock();
					this->nextJump = false;
					this->mNextJump.unlock();

				}
				else
				{
					this->toClimbAnimation(RYUNOSUKE_SPEED);
					//this->nodeBody->setVelocityLimit(RYUNOSUKE_WALL_SPEED);
					this->nodeBody->setVelocity(cocos2d::Vec2(0.0, this->nodeBody->getVelocity().y));

					this->mNextJump.lock();
					this->nextJump = false;
					this->mNextJump.unlock();

				}*/
				else
				{
					this->nodeBody->setVelocity(cocos2d::Vec2(0.0, this->nodeBody->getVelocity().y));

					this->mNextJump.lock();
					this->nextJump = false;
					this->mNextJump.unlock();

				}
				CCLOG("(ContactBegion) - Oil Right Wall - On the floor");
			}
		}
		else
		{
			CCLOG("(ContactBegion) - Left Oil Wall - Over the upper Oil floor");
			this->mWallDetection.unlock();
			return false;
		}
		this->mWallDetection.unlock();
	}
	return false;
}

bool NinjaM::Ryunosuke::onContactSeparate(cocos2d::PhysicsContact &contact)
{
	CCLOG("onContactSeparate");
	cocos2d::PhysicsBody *a = contact.getShapeA()->getBody();
	cocos2d::PhysicsBody *b = contact.getShapeB()->getBody();

	this->mWallDetection.lock();
	if ((a->getCollisionBitmask() == RYUNOSUKE_BITMASK && b->getCollisionBitmask() == FLOOR_BITMASK) || (a->getCollisionBitmask() == FLOOR_BITMASK && b->getCollisionBitmask() == RYUNOSUKE_BITMASK))
	{
		if (a->getCollisionBitmask() == RYUNOSUKE_BITMASK)
		{
			this->floors.erase(b->getLinkedNode());
		}
		else
		{
			this->floors.erase(a->getLinkedNode());
		}
		CCLOG("Floor Separation");
	}
	else if ((a->getCollisionBitmask() == RYUNOSUKE_BITMASK && b->getCollisionBitmask() == RIGHT_OBSTACLE_BITMASK) || (a->getCollisionBitmask() == RIGHT_OBSTACLE_BITMASK && b->getCollisionBitmask() == RYUNOSUKE_BITMASK))
	{
		if (a->getCollisionBitmask() == RYUNOSUKE_BITMASK)
		{
			this->rightWalls.erase(b->getLinkedNode());
		}
		else
		{
			this->rightWalls.erase(a->getLinkedNode());
		}
		if (this->rightWalls.empty() && this->edgeRightWalls.empty())
		{
			this->nodeBody->setVelocityLimit(cocos2d::PHYSICS_INFINITY);
		}
		CCLOG("Right Wall Separation");
	}
	else if ((a->getCollisionBitmask() == RYUNOSUKE_BITMASK && b->getCollisionBitmask() == LEFT_OBSTACLE_BITMASK) || (a->getCollisionBitmask() == LEFT_OBSTACLE_BITMASK && b->getCollisionBitmask() == RYUNOSUKE_BITMASK))
    {
		if (a->getCollisionBitmask() == RYUNOSUKE_BITMASK)
		{
			this->leftWalls.erase(b->getLinkedNode());
		}
		else
		{
			this->leftWalls.erase(a->getLinkedNode());
		}
		if (this->leftWalls.empty() && this->edgeLeftWalls.empty())
		{
			this->nodeBody->setVelocityLimit(cocos2d::PHYSICS_INFINITY);
		}
		CCLOG("Left Wall Separation");
    }
	else if ((a->getCollisionBitmask() == RYUNOSUKE_BITMASK && b->getCollisionBitmask() == EDGE_FLOOR_RIGHT_BITMASK) || (a->getCollisionBitmask() == EDGE_FLOOR_RIGHT_BITMASK && b->getCollisionBitmask() == RYUNOSUKE_BITMASK))
	{
		if (a->getCollisionBitmask() == RYUNOSUKE_BITMASK)
		{
			this->edgeFloors.erase(b->getLinkedNode());
		}
		else
		{
			this->edgeFloors.erase(a->getLinkedNode());
		}
		CCLOG("Edge Right Floor Separation");
	}
	else if ((a->getCollisionBitmask() == RYUNOSUKE_BITMASK && b->getCollisionBitmask() == EDGE_FLOOR_LEFT_BITMASK) || (a->getCollisionBitmask() == EDGE_FLOOR_LEFT_BITMASK && b->getCollisionBitmask() == RYUNOSUKE_BITMASK))
	{
		if (a->getCollisionBitmask() == RYUNOSUKE_BITMASK)
		{
			this->edgeFloors.erase(b->getLinkedNode());
		}
		else
		{
			this->edgeFloors.erase(a->getLinkedNode());
		}
		CCLOG("Edge Left Floor Separation");
	}
	else if ((a->getCollisionBitmask() == RYUNOSUKE_BITMASK && b->getCollisionBitmask() == EDGE_RIGHT_OBSTACLE_BITMASK) || (a->getCollisionBitmask() == EDGE_RIGHT_OBSTACLE_BITMASK && b->getCollisionBitmask() == RYUNOSUKE_BITMASK))
	{
		if (a->getCollisionBitmask() == RYUNOSUKE_BITMASK)
		{
			this->edgeRightWalls.erase(b->getLinkedNode());
		}
		else
		{
			this->edgeRightWalls.erase(a->getLinkedNode());
		}
		if (this->rightWalls.empty() && this->edgeRightWalls.empty())
		{
			this->nodeBody->setVelocityLimit(cocos2d::PHYSICS_INFINITY);
		}
		CCLOG("Edge Right Wall Separation");
	}
	else if ((a->getCollisionBitmask() == RYUNOSUKE_BITMASK && b->getCollisionBitmask() == EDGE_LEFT_OBSTACLE_BITMASK) || (a->getCollisionBitmask() == EDGE_LEFT_OBSTACLE_BITMASK && b->getCollisionBitmask() == RYUNOSUKE_BITMASK))
	{
		if (a->getCollisionBitmask() == RYUNOSUKE_BITMASK)
		{
			this->edgeLeftWalls.erase(b->getLinkedNode());
		}
		else
		{
			this->edgeLeftWalls.erase(a->getLinkedNode());
		}
		if (this->leftWalls.empty() && this->edgeLeftWalls.empty())
		{
			this->nodeBody->setVelocityLimit(cocos2d::PHYSICS_INFINITY);
		}
		CCLOG("Edge Left Wall Separation");
	}
	else if ((a->getCollisionBitmask() == RYUNOSUKE_BITMASK && b->getCollisionBitmask() == OIL_RIGHT_OBSTACLE_BITMASK) || (a->getCollisionBitmask() == OIL_RIGHT_OBSTACLE_BITMASK && b->getCollisionBitmask() == RYUNOSUKE_BITMASK))
	{
		if (a->getCollisionBitmask() == RYUNOSUKE_BITMASK)
		{
			this->oilRightWalls.erase(b->getLinkedNode());
		}
		else
		{
			this->oilRightWalls.erase(a->getLinkedNode());
		}
		CCLOG("Oil Right Wall Separation");
	}
	else if ((a->getCollisionBitmask() == RYUNOSUKE_BITMASK && b->getCollisionBitmask() == OIL_LEFT_OBSTACLE_BITMASK) || (a->getCollisionBitmask() == OIL_LEFT_OBSTACLE_BITMASK && b->getCollisionBitmask() == RYUNOSUKE_BITMASK))
	{
		if (a->getCollisionBitmask() == RYUNOSUKE_BITMASK)
		{
			this->oilLeftWalls.erase(b->getLinkedNode());
		}
		else
		{
			this->oilLeftWalls.erase(a->getLinkedNode());
		}
		CCLOG("Oil Left Wall Separation");
	}
	this->mWallDetection.unlock();
}


cocos2d::Node* NinjaM::Ryunosuke::searchForCorrespondenceFloor(std::set <cocos2d::Node*> edgeRightWalls, std::set <cocos2d::Node*> edgeFloors)
{
	int numCorrespondences = 0;
	cocos2d::Node* result;
	for (std::set <cocos2d::Node*>::iterator itW = edgeRightWalls.begin(); itW != edgeRightWalls.end(); itW++)
	{
		for (std::set <cocos2d::Node*>::iterator itF = edgeFloors.begin(); itF != edgeFloors.end(); itF++)
		{
			if (((cocos2d::Sprite*)*itW)->getPhysicsBody()->getOwnerNode() == ((cocos2d::Sprite*)*itF)->getPhysicsBody()->getOwnerNode())
			{
				numCorrespondences++;
				result = *itF;
			}
		}
	}
	if (numCorrespondences != 1)
	{
		return nullptr;
	}

	return result;
}

cocos2d::Node* NinjaM::Ryunosuke::searchForCorrespondenceWall(std::set <cocos2d::Node*> edgeRightWalls, std::set <cocos2d::Node*> edgeFloors)
{
	int numCorrespondences = 0;
	cocos2d::Node* result;
	for (std::set <cocos2d::Node*>::iterator itW = edgeRightWalls.begin(); itW != edgeRightWalls.end(); itW++)
	{
		for (std::set <cocos2d::Node*>::iterator itF = edgeFloors.begin(); itF != edgeFloors.end(); itF++)
		{
			if (((cocos2d::Sprite*)*itW)->getPhysicsBody()->getOwnerNode() == ((cocos2d::Sprite*)*itF)->getPhysicsBody()->getOwnerNode())
			{
				numCorrespondences++;
				result = *itW;
			}
		}
	}
	if (numCorrespondences != 1)
	{
		return nullptr;
	}

	return result;
}