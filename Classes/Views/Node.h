#ifndef NINJANOMEIYO_VIEWS_NODE_H
#define NINJANOMEIYO_VIEWS_NODE_H

#include <string>
#include "cocos2d.h"
#include "./Observers/NodeObserver.h"

namespace NinjaNoMeiyo {
	namespace Models {
				class Node;
	}
}

namespace NinjaNoMeiyo {
	namespace Views {

		class Node : virtual public Observers::NodeObserver {
		public:
			Node(Models::Node &node, cocos2d::Layer &layer);
			virtual ~Node();

			void spawn();
			void unspawn();
			void update(Models::Aspects::Node::Aspect &aspect);

			cocos2d::Sprite& getNodeSprite();

			void setPosition(cocos2d::Vec2 position);
			void setRotation(float rotation);
			void setAnchorPoint(cocos2d::Vec2 anchorPoint);
			void setTexture(std::string texture);
			void setPhysic(cocos2d::PhysicsBody &physicBody);
			cocos2d::Vec2 getCurrentPosition();
			cocos2d::Size getContentSize();
			cocos2d::Layer& getLayer();
			void runAction(cocos2d::Action *action);
			void stopAction(cocos2d::Action *action);
			void addEventListenerWithSceneGraphPriority(cocos2d::EventListener *listener);

		protected:
			cocos2d::Sprite &nodeSprite;
			cocos2d::Layer &layer;

		private:
		};
	}

}

#endif