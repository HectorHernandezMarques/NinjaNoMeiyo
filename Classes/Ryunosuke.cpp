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
    nodeSprite = cocos2d::Sprite::create(this->texture);
    nodeSprite->setPosition(this->position);
    layer->addChild(nodeSprite);
}


void NinjaM::Ryunosuke::setEventDispatcher(cocos2d::Layer *layer)
{
	auto listener = cocos2d::EventListenerTouchOneByOne::create();
	listener->onTouchBegan = [] (cocos2d::Touch* touch, cocos2d::Event* event) { return true; };
	listener->onTouchMoved = [=] (cocos2d::Touch* touch, cocos2d::Event* event) {
		auto touchPosition = touch->getLocation();
		if (nodeSprite->getBoundingBox().containsPoint(touchPosition)) {
			nodeSprite->setPosition(touchPosition);
		} };
	listener->onTouchEnded = [=](cocos2d::Touch* touch, cocos2d::Event* event) {};
	layer->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, layer);
}


void NinjaM::Ryunosuke::movePlayer(cocos2d::Touch* touch, cocos2d::Event* event)
{
	auto touchPosition = touch->getLocation();
	if (nodeSprite->getBoundingBox().containsPoint(touchPosition)) {
		nodeSprite->setPosition(touchPosition);
	}
}