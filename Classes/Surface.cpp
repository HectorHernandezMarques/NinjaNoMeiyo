//
// Created by AntonioMontana on 14/03/2017.
//

#include "./Surface.h"

NinjaM::Surface::Surface()
{

}

NinjaM::Surface::Surface(cocos2d::Size visibleSize, cocos2d::Vec2 position, cocos2d::Vec2 anchorPoint, std::string texture, float rotation, cocos2d::Size size) : Node(visibleSize, position, anchorPoint, texture, rotation)
{
    CCLOG("Surface Builder");
	contentSize = size;
}

NinjaM::Surface::~Surface()
{

}

void NinjaM::Surface::spawn(cocos2d::Layer *layer)
{
    for ( int i = 0 ; i < SURFACE_NUMBER ; i++ )
    {
        this->surfaceNode[i] = cocos2d::Node::create();
        switch (i)
        {
            case UPPER_SURFACE_INDEX:
                this->surfaceNode[i]->setPosition(cocos2d::Vec2(this->position.x + this->contentSize.width / 2, this->position.y + this->contentSize.height));

                this->surfaceBody[i] = cocos2d::PhysicsBody::createBox(cocos2d::Size(this->contentSize.width, 1));
                this->surfaceBody[i]->setCollisionBitmask(FLOOR_BITMASK);
                break;

            case RIGHT_SURFACE_INDEX:
                this->surfaceNode[i]->setPosition(cocos2d::Vec2(this->position.x + this->contentSize.width, this->position.y + this->contentSize.height/2));

                this->surfaceBody[i] = cocos2d::PhysicsBody::createBox(cocos2d::Size(1, this->contentSize.height));
                this->surfaceBody[i]->setCollisionBitmask(LEFT_OBSTACLE_BITMASK);
                break;

            case LEFT_SURFACE_INDEX:
                this->surfaceNode[i]->setPosition(cocos2d::Vec2(this->position.x, this->position.y + this->contentSize.height/2));

                this->surfaceBody[i] = cocos2d::PhysicsBody::createBox(cocos2d::Size(1, this->contentSize.height));
                this->surfaceBody[i]->setCollisionBitmask(RIGHT_OBSTACLE_BITMASK);
                break;

            case LOWER_SURFACE_INDEX:
                this->surfaceNode[i]->setPosition(cocos2d::Vec2(this->position.x + this->contentSize.width/2, this->position.y));

                this->surfaceBody[i] = cocos2d::PhysicsBody::createBox(cocos2d::Size(this->contentSize.width, 1));
                this->surfaceBody[i]->setCollisionBitmask(CEILING_BITMASK);
                break;
        }

        this->surfaceBody[i]->setDynamic(false);
        this->surfaceBody[i]->setContactTestBitmask(true);
		this->surfaceBody[i]->setOwnerNode(this->nodeSprite);
        this->surfaceBody[i]->setRotationEnable(false);

        this->surfaceNode[i]->setPhysicsBody(this->surfaceBody[i]);
        layer->addChild(this->surfaceNode[i]);
    }
}

void NinjaM::Surface::spawn(cocos2d::Layer *layer, int upperSurfaceBitmask, int rightSurfaceBitmask, int leftSurfaceBitmask, int lowerSurfaceBitmask)
{
	for (int i = 0; i < SURFACE_NUMBER; i++)
	{
		this->surfaceNode[i] = cocos2d::Node::create();
		switch (i)
		{
		case UPPER_SURFACE_INDEX:
			this->surfaceNode[i]->setPosition(cocos2d::Vec2(this->position.x + this->contentSize.width / 2, this->position.y + this->contentSize.height));

			this->surfaceBody[i] = cocos2d::PhysicsBody::createBox(cocos2d::Size(this->contentSize.width, 1));
			this->surfaceBody[i]->setCollisionBitmask(upperSurfaceBitmask);

			break;

		case RIGHT_SURFACE_INDEX:
			this->surfaceNode[i]->setPosition(cocos2d::Vec2(this->position.x + this->contentSize.width, this->position.y + this->contentSize.height / 2));

			this->surfaceBody[i] = cocos2d::PhysicsBody::createBox(cocos2d::Size(1, this->contentSize.height));
			this->surfaceBody[i]->setCollisionBitmask(rightSurfaceBitmask);
			break;

		case LEFT_SURFACE_INDEX:
			this->surfaceNode[i]->setPosition(cocos2d::Vec2(this->position.x, this->position.y + this->contentSize.height / 2));

			this->surfaceBody[i] = cocos2d::PhysicsBody::createBox(cocos2d::Size(1, this->contentSize.height));
			this->surfaceBody[i]->setCollisionBitmask(leftSurfaceBitmask);
			break;

		case LOWER_SURFACE_INDEX:
			this->surfaceNode[i]->setPosition(cocos2d::Vec2(this->position.x + this->contentSize.width / 2, this->position.y));

			this->surfaceBody[i] = cocos2d::PhysicsBody::createBox(cocos2d::Size(this->contentSize.width, 1));
			this->surfaceBody[i]->setCollisionBitmask(lowerSurfaceBitmask);
			break;
		}

		this->surfaceBody[i]->setDynamic(false);
		this->surfaceBody[i]->setContactTestBitmask(true);
		this->surfaceBody[i]->setOwnerNode(this->nodeSprite);
		this->surfaceBody[i]->setRotationEnable(false);

		this->surfaceNode[i]->setPhysicsBody(this->surfaceBody[i]);
		layer->addChild(this->surfaceNode[i]);

	}
}