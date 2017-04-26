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
	this->nodeBody = cocos2d::PhysicsBody::createBox(this->nodeSprite->getContentSize());
	this->nodeBody->setDynamic(true);
    this->nodeSprite->setPhysicsBody(nodeBody);
}