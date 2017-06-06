//
// Created by AntonioMontana on 14/03/2017.
//

#include "./Limit.h"

NinjaM::Limit::Limit()
{

}

NinjaM::Limit::Limit(cocos2d::Size visibleSize, cocos2d::Vec2 position, cocos2d::Vec2 anchorPoint, std::string texture, float rotation, cocos2d::Size size) : PhysicNode(visibleSize, position, anchorPoint, texture, rotation)
{
    CCLOG("Limit Builder");
	contentSize = size;
}

NinjaM::Limit::~Limit()
{

}

void NinjaM::Limit::spawn(cocos2d::Layer *layer, int limitBitmask)
{
	this->nodeSprite = cocos2d::Sprite::create();
	this->nodeSprite->setPosition(cocos2d::Vec2(this->position.x + this->contentSize.width/2, this->position.y + this->contentSize.height/2));
	this->nodeSprite->setAnchorPoint(this->anchorPoint);

	this->nodeBody = cocos2d::PhysicsBody::createBox(this->contentSize);
	this->nodeBody->setCollisionBitmask(FIXED_OBSTACLE_BITMASK);
	this->nodeBody->setDynamic(false);
	this->nodeBody->setContactTestBitmask(true);
	this->nodeBody->setRotationEnable(false);
	this->nodeSprite->setPhysicsBody(nodeBody);

	layer->addChild(nodeSprite);
}