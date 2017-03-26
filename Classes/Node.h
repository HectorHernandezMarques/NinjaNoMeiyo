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
        Node(std::string texture, cocos2d::Vec2 position);
        virtual ~Node();

        virtual void spawn(cocos2d::Layer *layer);

        virtual cocos2d::Vec2 getPosition() {return position;}
        virtual cocos2d::Vec2 getAnchorPoint() {return anchorPoint;}
        virtual std::string getTexture() {return texture;}
        virtual float getRotation() {return rotation;}

        virtual void setPosition(cocos2d::Vec2 position) {this->position = position;}
        virtual void setAnchorPoint(cocos2d::Vec2 anchorPoint) {this->anchorPoint = anchorPoint;}
        virtual void setTexture(std::string texture) {this->texture = texture;}
        virtual void setRotation(float) {this->rotation = rotation;}

    private:
        cocos2d::Size visibleSize;
        cocos2d::Vec2 position;
        cocos2d::Vec2 anchorPoint;
        std::string texture;
        float rotation;
    };
}

#endif //NINJANOMEIYO_NODE_H
