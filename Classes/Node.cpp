//
// Created by AntonioMontana on 14/03/2017.
//

#include "./Node.h"

NinjaM::Node::Node()
{

}

NinjaM::Node::Node(cocos2d::Size visibleSize, cocos2d::Vec2 position, cocos2d::Vec2 anchorPoint, std::string texture, float rotation)
{
	this->visibleSize = visibleSize;
	this->position = position;
    this->anchorPoint = anchorPoint;
    this->texture = texture;
	this->rotation = rotation;
}

NinjaM::Node::~Node()
{

}

void NinjaM::Node::spawn(cocos2d::Layer *layer)
{
	//this->poligonInfo = cocos2d::AutoPolygon::generatePolygon(this->texture);
	//this->nodeSprite = cocos2d::Sprite::create(this->poligonInfo);
    this->nodeSprite = cocos2d::Sprite::create(this->texture);
    this->nodeSprite->setPosition(this->position);
	this->nodeSprite->setAnchorPoint(this->anchorPoint);
    layer->addChild(nodeSprite);

}