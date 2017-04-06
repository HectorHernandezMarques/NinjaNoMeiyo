//
// Created by AntonioMontana on 14/03/2017.
//

#include "./PhysicNode.h"

NinjaM::PhysicNode::PhysicNode()
{

}

NinjaM::PhysicNode::PhysicNode(cocos2d::Size visibleSize, cocos2d::Vec2 position, cocos2d::Vec2 anchorPoint, std::string texture, float rotation) : Node(visibleSize, position, anchorPoint, texture, rotation)
{
	CCLOG("PhysicNode builder");
}

NinjaM::PhysicNode::~PhysicNode()
{

}

void NinjaM::PhysicNode::spawn(cocos2d::Layer *layer)
{
    nodeSprite = cocos2d::Sprite::create(this->texture);
    nodeSprite->setPosition(this->position);
    layer->addChild(nodeSprite);
}