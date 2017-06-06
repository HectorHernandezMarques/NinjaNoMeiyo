//
// Created by AntonioMontana on 14/03/2017.
//

#include <unistd.h>
#include "./MovementTouch.h"

NinjaM::MovementTouch::MovementTouch()
{

}

NinjaM::MovementTouch::MovementTouch(cocos2d::Size visibleSize, cocos2d::Vec2 position, cocos2d::Vec2 anchorPoint, float rotation, int sense, NinjaM::Ryunosuke* ryunosuke) : Touch(visibleSize, position, anchorPoint, rotation)
{
	CCLOG("MovementTouch builder");
	this->sense = sense;
    this->ryunosuke = ryunosuke;
}

NinjaM::MovementTouch::~MovementTouch()
{

}

void NinjaM::MovementTouch::spawn(cocos2d::Layer *layer)
{
    NinjaM::Touch::spawn(layer);
	this->nodeSprite->setTextureRect(cocos2d::Rect(this->position.x, this->position.y, this->visibleSize.width/2, this->visibleSize.height));
}

void NinjaM::MovementTouch::setEventDispatcher()
{
	this->listener = cocos2d::EventListenerTouchOneByOne::create();
	this->listener->onTouchBegan = CC_CALLBACK_2(NinjaM::MovementTouch::getInitialTouchValues, this);
	this->listener->onTouchMoved = CC_CALLBACK_2(NinjaM::MovementTouch::moveTouch, this);
	this->listener->onTouchEnded = CC_CALLBACK_2(NinjaM::MovementTouch::endMovement, this);
	this->nodeSprite->getEventDispatcher()->addEventListenerWithSceneGraphPriority(this->listener, this->nodeSprite);
}

void NinjaM::MovementTouch::toMoveAfterWait(float sense)
{
	this->ryunosuke->toMove(this->sense, true);
}

bool NinjaM::MovementTouch::getInitialTouchValues(cocos2d::Touch* touch, cocos2d::Event* event)
{
    this->mForcingUntouch.unlock();
	this->mGestureMade.unlock();
	auto touchPosition = touch->getLocation();
	if (this->nodeSprite->getBoundingBox().containsPoint(touchPosition)) {
		if (this->mDoubleTouch.try_lock()) {
		    //añadir retraso
			this->jumpCleanerSequence = cocos2d::Sequence::create(cocos2d::DelayTime::create(TOUCH_DELAY), cocos2d::CallFunc::create(CC_CALLBACK_0(NinjaM::MovementTouch::toMoveAfterWait, this, this->sense)), nullptr);
            this->nodeSprite->runAction(this->jumpCleanerSequence);
			this->initialTouchPosition = nodeSprite->getPosition();
			this->positionVariation = cocos2d::Vec2(touch->getLocation().x - this->initialTouchPosition.x, touch->getLocation().y - this->initialTouchPosition.y);
			if (this->sense > 0.0)
			{
				this->ryunosuke->getNodeSprite()->setTexture("Ryunosuke1D.png");
			}
			else
			{
				this->ryunosuke->getNodeSprite()->setTexture("Ryunosuke1I.png");
			}
			return true;
		}
		else {
			return false;
		}
	}
	else
	{
		return false;
	}
}

void NinjaM::MovementTouch::moveTouch(cocos2d::Touch* touch, cocos2d::Event* event)
{
    if (this->mForcingUntouch.try_lock()) {
        mForcingUntouch.unlock();
        auto touchPosition = touch->getLocation();
        this->nodeSprite->setPosition(cocos2d::Vec2(touchPosition.x - this->positionVariation.x, touchPosition.y - this->positionVariation.y));
        // |o|o|o|
        // | | | |
        // | | | |
        if (nodeSprite->getPositionY() > this->initialTouchPosition.y + this->visibleSize.height / TOUCH_UPPER_JUMP)
        {
            // | | |o|
            // | | | |
            // | | | |
            if (nodeSprite->getPositionX() > this->initialTouchPosition.x + this->visibleSize.height / TOUCH_RIGHT_JUMP)
            {
				std::try_lock(this->mGestureMade, this->mForcingUntouch);

				this->nodeSprite->stopAction(this->jumpCleanerSequence);

                this->ryunosuke->toJump(fabs(this->sense), true);
				this->ryunosuke->toStop(this->sense);
				this->nodeSprite->setPosition(this->position);
				this->mDoubleTouch.unlock();
            }
            // |o| | |
            // | | | |
            // | | | |
            else if (nodeSprite->getPositionX() < this->initialTouchPosition.x - this->visibleSize.height / TOUCH_LEFT_JUMP)
            {
				std::try_lock(this->mGestureMade, this->mForcingUntouch);

				this->nodeSprite->stopAction(this->jumpCleanerSequence);

                this->ryunosuke->toJump(-fabs(this->sense), true);
				this->ryunosuke->toStop(this->sense);
				this->nodeSprite->setPosition(this->position);
				this->mDoubleTouch.unlock();
            }
            // | |o| |
            // | | | |
            // | | | |
            else if (nodeSprite->getPositionY() > this->initialTouchPosition.y + this->visibleSize.height / TOUCH_UPPER_JUMP_2)
            {
				std::try_lock(this->mGestureMade, this->mForcingUntouch);

				this->nodeSprite->stopAction(this->jumpCleanerSequence);

                this->ryunosuke->toJump(0.0, true);
				this->ryunosuke->toStop(this->sense);
				this->nodeSprite->setPosition(this->position);
				this->mDoubleTouch.unlock();
            }

        }
	}
}

void NinjaM::MovementTouch::endMovement(cocos2d::Touch* touch, cocos2d::Event* event)
{
	this->nodeSprite->stopAction(this->jumpCleanerSequence);

	this->ryunosuke->toStop(this->sense);

	this->nodeSprite->setPosition(this->position);
	this->mDoubleTouch.unlock();
}