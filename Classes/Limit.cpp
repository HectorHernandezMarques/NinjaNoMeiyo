//
// Created by AntonioMontana on 14/03/2017.
//

#include "./Limit.h"

NinjaM::Limit::Limit()
{

}

NinjaM::Limit::Limit(cocos2d::Size visibleSize, cocos2d::Vec2 position, cocos2d::Vec2 anchorPoint, std::string texture, float rotation, cocos2d::Size contentSize, int count) : PhysicNode(visibleSize, position, anchorPoint, texture, rotation)
{
    CCLOG("Limit Builder");
	this->contentSize = contentSize;
	this->count = count;
}

NinjaM::Limit::~Limit()
{

}

void NinjaM::Limit::setPoints(cocos2d::Vec2 p0, cocos2d::Vec2 p1, cocos2d::Vec2 p2, cocos2d::Vec2 p3)
{
	CCLOG("%f", p0.x);
	this->points[0] = p0;
	this->points[1] = p1;
	this->points[2] = p2;
	this->points[3] = p3;
}

void NinjaM::Limit::spawn(cocos2d::Layer *layer, int limitBitmask)
{
	this->nodeSprite = cocos2d::Sprite::create();
	this->nodeSprite->setPosition(cocos2d::Vec2(this->position.x, this->position.y));
	//this->nodeSprite->setPosition(cocos2d::Vec2(this->position.x + this->contentSize.width/2, this->position.y + this->contentSize.height/2));
	this->nodeSprite->setAnchorPoint(this->anchorPoint);

	this->nodeBody = cocos2d::PhysicsBody::createPolygon(this->points, this->count);
	//this->nodeBody = cocos2d::PhysicsBody::createBox(this->contentSize);
	this->nodeBody->setCollisionBitmask(FIXED_OBSTACLE_BITMASK);
	this->nodeBody->setDynamic(false);
	this->nodeBody->setContactTestBitmask(true);
	this->nodeBody->setRotationEnable(false);
	this->nodeSprite->setPhysicsBody(nodeBody);

	layer->addChild(nodeSprite);
}