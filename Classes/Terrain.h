//
// Created by AntonioMontana on 14/03/2017.
//

#ifndef NINJANOMEIYO_TERRAIN_H
#define NINJANOMEIYO_TERRAIN_H

#include <string>
#include "Definitions.h"
#include "cocos2d.h"
#include "./PhysicNode.h"

namespace NinjaM{

    class Terrain : public NinjaM::PhysicNode
    {
    public:
        Terrain();
        Terrain(cocos2d::Size visibleSize, cocos2d::Vec2 position, cocos2d::Vec2 anchorPoint, std::string texture, float rotation);
        virtual ~Terrain();

        cocos2d::PhysicsBody* getSurfaceBody(int index) {return surfaceBody[index];}

        cocos2d::Node* getSurfaceNode(int index) {return surfaceNode[index];}

        void setSurfaceBody(cocos2d::PhysicsBody* upperSurfaceBody, int index) {this->surfaceBody[index] = upperSurfaceBody;}

        void setSurfaceNode(cocos2d::Node* surfaceNode, int index) {this->surfaceNode[index] = surfaceNode;}

        void setSurfacesMasks(int upperSurfaceMask, int leftSurfaceMask, int rightSurfaceMask, int lowerSurfaceMask) { this->surfaceBody[UPPER_SURFACE_INDEX]->setCollisionBitmask(upperSurfaceMask);
                                                                                                                        this->surfaceBody[LEFT_SURFACE_INDEX]->setCollisionBitmask(leftSurfaceMask);
                                                                                                                        this->surfaceBody[RIGHT_SURFACE_INDEX]->setCollisionBitmask(rightSurfaceMask);
                                                                                                                        this->surfaceBody[LOWER_SURFACE_INDEX]->setCollisionBitmask(lowerSurfaceMask);}

        virtual void spawn(cocos2d::Layer *layer);

    private:
        cocos2d::Node *surfaceNode[SURFACE_NUMBER];
        cocos2d::PhysicsBody *surfaceBody[SURFACE_NUMBER];
    };
}

#endif //NINJANOMEIYO_TERRAIN_H
