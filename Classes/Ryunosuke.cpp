//
// Created by AntonioMontana on 14/03/2017.
//

#include <unistd.h>
#include "./Ryunosuke.h"

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

void NinjaM::Ryunosuke::toMove(float velocity)
{
	if (velocity>0.0)
	{
		mWallDetection.lock();
		mJumpTrigger.lock();
	    if (!this->onTheRightWall && !this->onTheEdgeRightWall)
	    {
		    mJumpTrigger.unlock();
		    this->rightMovement = true;
		    this->nodeBody->setVelocityLimit(cocos2d::PHYSICS_INFINITY);
	        this->lastXVelocity = fabs(velocity);
	        this->nodeBody->setVelocity(cocos2d::Vec2(velocity, this->nodeBody->getVelocity().y));
			CCLOG("(toMove) Right Move -- Not in wall");
	    }
	    else if (!this->onTheFloor && !this->onTheEdgeFloor)
	    {
		    mJumpTrigger.unlock();
	        //Holding wall position
		    this->rightMovement = true;
	        this->lastXVelocity = fabs(velocity);
	        this->nodeBody->setVelocityLimit(RYUNOSUKE_WALL_SPEED);
	        this->nodeBody->setVelocity(cocos2d::Vec2(0.0, 0.0));
			CCLOG("(toMove) Right Move -- In wall Not in Floor");
	    }
		else if (this->onTheEdgeRightWall && this->onTheEdgeFloor)
		{
		    mJumpTrigger.unlock();
			//    |x|
			//    |x|
			//    |\| | |
			//    | |\| |
			//    | | | |
			if (fabs((this->nodeSprite->getPosition().x + this->nodeSprite->getContentSize().width/2) - (this->edgeFloorNode->getPosition().x + this->boxSize.width/2)) < fabs(this->nodeSprite->getPosition().y - (this->edgeFloorNode->getPosition().y - this->boxSize.height)))
			{
                this->rightMovement = true;
                this->nodeBody->setVelocityLimit(cocos2d::PHYSICS_INFINITY);
                this->lastXVelocity = fabs(velocity);
                this->nodeBody->setVelocity(cocos2d::Vec2(velocity, this->nodeBody->getVelocity().y));
				CCLOG("(toMove) Right Move -- In Edge wall and Edge floor and OVER");
				//DIFERENCIATE BETWEEN OVER FLOOR AND NOT OVER FLOOR.
			}
			else
			{
                //Holding wall position
                this->rightMovement = true;
                this->lastXVelocity = fabs(velocity);
                this->nodeBody->setVelocityLimit(RYUNOSUKE_WALL_SPEED);
                this->nodeBody->setVelocity(cocos2d::Vec2(0.0, 0.0));
				CCLOG("(toMove) Right Move -- In Ege wall and Edge floor and UNDER");
			}
		}
		mJumpTrigger.unlock();
		mWallDetection.unlock();
		this->nodeSprite->setTexture("Ryunosuke1D.png");
	}
	else
	{
		mWallDetection.lock();
		mJumpTrigger.lock();
	    if (!this->onTheLeftWall && !this->onTheEdgeLeftWall)
	    {
		    mJumpTrigger.unlock();
		    this->leftMovement = true;
		    this->nodeBody->setVelocityLimit(cocos2d::PHYSICS_INFINITY);
	        this->lastXVelocity = fabs(velocity);
	        this->nodeBody->setVelocity(cocos2d::Vec2(velocity, this->nodeBody->getVelocity().y));
			CCLOG("(toMove) Left Move -- Not in wall");
	    }
	    else if (!this->onTheFloor && !this->onTheEdgeFloor)
	    {
		    mJumpTrigger.unlock();
	        //Holding wall position
		    this->leftMovement = true;
		    this->lastXVelocity = fabs(velocity);
	        this->nodeBody->setVelocityLimit(RYUNOSUKE_WALL_SPEED);
	        this->nodeBody->setVelocity(cocos2d::Vec2(0.0, 0.0));
			CCLOG("(toMove) Left Move -- In wall Not in Floor");
	    }
		else if (this->onTheEdgeLeftWall && this->onTheEdgeFloor)
		{
		    mJumpTrigger.unlock();
			//     |x|
			//     |x|
			// | | |/|
			// | |/| |
			// | | | |
			if (fabs(this->nodeSprite->getPosition().x - (this->edgeFloorNode->getPosition().x - this->boxSize.width/2)) < fabs(this->nodeSprite->getPosition().y - (this->edgeFloorNode->getPosition().y - this->boxSize.height)))
			{
                this->leftMovement = true;
                this->nodeBody->setVelocityLimit(cocos2d::PHYSICS_INFINITY);
                this->lastXVelocity = fabs(velocity);
                this->nodeBody->setVelocity(cocos2d::Vec2(velocity, this->nodeBody->getVelocity().y));
				CCLOG("(toMove) Left Move -- In Edge wall and Edge floor and OVER");
				//DIFERENCIATE BETWEEN OVER FLOOR AND NOT OVER FLOOR.
			}
			else
			{
                //Holding wall position
                this->leftMovement = true;
                this->lastXVelocity = fabs(velocity);
                this->nodeBody->setVelocityLimit(RYUNOSUKE_WALL_SPEED);
                this->nodeBody->setVelocity(cocos2d::Vec2(0.0, 0.0));
				CCLOG("(toMove) Left Move -- In Ege wall and Edge floor and UNDER");
			}
		}
		mJumpTrigger.unlock();
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
		    mJumpTrigger.lock();
			if (this->onTheFloor || this->onTheEdgeFloor)
			{
		        mJumpTrigger.unlock();
				this->nodeBody->setVelocity(cocos2d::Vec2(0.0, this->nodeBody->getVelocity().y));
				CCLOG("(toStop) From Right -- On the floor");
			}
			else
			{
		        mJumpTrigger.unlock();
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
		    mJumpTrigger.lock();
			if (this->onTheFloor || this->onTheEdgeFloor)
			{
		        mJumpTrigger.unlock();
				this->nodeBody->setVelocity(cocos2d::Vec2(0.0, this->nodeBody->getVelocity().y));
				CCLOG("(toStop) From Left -- On the floor");
			}
			else
			{
		        mJumpTrigger.unlock();
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
	mJumpTrigger.lock();
	if (this->onTheFloor || this->onTheEdgeFloor)
	{
	    mJumpTrigger.unlock();
	    //toStop() needs to know if ryunosuke is in the air in order to either stop or let him go

		mJumpTrigger.lock();
		this->onTheFloor = false;
		this->onTheEdgeFloor = false;
		mJumpTrigger.unlock();

		if (this->onTheRightWall || this->onTheEdgeRightWall)
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
			mJumpTrigger.unlock();
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
			CCLOG("(toJump) On the left wall");
		}
		else
		{
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
	}
	else if(this->onTheRightWall || this->onTheEdgeRightWall)
	{
		mJumpTrigger.unlock();
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
		mJumpTrigger.unlock();
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
		CCLOG("(toJump) On the left wall");
	}
	else
	{
		mJumpTrigger.unlock();
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
		this->onTheRightWall = true;
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
		}
		return true;
	}
	else if ((a->getCollisionBitmask() == RYUNOSUKE_BITMASK && b->getCollisionBitmask() == LEFT_OBSTACLE_BITMASK) || (a->getCollisionBitmask() == LEFT_OBSTACLE_BITMASK && b->getCollisionBitmask() == RYUNOSUKE_BITMASK))
	{
		this->onTheLeftWall = true;
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
		}
		return true;
	}
	else if ((a->getCollisionBitmask() == RYUNOSUKE_BITMASK && b->getCollisionBitmask() == EDGE_FLOOR_RIGHT_BITMASK) || (a->getCollisionBitmask() == EDGE_FLOOR_RIGHT_BITMASK && b->getCollisionBitmask() == RYUNOSUKE_BITMASK))
	{
		mWallDetection.lock();

		this->onTheEdgeFloor = true;

		cocos2d::Node *currentRyunosukeSprite;
		if (a->getCollisionBitmask() == RYUNOSUKE_BITMASK)
		{
			this->edgeFloorNode = b->getLinkedSprite();
			currentRyunosukeSprite = a->getLinkedSprite();
		}
		else
		{
			this->edgeFloorNode = a->getLinkedSprite();
			currentRyunosukeSprite = b->getLinkedSprite();
		}

		//Check if ryunosuke is over the floor detected.
        bool ryunosukeOverRightEdgeFloor = false;
        if (fabs((currentRyunosukeSprite->getPosition().x + this->nodeSprite->getContentSize().width) - (this->edgeFloorNode->getPosition().x + this->boxSize.width/2)) < fabs(currentRyunosukeSprite->getPosition().y - (this->edgeFloorNode->getPosition().y - this->boxSize.height)))
        {
            ryunosukeOverRightEdgeFloor = true;
        }

		CCLOG("Edge Right Floor collision");
		if (ryunosukeOverRightEdgeFloor)
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
				mWallDetection.unlock();
				this->toMove(RYUNOSUKE_SPEED);
				if (this->mNextJump.try_lock()) {
					this->nextJump = false;
					this->mNextJump.unlock();
				}
			}
			else if (this->leftMovement)
			{
				mWallDetection.unlock();
				this->toMove(-RYUNOSUKE_SPEED);
				if (this->mNextJump.try_lock()) {
					this->nextJump = false;
					this->mNextJump.unlock();
				}
			}
		}
		else
		{
		    mWallDetection.unlock();
		    return false;
		}
        mWallDetection.unlock();
	}
	else if ((a->getCollisionBitmask() == RYUNOSUKE_BITMASK && b->getCollisionBitmask() == EDGE_FLOOR_LEFT_BITMASK) || (a->getCollisionBitmask() == EDGE_FLOOR_LEFT_BITMASK && b->getCollisionBitmask() == RYUNOSUKE_BITMASK))
	{
		mWallDetection.lock();

		this->onTheEdgeFloor = true;

		cocos2d::Node *currentRyunosukeSprite;
		if (a->getCollisionBitmask() == RYUNOSUKE_BITMASK)
		{
			this->edgeFloorNode = b->getLinkedSprite();
			currentRyunosukeSprite = a->getLinkedSprite();
		}
		else
		{
			this->edgeFloorNode = a->getLinkedSprite();
			currentRyunosukeSprite = b->getLinkedSprite();
		}

		//Check if ryunosuke is over the floor detected.
        bool ryunosukeOverLeftEdgeFloor = false;
        if (fabs(currentRyunosukeSprite->getPosition().x - (this->edgeFloorNode->getPosition().x - this->boxSize.width/2)) < fabs(currentRyunosukeSprite->getPosition().y - (this->edgeFloorNode->getPosition().y - this->boxSize.height)))
        {
            ryunosukeOverLeftEdgeFloor = true;
        }

		CCLOG("Edge Left Floor collision");
		if (ryunosukeOverLeftEdgeFloor)
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
				mWallDetection.unlock();
				this->toMove(RYUNOSUKE_SPEED);
				if (this->mNextJump.try_lock()) {
					this->nextJump = false;
					this->mNextJump.unlock();
				}
			}
			else if (this->leftMovement)
			{
				mWallDetection.unlock();
				this->toMove(-RYUNOSUKE_SPEED);
				if (this->mNextJump.try_lock()) {
					this->nextJump = false;
					this->mNextJump.unlock();
				}
			}
		}
		else
		{
		    mWallDetection.unlock();
		    return false;
		}
        mWallDetection.unlock();
	}
	else if ((a->getCollisionBitmask() == RYUNOSUKE_BITMASK && b->getCollisionBitmask() == EDGE_RIGHT_OBSTACLE_BITMASK) || (a->getCollisionBitmask() == EDGE_RIGHT_OBSTACLE_BITMASK && b->getCollisionBitmask() == RYUNOSUKE_BITMASK))
	{
		mWallDetection.lock();

		this->onTheEdgeRightWall = true;

		cocos2d::Node *currentRyunosukeSprite;
		if (a->getCollisionBitmask() == RYUNOSUKE_BITMASK)
		{
			this->rightEdgeWallNode = b->getLinkedSprite();
			currentRyunosukeSprite = a->getLinkedSprite();
		}
		else
		{
			this->rightEdgeWallNode = a->getLinkedSprite();
			currentRyunosukeSprite = b->getLinkedSprite();
		}

		//Check if ryunosuke is over the floor detected.
        bool ryunosukeOverRightEdgeFloor = false;
        if (fabs((currentRyunosukeSprite->getPosition().x + this->nodeSprite->getContentSize().width) - (this->rightEdgeWallNode->getPosition().x + this->boxSize.width)) < fabs(currentRyunosukeSprite->getPosition().y - (this->rightEdgeWallNode->getPosition().y - this->boxSize.height/2)))
        {
            ryunosukeOverRightEdgeFloor = true;
        }

        if (!ryunosukeOverRightEdgeFloor)
        {
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
                    this->nodeBody->setVelocity(cocos2d::Vec2(0.0, this->nodeBody->getVelocity().y));
                    if (this->mNextJump.try_lock()) {
                        this->nextJump = false;
                        this->mNextJump.unlock();
                    }
                }
                else if (this->leftMovement)
                {
                    this->nodeBody->setVelocityLimit(RYUNOSUKE_WALL_SPEED);
                    this->nodeBody->setVelocity(cocos2d::Vec2(0.0, this->nodeBody->getVelocity().y));
                    if (this->mNextJump.try_lock()) {
                        this->nextJump = false;
                        this->mNextJump.unlock();
                    }
                }
                else
                {
                    this->nodeBody->setVelocityLimit(RYUNOSUKE_WALL_SPEED);
                    this->nodeBody->setVelocity(cocos2d::Vec2(0.0, this->nodeBody->getVelocity().y));
                    if (this->mNextJump.try_lock()) {
                        this->nextJump = false;
                        this->mNextJump.unlock();
                    }
                }
                CCLOG("Right Edge Wall collision - Not on the floor");
            }
            else
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
                CCLOG("Right Wall Edge collision - In the floor and base of Ryunosuke UNDER center of the Right Wall");
            }
        }
        else
        {
            CCLOG("Right Wall Edge collision - In the floor and base of Ryunosuke OVER center of the Right Wall");
            mWallDetection.unlock();
            return false;
        }
		mWallDetection.unlock();
	}
	else if ((a->getCollisionBitmask() == RYUNOSUKE_BITMASK && b->getCollisionBitmask() == EDGE_LEFT_OBSTACLE_BITMASK) || (a->getCollisionBitmask() == EDGE_LEFT_OBSTACLE_BITMASK && b->getCollisionBitmask() == RYUNOSUKE_BITMASK))
	{
		mWallDetection.lock();

		this->onTheEdgeLeftWall = true;

		cocos2d::Node *currentRyunosukeSprite;
		if (a->getCollisionBitmask() == RYUNOSUKE_BITMASK)
		{
			this->leftEdgeWallNode = b->getLinkedSprite();
			currentRyunosukeSprite = a->getLinkedSprite();
		}
		else
		{
			this->leftEdgeWallNode = a->getLinkedSprite();
			currentRyunosukeSprite = b->getLinkedSprite();
		}

		//Check if ryunosuke is over the floor detected.
        bool ryunosukeOverLeftEdgeFloor = false;
        if (fabs(currentRyunosukeSprite->getPosition().x - (this->leftEdgeWallNode->getPosition().x - this->boxSize.width)) < fabs(currentRyunosukeSprite->getPosition().y - (this->leftEdgeWallNode->getPosition().y - this->boxSize.height/2)))
        {
            ryunosukeOverLeftEdgeFloor = true;
        }

        if (!ryunosukeOverLeftEdgeFloor)
        {
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
                    this->nodeBody->setVelocity(cocos2d::Vec2(0.0, this->nodeBody->getVelocity().y));//
                    if (this->mNextJump.try_lock()) {
                        this->nextJump = false;
                        this->mNextJump.unlock();
                    }
                }
                else if (this->leftMovement)
                {
                    this->nodeBody->setVelocityLimit(RYUNOSUKE_WALL_SPEED);
                    this->nodeBody->setVelocity(cocos2d::Vec2(0.0, this->nodeBody->getVelocity().y));//
                    if (this->mNextJump.try_lock()) {
                        this->nextJump = false;
                        this->mNextJump.unlock();
                    }
                }
                else
                {
                    this->nodeBody->setVelocityLimit(RYUNOSUKE_WALL_SPEED);
                    this->nodeBody->setVelocity(cocos2d::Vec2(0.0, this->nodeBody->getVelocity().y));//
                    if (this->mNextJump.try_lock()) {
                        this->nextJump = false;
                        this->mNextJump.unlock();
                    }
                }
                CCLOG("Left Wall Edge collision - Not on the floor");
            }
            else
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
                    this->nodeBody->setVelocity(cocos2d::Vec2(0.0, 0.0));//
                    if (this->mNextJump.try_lock()) {
                        this->nextJump = false;
                        this->mNextJump.unlock();
                    }
                }
                else if (this->leftMovement)
                {
                    this->nodeBody->setVelocityLimit(RYUNOSUKE_WALL_SPEED);
                    this->nodeBody->setVelocity(cocos2d::Vec2(0.0, 0.0));//
                    if (this->mNextJump.try_lock()) {
                        this->nextJump = false;
                        this->mNextJump.unlock();
                    }
                }
                else
                {
                    this->nodeBody->setVelocityLimit(RYUNOSUKE_WALL_SPEED);
                    this->nodeBody->setVelocity(cocos2d::Vec2(0.0, 0.0));//
                    if (this->mNextJump.try_lock()) {
                        this->nextJump = false;
                        this->mNextJump.unlock();
                    }
                }
                CCLOG("Left Wall Edge collision - In the floor and base of Ryunosuke UNDER center of the Right Wall");
            }
        }
        else
        {
            CCLOG("Left Wall Edge collision - In the floor and base of Ryunosuke OVER center of the Right Wall");
            mWallDetection.unlock();
            return false;
        }
		mWallDetection.unlock();
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
	else if ((a->getCollisionBitmask() == RYUNOSUKE_BITMASK && b->getCollisionBitmask() == EDGE_FLOOR_RIGHT_BITMASK) || (a->getCollisionBitmask() == EDGE_FLOOR_RIGHT_BITMASK && b->getCollisionBitmask() == RYUNOSUKE_BITMASK))
	{
		this->onTheEdgeFloor = false;
		CCLOG("Edge Right Floor Separation");
	}
	else if ((a->getCollisionBitmask() == RYUNOSUKE_BITMASK && b->getCollisionBitmask() == EDGE_FLOOR_LEFT_BITMASK) || (a->getCollisionBitmask() == EDGE_FLOOR_LEFT_BITMASK && b->getCollisionBitmask() == RYUNOSUKE_BITMASK))
	{
		this->onTheEdgeFloor = false;
		CCLOG("Edge Left Floor Separation");
	}
	else if ((a->getCollisionBitmask() == RYUNOSUKE_BITMASK && b->getCollisionBitmask() == EDGE_RIGHT_OBSTACLE_BITMASK) || (a->getCollisionBitmask() == EDGE_RIGHT_OBSTACLE_BITMASK && b->getCollisionBitmask() == RYUNOSUKE_BITMASK))
	{
		this->onTheEdgeRightWall = false;
        this->nodeBody->setVelocityLimit(cocos2d::PHYSICS_INFINITY);
		CCLOG("Edge Right Wall Separation");
	}
	else if ((a->getCollisionBitmask() == RYUNOSUKE_BITMASK && b->getCollisionBitmask() == EDGE_LEFT_OBSTACLE_BITMASK) || (a->getCollisionBitmask() == EDGE_LEFT_OBSTACLE_BITMASK && b->getCollisionBitmask() == RYUNOSUKE_BITMASK))
	{
    	this->onTheEdgeLeftWall = false;
        this->nodeBody->setVelocityLimit(cocos2d::PHYSICS_INFINITY);
		CCLOG("Edge Left Wall Separation");
	}
}