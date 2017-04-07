//
// Created by AntonioMontana on 14/03/2017.
//

#ifndef NINJANOMEIYO_PHYSIC_NODE_H
#define NINJANOMEIYO_PHYSIC_NODE_H

#include <string>
#include "cocos2d.h"
#include "./Node.h"

namespace NinjaM{

    class PhysicNode : public NinjaM::Node
    {
    public:
        PhysicNode();
		PhysicNode(cocos2d::Size visibleSize, cocos2d::Vec2 position, cocos2d::Vec2 anchorPoint, std::string texture, float rotation);
        virtual ~PhysicNode();

        virtual void spawn(cocos2d::Layer *layer);

    private:
	protected:
        cocos2d::PhysicsBody *nodeBody;
    };
}

#endif //NINJANOMEIYO_PHYSIC_NODE_H
