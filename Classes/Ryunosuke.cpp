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
    NinjaM::Character::spawn(layer);
	this->nodeBody = cocos2d::PhysicsBody::createCircle(this->nodeSprite->getContentSize().height / 2);
	this->nodeBody->setDynamic(true);
	this->nodeSprite->setPhysicsBody(nodeBody);
}


void NinjaM::Ryunosuke::setEventDispatcher(cocos2d::Layer *layer)
{
	auto listener = cocos2d::EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(NinjaM::Ryunosuke::getInitialTouchValues, this);
	listener->onTouchMoved = CC_CALLBACK_2(NinjaM::Ryunosuke::movePlayer, this);
	listener->onTouchEnded = CC_CALLBACK_2(NinjaM::Ryunosuke::endMovement, this);
	layer->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, layer);
}

bool NinjaM::Ryunosuke::getInitialTouchValues(cocos2d::Touch* touch, cocos2d::Event* event)
{
	auto touchPosition = touch->getLocation();
	if (this->nodeSprite->getBoundingBox().containsPoint(touchPosition)) {
		this->nodeBody->setDynamic(false);
	    this->initialTouchPosition = nodeSprite->getPosition();
	    this->positionVariation = cocos2d::Vec2(touch->getLocation().x - this->initialTouchPosition.x, touch->getLocation().y - this->initialTouchPosition.y);
	    return true;
	}
	else
    {
	    return false;
    }
}

void NinjaM::Ryunosuke::movePlayer(cocos2d::Touch* touch, cocos2d::Event* event)
{
	auto touchPosition = touch->getLocation();
	//if (this->nodeSprite->getBoundingBox().containsPoint(touchPosition)) {
		this->nodeSprite->setPosition(cocos2d::Vec2(touchPosition.x - this->positionVariation.x, touchPosition.y - this->positionVariation.y));
	//}
}

void NinjaM::Ryunosuke::endMovement(cocos2d::Touch* touch, cocos2d::Event* event)
{
	//this->nodeSprite->setPosition(this->initialTouchPosition);
	this->nodeBody->setDynamic(true);
}