#include "./Node.h"
#include "../Models/Node.h"

namespace NinjaNoMeiyo {
	namespace Views {

		Node::Node(Models::Node &node, cocos2d::Layer &layer) : nodeSprite(*cocos2d::Sprite::create(node.getTexture())), layer(layer) {
			assert(&node);
			assert(&layer);
			
			node.attach(*this);
			this->nodeSprite.setAnchorPoint(node.getAnchorPoint());
			this->nodeSprite.setPosition(node.getInitialPosition());
			if (node.hasPhysic()) {
				this->nodeSprite.setPhysicsBody(&node.getPhysicBody());
			}
		}

		Node::~Node() {

		}

		void Node::spawn() {
			this->layer.addChild(&this->nodeSprite);
		}

		void Node::unspawn() {
			this->layer.removeChild(&this->nodeSprite);
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

		void Node::setAnchorPoint(cocos2d::Vec2 anchorPoint) {
			this->nodeSprite.setAnchorPoint(anchorPoint);
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

		cocos2d::Vec2 Node::getCurrentPosition() {
			return this->nodeSprite.getPosition();
		}

		cocos2d::Size Node::getContentSize() {
			return this->nodeSprite.getContentSize();
		}

		cocos2d::Layer& Node::getLayer() {
			return this->layer;
		}

		void Node::runAction(cocos2d::Action *action) {
			this->nodeSprite.runAction(action);
		}

		void Node::stopAction(cocos2d::Action *action) {
			this->nodeSprite.stopAction(action);
		}

		void Node::addEventListenerWithSceneGraphPriority(cocos2d::EventListener *listener) {
			this->nodeSprite.getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, &this->nodeSprite);
		}
	}
}