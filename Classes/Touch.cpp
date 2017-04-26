//
// Created by AntonioMontana on 14/03/2017.
//

#include "./Touch.h"

NinjaM::Touch::Touch()
{

}

NinjaM::Touch::Touch(cocos2d::Size visibleSize, cocos2d::Vec2 position, cocos2d::Vec2 anchorPoint, std::string texture, float rotation, int sense, NinjaM::Ryunosuke* ryunosuke) : Node(visibleSize, position, anchorPoint, texture, rotation)
{
	CCLOG("Touch builder");
}

NinjaM::Touch::~Touch()
{

}

void NinjaM::Touch::spawn(cocos2d::Layer *layer)
{
    NinjaM::Node::spawn(layer);
}

void NinjaM::Touch::setEventDispatcher(cocos2d::Layer *layer)
{
	auto listener = cocos2d::EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(NinjaM::Touch::getInitialTouchValues, this);
	listener->onTouchMoved = CC_CALLBACK_2(NinjaM::Touch::movePlayer, this);
	listener->onTouchEnded = CC_CALLBACK_2(NinjaM::Touch::endMovement, this);
	layer->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, layer);
}


bool NinjaM::Touch::getInitialTouchValues(cocos2d::Touch* touch, cocos2d::Event* event)
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

void NinjaM::Touch::movePlayer(cocos2d::Touch* touch, cocos2d::Event* event)
{
	auto touchPosition = touch->getLocation();
	//if (this->nodeSprite->getBoundingBox().containsPoint(touchPosition)) {
		this->nodeSprite->setPosition(cocos2d::Vec2(touchPosition.x - this->positionVariation.x, touchPosition.y - this->positionVariation.y));
	//}
}

void NinjaM::Touch::endMovement(cocos2d::Touch* touch, cocos2d::Event* event)
{
	//this->nodeSprite->setPosition(this->initialTouchPosition);
	this->nodeBody->setDynamic(true);
}