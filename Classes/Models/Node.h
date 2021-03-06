#ifndef NINJANOMEIYO_MODELS_NODE_H
#define NINJANOMEIYO_MODELS_NODE_H

#include <string>
#include <unordered_set>
#include "cocos2d.h"
#include "./Observers/NodeObserver.h"
#include "./Aspects/Node/AddEventListenerWithSceneGraphPriorityAspect.h"
#include "./Aspects/Node/PhysicAspect.h"
#include "./Aspects/Node/PositionAspect.h"
#include "./Aspects/Node/AnchorPointAspect.h"
#include "./Aspects/Node/RotationAspect.h"
#include "./Aspects/Node/RunActionAspect.h"
#include "./Aspects/Node/StopActionAspect.h"
#include "./Aspects/Node/TextureAspect.h"
#include "./Physics/Physic.h"
#include "./Physics/PhysicEmpty.h"

namespace NinjaNoMeiyo {
	namespace Models {

		class Node {
		public:
			Node(cocos2d::Vec2 position, cocos2d::Vec2 anchorPoint = cocos2d::Vec2::ZERO, std::string texture = "", float rotation = 0.0, Physics::Physic *physic = new Physics::PhysicEmpty());
			virtual ~Node();

			void attach(Models::Observers::NodeObserver &nodeObserver);
			void notify(Aspects::Node::Aspect &aspect);
			bool hasPhysic();
			void runAction(cocos2d::Action *action);
			void stopAction(cocos2d::Action *action);
			void addEventListenerWithSceneGraphPriority(cocos2d::EventListener *listener);

			cocos2d::Vec2 getInitialPosition();
			cocos2d::Vec2 getPosition();
			cocos2d::Size getContentSize();
			cocos2d::Vec2 getAnchorPoint();
			std::string getTexture();
			float getRotation();
			Physics::Physic& getPhysic();
			cocos2d::PhysicsBody& getPhysicBody();
			cocos2d::Vec2 getVelocity();
			cocos2d::Layer& getLayer();
			void setPosition(cocos2d::Vec2 position);
			void setAnchorPoint(cocos2d::Vec2 anchorPoint);
			void setTexture(std::string texture);
			void setRotation(float rotation);
			void setPhysic(Physics::Physic &physic);
			void setDynamic(bool dynamic);
			void setCategoryBitmask(int bitmask);
			void setCollisionBitmask(int bitmask);
			void setContactTestBitmask(int bitmask);
			void setVelocity(cocos2d::Vec2 velocity);
			void setVelocityLimit(float velocity);

		protected:

		private:
			cocos2d::Vec2 position;
			cocos2d::Vec2 anchorPoint;
			std::string texture;
			float rotation;
			Models::Observers::NodeObserver *nodeObserver;
			Physics::Physic *physic;
		};
	}
}

#endif