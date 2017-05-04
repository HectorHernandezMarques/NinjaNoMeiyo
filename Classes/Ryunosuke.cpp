//
// Created by AntonioMontana on 14/03/2017.
//

#include "./Ryunosuke.h"
#include <unistd.h>

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
	material.restitution = 0.7f;
	material.friction = 0.0f;
	this->nodeBody = cocos2d::PhysicsBody::createBox(this->nodeSprite->getContentSize(), material);
	this->nodeBody->setDynamic(true);
	this->nodeBody->setCollisionBitmask(0x000001);
	this->nodeBody->setContactTestBitmask(true);
	this->nodeBody->setRotationEnable(false);
    this->nodeSprite->setPhysicsBody(nodeBody);
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
	}
	else
	{
	    if (!this->onTheLeftWall)
	    {
		    this->leftMovement = true;
	        this->lastXVelocity = fabs(velocity);
	        this->nodeBody->setVelocity(cocos2d::Vec2(velocity, this->nodeBody->getVelocity().y));
	    }
	}

}

void NinjaM::Ryunosuke::toStop(float velocity)
{
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
			this->nodeBody->setVelocity(cocos2d::Vec2(-this->lastXVelocity, this->nodeBody->getVelocity().y));
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
			this->nodeBody->setVelocity(cocos2d::Vec2(this->lastXVelocity, this->nodeBody->getVelocity().y));
		}
	}
}

void NinjaM::Ryunosuke::toJump(float velocity)
{
	if (this->onTheFloor || this->onTheRightWall || this->onTheLeftWall)
	{
		this->onTheFloor = false;
		this->onTheRightWall = false;
		this->onTheLeftWall = false;
		getNodeSprite()->getPhysicsBody()->setVelocity(cocos2d::Vec2(velocity, 950));
	}
	else
	{
	    if (this->mNextJump.try_lock()){
	        CCLOG("DOBLESALTO");
	        this->nextJump = velocity;
	        //std::thread tJumpCleaner = std::thread(NinjaM::Ryunosuke::jumpCleaner, 500, this->jumpCounter);
	        //auto sJumpCleaner = cocos2d::Director::getInstance()->getScheduler();
            //sJumpCleaner->performFunctionInCocosThread(CC_CALLBACK_0(NinjaM::Ryunosuke::jumpCleaner, this, 500, ++this->jumpCounter));
            cocos2d::DelayTime *delayAction = cocos2d::DelayTime::create(0.25f);
            cocos2d::CallFunc *jumpCleanerAction = cocos2d::CallFunc::create(CC_CALLBACK_0(NinjaM::Ryunosuke::jumpCleaner, this, 500, ++this->jumpCounter));
            this->nodeSprite->runAction(cocos2d::Sequence::create(delayAction, jumpCleanerAction, nullptr));
	        this->mNextJump.unlock();
	    }
	}
}


void NinjaM::Ryunosuke::jumpCleaner(unsigned int dt, unsigned int jumpCounter)
{
	if (this->mNextJump.try_lock())
	{
	    if (jumpCounter == this->jumpCounter)
	    {
	        this->nextJump = 0.0;
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

	if ((a->getCollisionBitmask() == 0x000001 && b->getCollisionBitmask() == 0x000002) || (a->getCollisionBitmask() == 0x000002 && b->getCollisionBitmask() == 0x000001))
	{
		this->onTheFloor = true;
		if (!this->rightMovement && !this->leftMovement)
		{
			this->nodeBody->setVelocity(cocos2d::Vec2(0.0, 0.0));
			if (this->mNextJump.try_lock()){
                if (this->nextJump)
                {
                    this->toJump(nextJump);
                    this->nextJump = 0.0;
                }
                this->mNextJump.unlock();
            }
		}
		else
		{
			this->nodeBody->setVelocity(cocos2d::Vec2(this->nodeBody->getVelocity().x, 0.0));
			if (this->mNextJump.try_lock()){
                this->nextJump = 0.0;
                this->mNextJump.unlock();
            }
		}
	}
	else if ((a->getCollisionBitmask() == 0x000001 && b->getCollisionBitmask() == 0x000003) || (a->getCollisionBitmask() == 0x000001 && b->getCollisionBitmask() == 0x000003))
	{
		this->onTheRightWall = true;
		if (!this->rightMovement && !this->leftMovement)
		{
			this->nodeBody->setVelocity(cocos2d::Vec2(0.0, 0.0));
			if (this->mNextJump.try_lock()){
                if(this->nextJump)
                {
                    this->toJump(nextJump);
                    this->nextJump = 0.0;
                }
                this->mNextJump.unlock();
            }
		}
		else
		{
			this->nodeBody->setVelocity(cocos2d::Vec2(0.0, this->nodeBody->getVelocity().y));
			if (this->mNextJump.try_lock()){
                this->nextJump = 0.0;
                this->mNextJump.unlock();
            }
		}
	}
	else if ((a->getCollisionBitmask() == 0x000001 && b->getCollisionBitmask() == 0x000004) || (a->getCollisionBitmask() == 0x000001 && b->getCollisionBitmask() == 0x000004))
	{
		this->onTheLeftWall = true;
		if (!this->rightMovement && !this->leftMovement)
		{
			this->nodeBody->setVelocity(cocos2d::Vec2(0.0, 0.0));
			if (this->mNextJump.try_lock()){
                if(this->nextJump)
                {
                    this->toJump(nextJump);
                    this->nextJump = 0.0;
                }
                this->mNextJump.unlock();
            }
		}
		else
		{
			this->nodeBody->setVelocity(cocos2d::Vec2(0.0, 0.0));
			if (this->mNextJump.try_lock()){
                this->nextJump = 0.0;
                this->mNextJump.unlock();
            }
		}
	}
	return true;
}

bool NinjaM::Ryunosuke::onContactSeparate(cocos2d::PhysicsContact &contact)
{
	cocos2d::PhysicsBody *a = contact.getShapeA()->getBody();
	cocos2d::PhysicsBody *b = contact.getShapeB()->getBody();

	if ((a->getCollisionBitmask() == 0x000001 && b->getCollisionBitmask() == 0x000002) || (a->getCollisionBitmask() == 0x000002 && b->getCollisionBitmask()== 0x000001))
	{
		this->onTheFloor = false;
	}
	else if ((a->getCollisionBitmask() == 0x000001 && b->getCollisionBitmask() == 0x000003) || (a->getCollisionBitmask() == 0x000003 && b->getCollisionBitmask() == 0x000001))
	{
		this->onTheRightWall = false;
	}
	else if ((a->getCollisionBitmask() == 0x000001 && b->getCollisionBitmask() == 0x000004) || (a->getCollisionBitmask() == 0x000004 && b->getCollisionBitmask() == 0x000001))
    	{
    		this->onTheLeftWall = false;
    	}
}