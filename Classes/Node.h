//
// Created by AntonioMontana on 14/03/2017.
//

#ifndef NINJANOMEIYO_NODE_H
#define NINJANOMEIYO_NODE_H

#include <string>
#include "cocos2d.h"

namespace NinjaM{

    class Node
    {
    public:
        Node();
        Node(cocos2d::Size visibleSize, cocos2d::Vec2 position, cocos2d::Vec2 anchorPoint, std::string texture, float rotation);
        virtual ~Node();

        virtual void spawn(cocos2d::Layer *layer);

        cocos2d::Vec2 getPosition() {return position;}
        cocos2d::Vec2 getAnchorPoint() {return anchorPoint;}
        std::string getTexture() {return texture;}
        float getRotation() {return rotation;}
        cocos2d::Sprite* getNodeSprite() {return this->nodeSprite;}

        void setPosition(cocos2d::Vec2 position) {this->position = position;}
        void setAnchorPoint(cocos2d::Vec2 anchorPoint) {this->anchorPoint = anchorPoint;}
        void setTexture(std::string texture) {this->texture = texture;}
        void setRotation(float) {this->rotation = rotation;}

	private:
    protected:
        cocos2d::Size visibleSize;
        cocos2d::Vec2 position;
        cocos2d::Vec2 anchorPoint;
        std::string texture;
        float rotation;

		cocos2d::PolygonInfo poligonInfo;
		cocos2d::Sprite *nodeSprite;
    };
}

#endif //NINJANOMEIYO_NODE_H
