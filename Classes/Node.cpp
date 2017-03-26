//
// Created by AntonioMontana on 14/03/2017.
//

#include "./Node.h"

NinjaM::Node::Node()
{

}

NinjaM::Node::Node(std::string texture, cocos2d::Vec2 position)
{
    this->texture = texture;
    this->position = position;
}

NinjaM::Node::~Node()
{

}

void NinjaM::Node::spawn(cocos2d::Layer *layer)
{
    auto nodeSprite = cocos2d::Sprite::create(this->texture);
    nodeSprite->setPosition(this->position);
    layer->addChild(nodeSprite);
}