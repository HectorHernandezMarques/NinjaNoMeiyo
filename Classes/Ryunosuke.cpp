//
// Created by AntonioMontana on 14/03/2017.
//

#include <unistd.h>
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

void NinjaM::Ryunosuke::toMove(float velocity)
{
	if (velocity>0.0)
	{
		mWallDetection.lock();
	    if (!this->onTheRightWall && !this->onTheEdgeRightWall)
	    {
		    this->rightMovement = true;
	        this->lastXVelocity = fabs(velocity);
	        this->nodeBody->setVelocity(cocos2d::Vec2(velocity, this->nodeBody->getVelocity().y));
			CCLOG("(toMove) Right Move -- Not in wall");
	    }
	    else if (!this->onTheFloor && !this->onTheEdgeFloor)
	    {
	        //Holding wall position
		    this->rightMovement = true;
	        this->lastXVelocity = fabs(velocity);
	        this->nodeBody->setVelocityLimit(RYUNOSUKE_WALL_SPEED);
	        this->nodeBody->setVelocity(cocos2d::Vec2(0.0, 0.0));
			CCLOG("(toMove) Right Move -- In wall Not in Floor");
	    }
		else if (this->onTheEdgeRightWall && this->onTheEdgeFloor)
		{	//       |x|
			// | |o|o|x|
			// | |o|o|
			// | | | |
			if (this->rightEdgeWallPosition.y < (this->nodeSprite->getPosition().y - this->nodeSprite->getContentSize().height / 2))
			{
				this->rightMovement = true;
				this->lastXVelocity = fabs(velocity);
				this->nodeBody->setVelocity(cocos2d::Vec2(velocity, this->nodeBody->getVelocity().y));
				CCLOG("(toMove) Right Move -- In Edge wall and Edge floor and OVER center of Edge Wall");
				//DIFERENCIATE BETWEEN OVER FLOOR AND NOT OVER FLOOR.
			}
			else
			{
				//Holding wall position
				this->rightMovement = true;
				this->lastXVelocity = fabs(velocity);
				this->nodeBody->setVelocityLimit(RYUNOSUKE_WALL_SPEED);
				this->nodeBody->setVelocity(cocos2d::Vec2(0.0, 0.0));
				CCLOG("(toMove) Right Move -- In Ege wall and Edge floor and UNDER center of Edge Wall");
			}
		}
		mWallDetection.unlock();
		this->nodeSprite->setTexture("Ryunosuke1D.png");
	}
	else
	{
		mWallDetection.lock();
	    if (!this->onTheLeftWall && !this->onTheEdgeLeftWall)
	    {
		    this->leftMovement = true;
	        this->lastXVelocity = fabs(velocity);
	        this->nodeBody->setVelocity(cocos2d::Vec2(velocity, this->nodeBody->getVelocity().y));
			CCLOG("(toMove) Left Move -- Not in wall");
	    }
	    else if (!this->onTheFloor && !this->onTheEdgeFloor)
	    {
	        //Holding wall position
		    this->leftMovement = true;
		    this->lastXVelocity = fabs(velocity);
	        this->nodeBody->setVelocityLimit(RYUNOSUKE_WALL_SPEED);
	        this->nodeBody->setVelocity(cocos2d::Vec2(0.0, 0.0));
			CCLOG("(toMove) Left Move -- In wall Not in Floor");
	    }
		else if (this->onTheEdgeLeftWall && this->onTheEdgeFloor)
		{	// |x|
			// |x|| |o|o|
			//    | |o|o|
			//    | | | |
			if (this->leftEdgeWallPosition.y < (this->nodeSprite->getPosition().y - this->nodeSprite->getContentSize().height / 2))
			{
				this->leftMovement = true;
				this->lastXVelocity = fabs(velocity);
				this->nodeBody->setVelocity(cocos2d::Vec2(velocity, this->nodeBody->getVelocity().y));
				CCLOG("(toMove) Left Move -- In Edge wall and Edge floor and OVER center of Edge Wall");
				//DIFERENCIATE BETWEEN OVER FLOOR AND NOT OVER FLOOR.
			}
			else
			{
				//Holding wall position
				this->leftMovement = true;
				this->lastXVelocity = fabs(velocity);
				this->nodeBody->setVelocityLimit(RYUNOSUKE_WALL_SPEED);
				this->nodeBody->setVelocity(cocos2d::Vec2(0.0, 0.0));
				CCLOG("(toMove) Left Move -- In Ege wall and Edge floor and UNDER center of Edge Wall");
			}
		}	
		mWallDetection.unlock();
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
			if (this->onTheFloor || this->onTheEdgeFloor)
			{
				this->nodeBody->setVelocity(cocos2d::Vec2(0.0, this->nodeBody->getVelocity().y));
				CCLOG("(toStop) From Right -- On the floor");
			}
			else
			{
				CCLOG("(toStop) From Right -- On the air");
			}
		}
		else
		{
		    this->toMove(-this->lastXVelocity);
			CCLOG("(toStop) From Right -- BackMovement");
		}
	}
	else
	{
		this->leftMovement = false;
		if (!this->rightMovement)
		{
			if (this->onTheFloor || this->onTheEdgeFloor)
			{
				this->nodeBody->setVelocity(cocos2d::Vec2(0.0, this->nodeBody->getVelocity().y));
				CCLOG("(toStop) From Left -- On the floor");
			}
			else
			{
				CCLOG("(toStop) From Left -- On the air");
			}
		}
		else
		{
		    this->toMove(this->lastXVelocity);
			CCLOG("(toStop) From Left -- BackMovement");
		}
	}
}

