//
// Created by AntonioMontana on 14/03/2017.
//

#include "./Terrain.h"

NinjaM::Terrain::Terrain()
{

}

NinjaM::Terrain::Terrain(std::string texture, cocos2d::Vec2 position)
{
    this->texture = texture;
    this->position = position;
}

NinjaM::Terrain::~Terrain()
{

}

void NinjaM::Terrain::spawn(cocos2d::Layer *layer)
{
    auto nodeSprite = cocos2d::Sprite::create(this->texture);
    nodeSprite->setPosition(this->position);
    layer->addChild(nodeSprite);
}