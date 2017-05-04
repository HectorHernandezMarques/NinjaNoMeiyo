//
// Created by AntonioMontana on 14/03/2017.
//

#include "./Touch.h"

NinjaM::Touch::Touch()
{

}

NinjaM::Touch::Touch(cocos2d::Size visibleSize, cocos2d::Vec2 position, cocos2d::Vec2 anchorPoint, float rotation) : Node(visibleSize, position, anchorPoint, "", rotation)
{
	CCLOG("Touch builder");
}

NinjaM::Touch::~Touch()
{

}

void NinjaM::Touch::spawn(cocos2d::Layer *layer)
{
	this->nodeSprite = cocos2d::Sprite::create();
	this->nodeSprite->setPosition(this->position);
	this->nodeSprite->setAnchorPoint(this->anchorPoint);
	this->nodeSprite->setOpacity(0);
	layer->addChild(nodeSprite);
}

void NinjaM::Touch::setEventDispatcher()
{
	this->listener = cocos2d::EventListenerTouchOneByOne::create();
	this->listener->onTouchBegan = CC_CALLBACK_2(NinjaM::Touch::getInitialTouchValues, this);
	this->listener->onTouchMoved = CC_CALLBACK_2(NinjaM::Touch::moveTouch, this);
	this->listener->onTouchEnded = CC_CALLBACK_2(NinjaM::Touch::endMovement, this);
	this->nodeSprite->getEventDispatcher()->addEventListenerWithSceneGraphPriority(this->listener, this->nodeSprite);
}


bool NinjaM::Touch::getInitialTouchValues(cocos2d::Touch* touch, cocos2d::Event* event)
{
	auto touchPosition = touch->getLocation();
	if (this->nodeSprite->getBoundingBox().containsPoint(touchPosition)) {
	    this->initialTouchPosition = nodeSprite->getPosition();
	    this->positionVariation = cocos2d::Vec2(touch->getLocation().x - this->initialTouchPosition.x, touch->getLocation().y - this->initialTouchPosition.y);
	    return true;
	}
	else
    {
	    return false;
    }
}

void NinjaM::Touch::moveTouch(cocos2d::Touch* touch, cocos2d::Event* event)
{
	auto touchPosition = touch->getLocation();
	this->nodeSprite->setPosition(cocos2d::Vec2(touchPosition.x - this->positionVariation.x, touchPosition.y - this->positionVariation.y));
}

void NinjaM::Touch::endMovement(cocos2d::Touch* touch, cocos2d::Event* event)
{

}