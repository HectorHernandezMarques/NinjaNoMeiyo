//
// Created by AntonioMontana on 14/03/2017.
//

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
	auto listener = cocos2d::EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(NinjaM::MovementTouch::getInitialTouchValues, this);
	listener->onTouchMoved = CC_CALLBACK_2(NinjaM::MovementTouch::moveTouch, this);
	listener->onTouchEnded = CC_CALLBACK_2(NinjaM::MovementTouch::endMovement, this);
	this->nodeSprite->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this->nodeSprite);
}

bool NinjaM::MovementTouch::getInitialTouchValues(cocos2d::Touch* touch, cocos2d::Event* event)
{
	auto touchPosition = touch->getLocation();
	if (this->nodeSprite->getBoundingBox().containsPoint(touchPosition)) {
		if (this->m.try_lock()) {
			this->initialTouchPosition = nodeSprite->getPosition();
			this->positionVariation = cocos2d::Vec2(touch->getLocation().x - this->initialTouchPosition.x, touch->getLocation().y - this->initialTouchPosition.y);
			this->ryunosuke->toMove(this->sense);
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
	auto touchPosition = touch->getLocation();
	this->nodeSprite->setPosition(cocos2d::Vec2(touchPosition.x - this->positionVariation.x, touchPosition.y - this->positionVariation.y));
	if (nodeSprite->getPositionY() > this->initialTouchPosition.y + this->visibleSize.height / 10.0)
	{
		this->ryunosuke->toJump(this->sense);
	}
}

void NinjaM::MovementTouch::endMovement(cocos2d::Touch* touch, cocos2d::Event* event)
{
	this->ryunosuke->toStop(this->sense);
	this->nodeSprite->setPosition(this->position);
	this->m.unlock();
}