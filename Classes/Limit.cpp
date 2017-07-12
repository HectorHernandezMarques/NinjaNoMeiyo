//
// Created by AntonioMontana on 14/03/2017.
//

#include "./Limit.h"

NinjaM::Limit::Limit()
{

}

NinjaM::Limit::Limit(cocos2d::Size visibleSize, cocos2d::Vec2 position, cocos2d::Vec2 anchorPoint, std::string texture, float rotation, std::vector<cocos2d::Vec2> points, int count) : PhysicNode(visibleSize, position, anchorPoint, texture, rotation)
{
    CCLOG("Limit Builder");
	this->points = points;
	this->count = count;
}

NinjaM::Limit::~Limit()
{

}

void NinjaM::Limit::setPoints(std::vector<cocos2d::Vec2> points)
{
	this->points = points;
}

void NinjaM::Limit::spawn(cocos2d::Layer *layer, int limitBitmask)
{
	this->nodeSprite = cocos2d::Sprite::create();
	this->nodeSprite->setPosition(cocos2d::Vec2(this->position.x, this->position.y));
	//this->nodeSprite->setPosition(cocos2d::Vec2(this->position.x + this->contentSize.width/2, this->position.y + this->contentSize.height/2));
	this->nodeSprite->setAnchorPoint(this->anchorPoint);

	cocos2d::Vec2 arrayPoints[this->count];

	for (int i = 0 ; i < this->count ; i++)
	{
		arrayPoints[i] = cocos2d::Vec2(this->points.at(i).x - this->position.x, this->points.at(i).y - this->position.y);
		CCLOG("%d: %f, %f", i, arrayPoints[i].x, arrayPoints[i].y);
	}

	this->nodeBody = cocos2d::PhysicsBody::createPolygon(arrayPoints, this->count);
	//this->nodeBody = cocos2d::PhysicsBody::createBox(cocos2d::Size(100,100));
	this->nodeBody->setCollisionBitmask(FIXED_OBSTACLE_BITMASK);
	this->nodeBody->setDynamic(false);
	this->nodeBody->setContactTestBitmask(true);
	this->nodeBody->setRotationEnable(false);
	this->nodeSprite->setPhysicsBody(nodeBody);

	layer->addChild(nodeSprite);
	CCLOG("xdno");
}