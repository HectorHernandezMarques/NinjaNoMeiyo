//
// Created by AntonioMontana on 14/03/2017.
//

#include "./Terrain.h"

NinjaM::Terrain::Terrain()
{

}

NinjaM::Terrain::Terrain(cocos2d::Size visibleSize, cocos2d::Vec2 position, cocos2d::Vec2 anchorPoint, std::string texture, float rotation) : PhysicNode(visibleSize, position, anchorPoint, texture, rotation)
{
    CCLOG("Terrain Builder");
}

NinjaM::Terrain::~Terrain()
{

}

void NinjaM::Terrain::spawn(cocos2d::Layer *layer)
{
    NinjaM::PhysicNode::spawn(layer);
	this->nodeBody->setCollisionBitmask(FIXED_OBSTACLE_BITMASK);
    for ( int i = 0 ; i < SURFACE_NUMBER ; i++ )
    {
        this->surfaceNode[i] = cocos2d::Node::create();
        switch (i)
        {
            case UPPER_SURFACE_INDEX:
                this->surfaceNode[i]->setPosition(cocos2d::Vec2(this->position.x + this->nodeSprite->getContentSize().width / 2, this->position.y + this->nodeSprite->getContentSize().height));

                this->surfaceBody[i] = cocos2d::PhysicsBody::createBox(cocos2d::Size(this->nodeSprite->getContentSize().width, 1));
                this->surfaceBody[i]->setCollisionBitmask(FLOOR_BITMASK);

                break;

            case RIGHT_SURFACE_INDEX:
                this->surfaceNode[i]->setPosition(cocos2d::Vec2(this->position.x + this->nodeSprite->getContentSize().width, this->position.y + this->nodeSprite->getContentSize().height/2));

                this->surfaceBody[i] = cocos2d::PhysicsBody::createBox(cocos2d::Size(1, this->nodeSprite->getContentSize().height));
                this->surfaceBody[i]->setCollisionBitmask(LEFT_OBSTACLE_BITMASK);
                break;

            case LEFT_SURFACE_INDEX:
                this->surfaceNode[i]->setPosition(cocos2d::Vec2(this->position.x, this->position.y + this->nodeSprite->getContentSize().height/2));

                this->surfaceBody[i] = cocos2d::PhysicsBody::createBox(cocos2d::Size(1, this->nodeSprite->getContentSize().height));
                this->surfaceBody[i]->setCollisionBitmask(RIGHT_OBSTACLE_BITMASK);
                break;

            case LOWER_SURFACE_INDEX:
                this->surfaceNode[i]->setPosition(cocos2d::Vec2(this->position.x + this->nodeSprite->getContentSize().width/2, this->position.y));

                this->surfaceBody[i] = cocos2d::PhysicsBody::createBox(cocos2d::Size(this->nodeSprite->getContentSize().width, 1));
                this->surfaceBody[i]->setCollisionBitmask(CEILING_BITMASK);
                break;
        }

        this->surfaceBody[i]->setDynamic(false);
        this->surfaceBody[i]->setContactTestBitmask(true);
        this->surfaceBody[i]->setRotationEnable(false);

        this->surfaceNode[i]->setPhysicsBody(this->surfaceBody[i]);
        layer->addChild(this->surfaceNode[i]);

    }
}