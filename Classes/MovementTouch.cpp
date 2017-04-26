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

void NinjaM::MovementTouch::setEventDispatcher(cocos2d::Layer *layer)
{
	auto listener = cocos2d::EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(NinjaM::MovementTouch::getInitialTouchValues, this);
	listener->onTouchMoved = CC_CALLBACK_2(NinjaM::MovementTouch::movePlayer, this);
	listener->onTouchEnded = CC_CALLBACK_2(NinjaM::MovementTouch::endMovement, this);
	layer->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, layer);
}


bool NinjaM::MovementTouch::getInitialTouchValues(cocos2d::Touch* touch, cocos2d::Event* event)
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

void NinjaM::MovementTouch::movePlayer(cocos2d::Touch* touch, cocos2d::Event* event)
{
	auto touchPosition = touch->getLocation();
	//if (this->nodeSprite->getBoundingBox().containsPoint(touchPosition)) {
	    auto nodeSprite = this->ryunosuke->getNodeSprite();
		nodeSprite->setPosition(cocos2d::Vec2(nodeSprite->getPositionX() + this->sense, nodeSprite->getPositionY()));
	//}
}

void NinjaM::MovementTouch::endMovement(cocos2d::Touch* touch, cocos2d::Event* event)
{
	//this->nodeSprite->setPosition(this->initialTouchPosition);
}