#include "./Node.h"
#include "../Models/Node.h"

namespace NinjaNoMeiyo {
	namespace Views {

		Node::Node(Models::Node &node, cocos2d::Layer &layer) : nodeSprite(*cocos2d::Sprite::create(node.getTexture())), layer(layer) {
			assert(&node);
			assert(&layer);
			
			node.attach(*this);
			this->nodeSprite.setPosition(node.getPosition());
			this->nodeSprite.setAnchorPoint(node.getAnchorPoint());
			if (node.hasPhysic()) {
				this->nodeSprite.setPhysicsBody(&node.getPhysicBody());
			}
		}

		Node::~Node() {

		}

		void Node::spawn() {
			this->layer.addChild(&nodeSprite);
		}

		void Node::update(Models::Aspects::Node::Aspect &aspect) {
			aspect.visit(*this);
		}

		cocos2d::Sprite& Node::getNodeSprite() {
			return this->nodeSprite;
		}

		void Node::setPosition(cocos2d::Vec2 position) {
			this->nodeSprite.setPosition(position);
		}

		void Node::setRotation(float rotation) {
			this->nodeSprite.setRotation(rotation);
		}

		void Node::setTexture(std::string texture) {
			this->nodeSprite.setTexture(texture);
		}
		
		void Node::setPhysic(cocos2d::PhysicsBody &physicBody) {
			this->nodeSprite.setPhysicsBody(&physicBody);
		}

		void Node::runAction(cocos2d::Action *action) {
			this->nodeSprite.runAction(action);
		}

		void Node::stopAction(cocos2d::Action *action) {
			this->nodeSprite.stopAction(action);
		}
	}
}