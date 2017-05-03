//
// Created by AntonioMontana on 14/03/2017.
//

#include "./Ryunosuke.h"

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
    this->nodeSprite->setPhysicsBody(nodeBody);
}

void NinjaM::Ryunosuke::toMove(float velocity) {
	if(velocity>0.0)
	{
		this->rightMovement = true;
	}
	else
	{
		this->leftMovement = true;
	}
	
	this->lastXVelocity = fabs(velocity);
	this->nodeBody->setVelocity(cocos2d::Vec2(velocity, this->nodeBody->getVelocity().y));
}

void NinjaM::Ryunosuke::toStop(float velocity) {
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
	if (this->onTheFloor || this->onTheWall)
	{
		this->onTheFloor = false;
		this->onTheWall = false;
		getNodeSprite()->getPhysicsBody()->setVelocity(cocos2d::Vec2(velocity*0.75, 900));
	}
	else if (!this->nextJump)
	{
	    nextJump = velocity;
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
			if(this->nextJump)
			{
			    this->toJump(nextJump);
			    this->nextJump = 0.0;
			}
		}
		else
		{
			this->nodeBody->setVelocity(cocos2d::Vec2(this->nodeBody->getVelocity().x, 0.0));
		}
	}
	else if ((a->getCollisionBitmask() == 0x000001 && b->getCollisionBitmask() == 0x000003) || (a->getCollisionBitmask() == 0x000001 && b->getCollisionBitmask() == 0x000003))
	{
		this->onTheWall = true;
		if (!this->rightMovement && !this->leftMovement)
		{
			this->nodeBody->setVelocity(cocos2d::Vec2(0.0, 0.0));
			if(this->nextJump)
			{
			    this->toJump(nextJump);
			    this->nextJump = 0.0;
			}
		}
		else
		{
			this->nodeBody->setVelocity(cocos2d::Vec2(0.0, this->nodeBody->getVelocity().y));
		}
	}
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
		this->onTheWall = false;
	}
}