void NinjaM::Ryunosuke::toJump(float velocity)
{
	if (this->onTheFloor || this->onTheEdgeFloor)
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
		CCLOG("(toJump) On the floor");
	}
	else if(this->onTheRightWall || this->onTheEdgeRightWall)
	{
	    this->nodeBody->setVelocityLimit(cocos2d::PHYSICS_INFINITY);
		if (velocity >= 0.0)
		{
			getNodeSprite()->getPhysicsBody()->setVelocity(cocos2d::Vec2(0.0, RYUNOSUKE_JUMP_ON_WALL));
			this->nodeSprite->setTexture("Ryunosuke1D.png");
		}
		else if (velocity < 0.0)
		{
			getNodeSprite()->getPhysicsBody()->setVelocity(cocos2d::Vec2(velocity, RYUNOSUKE_JUMP_ON_WALL));
			this->nodeSprite->setTexture("Ryunosuke1I.png");
		}
		CCLOG("(toJump) On the right wall");
	}
	else if (this->onTheLeftWall || this->onTheEdgeLeftWall)
	{
		this->nodeBody->setVelocityLimit(cocos2d::PHYSICS_INFINITY);
		if (velocity > 0.0)
		{
			getNodeSprite()->getPhysicsBody()->setVelocity(cocos2d::Vec2(velocity, RYUNOSUKE_JUMP_ON_WALL));
			this->nodeSprite->setTexture("Ryunosuke1D.png");
		}
		else if (velocity <= 0.0)
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
		CCLOG("(toJump) On the air");
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
		/*
		bool ryunosukeOverFloor = false
		//Check if ryunosuke is over the floor detected.
		if(a->getCollisionBitmask() == RYUNOSUKE_BITMASK)
		{
		    if((a->getPosition().y) >= b->getPosition().y)
		    {
		        ryunosukeOverFloor = true;
		    }
		}
		else
		{
		    if((b->getPosition().y) >= a->getPosition().y)
		    {
				this->onTheFloor = true;
		        ryunosukeOverFloor = true;
		    }
		}*/

		CCLOG("Floor collision");
		this->onTheFloor = true;
		this->nodeBody->setVelocityLimit(cocos2d::PHYSICS_INFINITY);
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
		else if (this->rightMovement)
		{
			this->toMove(RYUNOSUKE_SPEED);
			if (this->mNextJump.try_lock()) {
				this->nextJump = false;
				this->mNextJump.unlock();
			}
		}
		else if (this->leftMovement)
		{
			this->toMove(-RYUNOSUKE_SPEED);
			if (this->mNextJump.try_lock()) {
				this->nextJump = false;
				this->mNextJump.unlock();
			}
		}
	}
	else if ((a->getCollisionBitmask() == RYUNOSUKE_BITMASK && b->getCollisionBitmask() == RIGHT_OBSTACLE_BITMASK) || (a->getCollisionBitmask() == RIGHT_OBSTACLE_BITMASK && b->getCollisionBitmask() == RYUNOSUKE_BITMASK))
	{
		mWallDetection.lock();
		this->onTheRightWall = true;
		cocos2d::Vec2 currentRyunosukePosition;
		if (a->getCollisionBitmask() == RYUNOSUKE_BITMASK)
		{
			this->rightEdgeWallPosition = b->getLinkedSprite()->getPosition();
			currentRyunosukePosition = a->getLinkedSprite()->getPosition();
		}
		else
		{
			this->rightEdgeWallPosition = a->getLinkedSprite()->getPosition();
			currentRyunosukePosition = b->getLinkedSprite()->getPosition();
		}
		mWallDetection.unlock();

		if (!this->onTheFloor)
		{
			if (!this->rightMovement && !this->leftMovement)
			{
				this->nodeBody->setVelocity(cocos2d::Vec2(0.0, 0.0));
				if (this->mNextJump.try_lock()) {
					if (this->nextJump)
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
				if (this->mNextJump.try_lock()) {
					this->nextJump = false;
					this->mNextJump.unlock();
				}
			}
			else if (this->leftMovement)
			{
				this->nodeBody->setVelocityLimit(RYUNOSUKE_WALL_SPEED);
				this->nodeBody->setVelocity(cocos2d::Vec2(0.0, 0.0));
				if (this->mNextJump.try_lock()) {
					this->nextJump = false;
					this->mNextJump.unlock();
				}
			}
			else
			{
				this->nodeBody->setVelocityLimit(RYUNOSUKE_WALL_SPEED);
				this->nodeBody->setVelocity(cocos2d::Vec2(0.0, 0.0));
				if (this->mNextJump.try_lock()) {
					this->nextJump = false;
					this->mNextJump.unlock();
				}
			}
			CCLOG("Right Wall collision - Not on the floor");
		}
		else
		{
			CCLOG("Right Wall collision - On the floor");
			return true;
		}

	}
	else if ((a->getCollisionBitmask() == RYUNOSUKE_BITMASK && b->getCollisionBitmask() == LEFT_OBSTACLE_BITMASK) || (a->getCollisionBitmask() == LEFT_OBSTACLE_BITMASK && b->getCollisionBitmask() == RYUNOSUKE_BITMASK))
	{
		mWallDetection.lock();
		this->onTheLeftWall = true;
		cocos2d::Vec2 currentRyunosukePosition;
		if (a->getCollisionBitmask() == RYUNOSUKE_BITMASK)
		{
			this->leftEdgeWallPosition = b->getLinkedSprite()->getPosition();
			currentRyunosukePosition = a->getLinkedSprite()->getPosition();
		}
		else
		{
			this->leftEdgeWallPosition = a->getLinkedSprite()->getPosition();
			currentRyunosukePosition = b->getLinkedSprite()->getPosition();
		}
		mWallDetection.unlock();

		if (!this->onTheFloor)
		{
			if (!this->rightMovement && !this->leftMovement)
			{
				this->nodeBody->setVelocity(cocos2d::Vec2(0.0, 0.0));
				if (this->mNextJump.try_lock()) {
					if (this->nextJump)
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
				if (this->mNextJump.try_lock()) {
					this->nextJump = false;
					this->mNextJump.unlock();
				}
			}
			else if (this->leftMovement)
			{
				this->nodeBody->setVelocityLimit(RYUNOSUKE_WALL_SPEED);
				this->nodeBody->setVelocity(cocos2d::Vec2(0.0, 0.0));
				if (this->mNextJump.try_lock()) {
					this->nextJump = false;
					this->mNextJump.unlock();
				}
			}
			else
			{
				this->nodeBody->setVelocityLimit(RYUNOSUKE_WALL_SPEED);
				this->nodeBody->setVelocity(cocos2d::Vec2(0.0, 0.0));
				if (this->mNextJump.try_lock()) {
					this->nextJump = false;
					this->mNextJump.unlock();
				}
			}
			CCLOG("Left Wall collision - Not on the floor");
		}
		else
		{
			this->nodeBody->setVelocity(cocos2d::Vec2(0.0, 0.0));
			CCLOG("Left Wall collision - On the floor");
			return true;
		}
	}
	else if ((a->getCollisionBitmask() == RYUNOSUKE_BITMASK && b->getCollisionBitmask() == EDGE_FLOOR_BITMASK) || (a->getCollisionBitmask() == EDGE_FLOOR_BITMASK && b->getCollisionBitmask() == RYUNOSUKE_BITMASK))
	{
		this->onTheEdgeFloor = true;
		bool ryunosukeOverFloor = false;
		//Check if ryunosuke is over the floor detected.
		if(a->getCollisionBitmask() == RYUNOSUKE_BITMASK)
		{
			if((a->getLinkedSprite()->getPosition().y + this->nodeSprite->getContentSize().height/2) >= b->getLinkedSprite()->getPosition().y)
			{
				this->onTheEdgeFloor = true;
				ryunosukeOverFloor = true;
			}
		}
		else
		{
			if((b->getLinkedSprite()->getPosition().y + this->nodeSprite->getContentSize().height/2) >= a->getLinkedSprite()->getPosition().y)
			{
				this->onTheEdgeFloor = true;
				ryunosukeOverFloor = true;
			}
		}
		CCLOG("Edge Floor collision");
		if (ryunosukeOverFloor)
		{
			this->nodeBody->setVelocityLimit(cocos2d::PHYSICS_INFINITY);
			if (!this->rightMovement && !this->leftMovement)
			{
				this->nodeBody->setVelocity(cocos2d::Vec2(0.0, 0.0));
				if (this->mNextJump.try_lock()) {
					if (this->nextJump)
					{
						this->toJump(nextJumpVelocity);
						this->nextJump = false;
					}
					this->mNextJump.unlock();
				}
			}
			else if (this->rightMovement)
			{
				this->toMove(RYUNOSUKE_SPEED);
				if (this->mNextJump.try_lock()) {
					this->nextJump = false;
					this->mNextJump.unlock();
				}
			}
			else if (this->leftMovement)
			{
				this->toMove(-RYUNOSUKE_SPEED);
				if (this->mNextJump.try_lock()) {
					this->nextJump = false;
					this->mNextJump.unlock();
				}
			}
		}
	}
	else if ((a->getCollisionBitmask() == RYUNOSUKE_BITMASK && b->getCollisionBitmask() == EDGE_RIGHT_OBSTACLE_BITMASK) || (a->getCollisionBitmask() == EDGE_RIGHT_OBSTACLE_BITMASK && b->getCollisionBitmask() == RYUNOSUKE_BITMASK))
	{
		mWallDetection.lock();
		this->onTheEdgeRightWall = true;
		cocos2d::Vec2 currentRyunosukePosition;
		if (a->getCollisionBitmask() == RYUNOSUKE_BITMASK)
		{
			this->rightEdgeWallPosition = b->getLinkedSprite()->getPosition();
			currentRyunosukePosition = a->getLinkedSprite()->getPosition();
		}
		else
		{
			this->rightEdgeWallPosition = a->getLinkedSprite()->getPosition();
			currentRyunosukePosition = b->getLinkedSprite()->getPosition();
		}
		mWallDetection.unlock();

		if (!this->onTheFloor && !this->onTheEdgeFloor)
		{
			if (!this->rightMovement && !this->leftMovement)
			{
				this->nodeBody->setVelocity(cocos2d::Vec2(0.0, 0.0));
				if (this->mNextJump.try_lock()) {
					if (this->nextJump)
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
				if (this->mNextJump.try_lock()) {
					this->nextJump = false;
					this->mNextJump.unlock();
				}
			}
			else if (this->leftMovement)
			{
				this->nodeBody->setVelocityLimit(RYUNOSUKE_WALL_SPEED);
				this->nodeBody->setVelocity(cocos2d::Vec2(0.0, 0.0));
				if (this->mNextJump.try_lock()) {
					this->nextJump = false;
					this->mNextJump.unlock();
				}
			}
			else
			{
				this->nodeBody->setVelocityLimit(RYUNOSUKE_WALL_SPEED);
				this->nodeBody->setVelocity(cocos2d::Vec2(0.0, 0.0));
				if (this->mNextJump.try_lock()) {
					this->nextJump = false;
					this->mNextJump.unlock();
				}
			}
			CCLOG("Right Wall collision - Not on the floor");
		}
		else if (this->rightEdgeWallPosition.y > (currentRyunosukePosition.y - this->nodeSprite->getContentSize().height / 2))
		{
			if (!this->rightMovement && !this->leftMovement)
			{
				this->nodeBody->setVelocity(cocos2d::Vec2(0.0, 0.0));
				if (this->mNextJump.try_lock()) {
					if (this->nextJump)
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
				if (this->mNextJump.try_lock()) {
					this->nextJump = false;
					this->mNextJump.unlock();
				}
			}
			else if (this->leftMovement)
			{
				this->nodeBody->setVelocityLimit(RYUNOSUKE_WALL_SPEED);
				this->nodeBody->setVelocity(cocos2d::Vec2(0.0, 0.0));
				if (this->mNextJump.try_lock()) {
					this->nextJump = false;
					this->mNextJump.unlock();
				}
			}
			else
			{
				this->nodeBody->setVelocityLimit(RYUNOSUKE_WALL_SPEED);
				this->nodeBody->setVelocity(cocos2d::Vec2(0.0, 0.0));
				if (this->mNextJump.try_lock()) {
					this->nextJump = false;
					this->mNextJump.unlock();
				}
			}
			CCLOG("Right Wall collision - In the floor and base of Ryunosuke UNDER center of the Right Wall");
		}
		else
		{
			CCLOG("Right Wall collision - In the floor and base of Ryunosuke OVER center of the Right Wall");
			return false;
		}
	}
	else if ((a->getCollisionBitmask() == RYUNOSUKE_BITMASK && b->getCollisionBitmask() == EDGE_LEFT_OBSTACLE_BITMASK) || (a->getCollisionBitmask() == EDGE_LEFT_OBSTACLE_BITMASK && b->getCollisionBitmask() == RYUNOSUKE_BITMASK))
	{
		mWallDetection.lock();
		this->onTheEdgeLeftWall = true;
		cocos2d::Vec2 currentRyunosukePosition;
		if (a->getCollisionBitmask() == RYUNOSUKE_BITMASK)
		{
			this->leftEdgeWallPosition = b->getLinkedSprite()->getPosition();
			currentRyunosukePosition = a->getLinkedSprite()->getPosition();
		}
		else
		{
			this->leftEdgeWallPosition = a->getLinkedSprite()->getPosition();
			currentRyunosukePosition = b->getLinkedSprite()->getPosition();
		}
		mWallDetection.unlock();

		if (!this->onTheFloor && !this->onTheEdgeFloor)
		{
			if (!this->rightMovement && !this->leftMovement)
			{
				this->nodeBody->setVelocity(cocos2d::Vec2(0.0, 0.0));
				if (this->mNextJump.try_lock()) {
					if (this->nextJump)
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
				if (this->mNextJump.try_lock()) {
					this->nextJump = false;
					this->mNextJump.unlock();
				}
			}
			else if (this->leftMovement)
			{
				this->nodeBody->setVelocityLimit(RYUNOSUKE_WALL_SPEED);
				this->nodeBody->setVelocity(cocos2d::Vec2(0.0, 0.0));
				if (this->mNextJump.try_lock()) {
					this->nextJump = false;
					this->mNextJump.unlock();
				}
			}
			else
			{
				this->nodeBody->setVelocityLimit(RYUNOSUKE_WALL_SPEED);
				this->nodeBody->setVelocity(cocos2d::Vec2(0.0, 0.0));
				if (this->mNextJump.try_lock()) {
					this->nextJump = false;
					this->mNextJump.unlock();
				}
			}
			CCLOG("Left Wall collision - Not on the floor");
		}
		else if (this->leftEdgeWallPosition.y > (currentRyunosukePosition.y - this->nodeSprite->getContentSize().height / 2))
		{
			if (!this->rightMovement && !this->leftMovement)
			{
				this->nodeBody->setVelocity(cocos2d::Vec2(0.0, 0.0));
				if (this->mNextJump.try_lock()) {
					if (this->nextJump)
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
				if (this->mNextJump.try_lock()) {
					this->nextJump = false;
					this->mNextJump.unlock();
				}
			}
			else if (this->leftMovement)
			{
				this->nodeBody->setVelocityLimit(RYUNOSUKE_WALL_SPEED);
				this->nodeBody->setVelocity(cocos2d::Vec2(0.0, 0.0));
				if (this->mNextJump.try_lock()) {
					this->nextJump = false;
					this->mNextJump.unlock();
				}
			}
			else
			{
				this->nodeBody->setVelocityLimit(RYUNOSUKE_WALL_SPEED);
				this->nodeBody->setVelocity(cocos2d::Vec2(0.0, 0.0));
				if (this->mNextJump.try_lock()) {
					this->nextJump = false;
					this->mNextJump.unlock();
				}
			}
			CCLOG("Left Wall collision - In the floor and base of Ryunosuke UNDER center of the Left Wall");
		}
		else
		{
			CCLOG("Left Wall collision - In the floor and base of Ryunosuke OVER center of the Left Wall");
			return false;
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
		CCLOG("Floor Separation");
	}
	else if ((a->getCollisionBitmask() == RYUNOSUKE_BITMASK && b->getCollisionBitmask() == RIGHT_OBSTACLE_BITMASK) || (a->getCollisionBitmask() == RIGHT_OBSTACLE_BITMASK && b->getCollisionBitmask() == RYUNOSUKE_BITMASK))
	{
		this->onTheRightWall = false;
        this->nodeBody->setVelocityLimit(cocos2d::PHYSICS_INFINITY);
		CCLOG("Right Wall Separation");
	}
	else if ((a->getCollisionBitmask() == RYUNOSUKE_BITMASK && b->getCollisionBitmask() == LEFT_OBSTACLE_BITMASK) || (a->getCollisionBitmask() == LEFT_OBSTACLE_BITMASK && b->getCollisionBitmask() == RYUNOSUKE_BITMASK))
    {
    	this->onTheLeftWall = false;
        this->nodeBody->setVelocityLimit(cocos2d::PHYSICS_INFINITY);
		CCLOG("Left Wall Separation");
    }
	else if ((a->getCollisionBitmask() == RYUNOSUKE_BITMASK && b->getCollisionBitmask() == EDGE_FLOOR_BITMASK) || (a->getCollisionBitmask() == EDGE_FLOOR_BITMASK && b->getCollisionBitmask() == RYUNOSUKE_BITMASK))
	{
		this->onTheEdgeFloor = false;
		CCLOG("Edge Floor Separation");
	}
	else if ((a->getCollisionBitmask() == RYUNOSUKE_BITMASK && b->getCollisionBitmask() == EDGE_RIGHT_OBSTACLE_BITMASK) || (a->getCollisionBitmask() == EDGE_RIGHT_OBSTACLE_BITMASK && b->getCollisionBitmask() == RYUNOSUKE_BITMASK))
	{
		this->onTheRightWall = false;
        this->nodeBody->setVelocityLimit(cocos2d::PHYSICS_INFINITY);
		CCLOG("Edge Right Wall Separation");
	}
	else if ((a->getCollisionBitmask() == RYUNOSUKE_BITMASK && b->getCollisionBitmask() == EDGE_LEFT_OBSTACLE_BITMASK) || (a->getCollisionBitmask() == EDGE_LEFT_OBSTACLE_BITMASK && b->getCollisionBitmask() == RYUNOSUKE_BITMASK))
	{
    	this->onTheLeftWall = false;
        this->nodeBody->setVelocityLimit(cocos2d::PHYSICS_INFINITY);
		CCLOG("Edge Left Wall Separation");
	}
}