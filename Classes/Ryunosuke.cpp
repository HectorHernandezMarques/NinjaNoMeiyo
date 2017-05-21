//
// Created by AntonioMontana on 14/03/2017.
//

#include <unistd.h>
#include "./Ryunosuke.h"
#include <sstream>
char* Convert(float number) {
	std::ostringstream buff;
	buff << number;
	return &buff.str()[0];
}
NinjaM::Ryunosuke::Ryunosuke()
{

}

NinjaM::Ryunosuke::Ryunosuke(cocos2d::Size visibleSize, cocos2d::Vec2 position, cocos2d::Vec2 anchorPoint, std::string texture, float rotation) : Character(visibleSize, position, anchorPoint, texture, rotation)
{
	CCLOG("Ryunosuke builder");
}

NinjaM::Ryunosuke::~Ryunosuke()
{

}

void NinjaM::Ryunosuke::spawn(cocos2d::Layer *layer)
{
    NinjaM::Node::spawn(layer);
	auto material = cocos2d::PHYSICSBODY_MATERIAL_DEFAULT;
	material.density = 1.0f;
	material.restitution = 0.5f;
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

void NinjaM::Ryunosuke::toMove(float velocity)
{
	if (velocity>0.0)
	{
	    if (!this->onTheRightWall)
	    {
		    this->rightMovement = true;
	        this->lastXVelocity = fabs(velocity);
	        this->nodeBody->setVelocity(cocos2d::Vec2(velocity, this->nodeBody->getVelocity().y));
	    }
	    else if (!this->onTheFloor)
	    {
	        //Holding wall position
		    this->rightMovement = true;
	        this->lastXVelocity = fabs(velocity);
	        this->nodeBody->setVelocityLimit(RYUNOSUKE_WALL_SPEED);
	        this->nodeBody->setVelocity(cocos2d::Vec2(0.0, 0.0));
	    }
		this->nodeSprite->setTexture("Ryunosuke1D.png");
	}
	else
	{
	    if (!this->onTheLeftWall)
	    {
		    this->leftMovement = true;
	        this->lastXVelocity = fabs(velocity);
	        this->nodeBody->setVelocity(cocos2d::Vec2(velocity, this->nodeBody->getVelocity().y));
	    }
	    else if (!this->onTheFloor)
	    {
	        //Holding wall position
		    this->leftMovement = true;
		    this->lastXVelocity = fabs(velocity);
	        this->nodeBody->setVelocityLimit(RYUNOSUKE_WALL_SPEED);
	        this->nodeBody->setVelocity(cocos2d::Vec2(0.0, 0.0));
	    }
		this->nodeSprite->setTexture("Ryunosuke1I.png");
	}

}

void NinjaM::Ryunosuke::toStop(float velocity)
{
    this->nodeBody->setVelocityLimit(cocos2d::PHYSICS_INFINITY);
	if (velocity>0.0)
	{
		this->rightMovement = false;
		if (!this->leftMovement)
		{
			if (this->onTheFloor)
			{
				this->nodeBody->setVelocity(cocos2d::Vec2(0.0, this->nodeBody->getVelocity().y));
			}
		}
		else
		{
		    this->toMove(-this->lastXVelocity);
		}
	}
	else
	{
		this->leftMovement = false;
		if (!this->rightMovement)
		{
			if (this->onTheFloor)
			{
				this->nodeBody->setVelocity(cocos2d::Vec2(0.0, this->nodeBody->getVelocity().y));
			}
		}
		else
		{
		    this->toMove(this->lastXVelocity);
		}
	}
}

void NinjaM::Ryunosuke::toJump(float velocity)
{
	if (this->onTheFloor)
	{
	    //toStop() needs to know if ryunosuke is in the air in order to either stop or let him go
		this->onTheFloor = false;
		this->nodeBody->setVelocityLimit(cocos2d::PHYSICS_INFINITY);
		getNodeSprite()->getPhysicsBody()->setVelocity(cocos2d::Vec2(velocity, RYUNOSUKE_JUMP_ON_FLOOR));
		if (velocity > 0.0)
		{
			this->nodeSprite->setTexture("Ryunosuke1D.png");
		}
		else if (velocity < 0.0)
		{
			this->nodeSprite->setTexture("Ryunosuke1I.png");
		}
	}
	else if(this->onTheRightWall)
	{
	    this->nodeBody->setVelocityLimit(cocos2d::PHYSICS_INFINITY);
		if (velocity > 0.0)
		{
			getNodeSprite()->getPhysicsBody()->setVelocity(cocos2d::Vec2(0.0, RYUNOSUKE_JUMP_ON_WALL));
			this->nodeSprite->setTexture("Ryunosuke1D.png");
		}
		else if (velocity < 0.0)
		{
			getNodeSprite()->getPhysicsBody()->setVelocity(cocos2d::Vec2(velocity, RYUNOSUKE_JUMP_ON_WALL));
			this->nodeSprite->setTexture("Ryunosuke1I.png");
		}
	}
	else if (this->onTheLeftWall)
	{
		this->nodeBody->setVelocityLimit(cocos2d::PHYSICS_INFINITY);
		if (velocity > 0.0)
		{
			getNodeSprite()->getPhysicsBody()->setVelocity(cocos2d::Vec2(velocity, RYUNOSUKE_JUMP_ON_WALL));
			this->nodeSprite->setTexture("Ryunosuke1D.png");
		}
		else if (velocity < 0.0)
		{
			getNodeSprite()->getPhysicsBody()->setVelocity(cocos2d::Vec2(0.0, RYUNOSUKE_JUMP_ON_WALL));
			this->nodeSprite->setTexture("Ryunosuke1I.png");
		}
	}
	else
	{
	    if (this->mNextJump.try_lock()){
	        this->nextJumpVelocity = velocity;
	        this->nextJump = true;
            cocos2d::DelayTime *delayAction = cocos2d::DelayTime::create(RYUNOSUKE_JUMP_TIME_REMEMBER);
            cocos2d::CallFunc *jumpCleanerAction = cocos2d::CallFunc::create(CC_CALLBACK_0(NinjaM::Ryunosuke::jumpCleaner, this, ++this->jumpCounter));
            this->nodeSprite->runAction(cocos2d::Sequence::create(delayAction, jumpCleanerAction, nullptr));
	        this->mNextJump.unlock();
	    }
	}
}


void NinjaM::Ryunosuke::jumpCleaner(unsigned int jumpCounter)
{
	if (this->mNextJump.try_lock())
	{
	    if (jumpCounter == this->jumpCounter)
	    {
	        this->nextJump = false;
	    }
	    this->mNextJump.unlock();
	}
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
	cocos2d::PhysicsBody *a = contact.getShapeA()->getBody();
	cocos2d::PhysicsBody *b = contact.getShapeB()->getBody();

	if ((a->getCollisionBitmask() == RYUNOSUKE_BITMASK && b->getCollisionBitmask() == FIXED_OBSTACLE_BITMASK) || (a->getCollisionBitmask() == FIXED_OBSTACLE_BITMASK && b->getCollisionBitmask() == RYUNOSUKE_BITMASK))
	{
		return true;
	}
	else if ((a->getCollisionBitmask() == RYUNOSUKE_BITMASK && b->getCollisionBitmask() == FLOOR_BITMASK) || (a->getCollisionBitmask() == FLOOR_BITMASK && b->getCollisionBitmask() == RYUNOSUKE_BITMASK))
	{
		bool ryunosukeOverFloor = false;
		//Check if ryunosuke is over the floor detected.
		if(a->getCollisionBitmask() == RYUNOSUKE_BITMASK)
		{
		    if((a->getPosition().y - this->nodeSprite->getContentSize().height/8) >= b->getPosition().y)
		    {
				this->onTheFloor = true;
		        ryunosukeOverFloor = true;
		    }
		}
		else
		{
		    if((b->getPosition().y - this->nodeSprite->getContentSize().height/8) >= a->getPosition().y)
		    {
				this->onTheFloor = true;
		        ryunosukeOverFloor = true;
		    }
		}
	    if (ryunosukeOverFloor)
	    {
            if (!this->rightMovement && !this->leftMovement)
            {
                this->nodeBody->setVelocity(cocos2d::Vec2(0.0, 0.0));
                if (this->mNextJump.try_lock()){
                    if (this->nextJump)
                    {
                        this->toJump(nextJumpVelocity);
                        this->nextJump = false;
                    }
                    this->mNextJump.unlock();
                }
            }
            else
            {
                this->nodeBody->setVelocity(cocos2d::Vec2(this->nodeBody->getVelocity().x, 0.0));
                if (this->mNextJump.try_lock()){
                    this->nextJump = false;
                    this->mNextJump.unlock();
                }
            }
		}
		else
		{
		    return false;
		}
	}
	else if ((a->getCollisionBitmask() == RYUNOSUKE_BITMASK && b->getCollisionBitmask() == RIGHT_OBSTACLE_BITMASK) || (a->getCollisionBitmask() == RIGHT_OBSTACLE_BITMASK && b->getCollisionBitmask() == RYUNOSUKE_BITMASK))
	{
		this->onTheRightWall = true;
		if (!this->rightMovement && !this->leftMovement)
		{
			this->nodeBody->setVelocity(cocos2d::Vec2(0.0, 0.0));
			if (this->mNextJump.try_lock()){
                if(this->nextJump)
                {
                    this->toJump(nextJumpVelocity);
                    this->nextJump = false;
                }
                this->mNextJump.unlock();
            }
		}
		else if (this->rightMovement)
		{
	        this->nodeBody->setVelocityLimit(RYUNOSUKE_WALL_SPEED);
			this->nodeBody->setVelocity(cocos2d::Vec2(0.0, 0.0));
			if (this->mNextJump.try_lock()){
                this->nextJump = false;
                this->mNextJump.unlock();
            }
		}
		else if (this->leftMovement)
		{
	        this->nodeBody->setVelocityLimit(RYUNOSUKE_WALL_SPEED);
			this->nodeBody->setVelocity(cocos2d::Vec2(0.0, 0.0));
			if (this->mNextJump.try_lock()){
                this->nextJump = false;
                this->mNextJump.unlock();
            }
		}
		else
		{

		}
	}
	else if ((a->getCollisionBitmask() == RYUNOSUKE_BITMASK && b->getCollisionBitmask() == LEFT_OBSTACLE_BITMASK) || (a->getCollisionBitmask() == LEFT_OBSTACLE_BITMASK && b->getCollisionBitmask() == RYUNOSUKE_BITMASK))
	{
		this->onTheLeftWall = true;
		if (!this->rightMovement && !this->leftMovement)
		{
			this->nodeBody->setVelocity(cocos2d::Vec2(0.0, 0.0));
			if (this->mNextJump.try_lock()){
                if(this->nextJump)
                {
                    this->toJump(nextJumpVelocity);
                    this->nextJump = false;
                }
                this->mNextJump.unlock();
            }
		}
		else if (this->rightMovement)
		{
	        this->nodeBody->setVelocityLimit(RYUNOSUKE_WALL_SPEED);
			this->nodeBody->setVelocity(cocos2d::Vec2(0.0, 0.0));
			if (this->mNextJump.try_lock()){
                this->nextJump = false;
                this->mNextJump.unlock();
            }
		}
		else if (this->leftMovement)
		{
	        this->nodeBody->setVelocityLimit(RYUNOSUKE_WALL_SPEED);
			this->nodeBody->setVelocity(cocos2d::Vec2(0.0, 0.0));
			if (this->mNextJump.try_lock()){
                this->nextJump = false;
                this->mNextJump.unlock();
            }
		}
		else
		{

		}
	}
	return true;
}

bool NinjaM::Ryunosuke::onContactSeparate(cocos2d::PhysicsContact &contact)
{
	cocos2d::PhysicsBody *a = contact.getShapeA()->getBody();
	cocos2d::PhysicsBody *b = contact.getShapeB()->getBody();

	if ((a->getCollisionBitmask() == RYUNOSUKE_BITMASK && b->getCollisionBitmask() == FLOOR_BITMASK) || (a->getCollisionBitmask() == FLOOR_BITMASK && b->getCollisionBitmask() == RYUNOSUKE_BITMASK))
	{
		this->onTheFloor = false;
	}
	else if ((a->getCollisionBitmask() == RYUNOSUKE_BITMASK && b->getCollisionBitmask() == RIGHT_OBSTACLE_BITMASK) || (a->getCollisionBitmask() == RIGHT_OBSTACLE_BITMASK && b->getCollisionBitmask() == RYUNOSUKE_BITMASK))
	{
		this->onTheRightWall = false;
        this->nodeBody->setVelocityLimit(cocos2d::PHYSICS_INFINITY);
	}
	else if ((a->getCollisionBitmask() == RYUNOSUKE_BITMASK && b->getCollisionBitmask() == LEFT_OBSTACLE_BITMASK) || (a->getCollisionBitmask() == LEFT_OBSTACLE_BITMASK && b->getCollisionBitmask() == RYUNOSUKE_BITMASK))
    {
    	this->onTheLeftWall = false;
        this->nodeBody->setVelocityLimit(cocos2d::PHYSICS_INFINITY);
    }
}