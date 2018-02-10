#include "./Node.h"

namespace NinjaNoMeiyo {
	namespace Models {

		Node::Node(cocos2d::Vec2 position, cocos2d::Vec2 anchorPoint, std::string texture, float rotation, Physics::Physic *physic) :
				position(position), anchorPoint(anchorPoint), texture(texture), rotation(rotation), nodeObserver(nullptr), physic(physic) {

		}

		Node::~Node()
		{

		}

		void Node::attach(Views::Observers::NodeObserver& nodeObserver) {
			this->nodeObserver = &nodeObserver;
		}

		void Node::notify(Aspects::Node::Aspect &aspect) {
			if (this->nodeObserver) {
				this->nodeObserver->update(aspect);
			}
		}

		bool Node::hasPhysic() {
			return this->physic != nullptr;
		}

		void Node::stopAction(cocos2d::Action *action) {
			if (action) {
				this->notify(*(new Aspects::Node::StopActionAspect(action)));
			}
		}

		void Node::runAction(cocos2d::Action *action) {
			this->notify(*(new Aspects::Node::RunActionAspect(action)));
		}

		void Node::addEventListenerWithSceneGraphPriority(cocos2d::EventListener *listener) {
			assert(listener);

			this->notify(*(new Aspects::Node::AddEventListenerWithSceneGraphPriorityAspect(listener)));
		}

		cocos2d::Vec2 Node::getPosition() {
			return this->position;
		}

		cocos2d::Vec2 Node::getAnchorPoint() {
			return this->anchorPoint;
		}

		std::string Node::getTexture() {
			return this->texture;
		}

		float Node::getRotation() {
			return this->rotation;
		}

		Physics::Physic& Node::getPhysic() {
			assert(this->physic);

			return *this->physic;
		}

		cocos2d::PhysicsBody& Node::getPhysicBody() {
			assert(this->physic);

			return this->physic->getPhysic();
		}

		cocos2d::Vec2 Node::getVelocity() {
			assert(this->physic);

			return this->physic->getVelocity();
		}

		void Node::setPosition(cocos2d::Vec2 position) {
			this->position = position;
			this->notify(*(new Aspects::Node::PositionAspect(this->position)));
		}

		void Node::setTexture(std::string texture) {
			this->texture = texture;
			this->notify(*(new Aspects::Node::TextureAspect(this->texture)));
		}

		void Node::setRotation(float rotation) {
			this->rotation = rotation;
			this->notify(*(new Aspects::Node::RotationAspect(this->rotation)));
		}
		void Node::setPhysic(Physics::Physic &physic) {
			this->physic = &physic;
			this->notify(*(new Aspects::Node::PhysicAspect(this->physic->getPhysic())));
		}

		void Node::setDynamic(bool dynamic) {
			assert(this->physic);

			this->physic->setDynamic(dynamic);
			this->notify(*(new Aspects::Node::PhysicAspect(this->physic->getPhysic())));
		}

		void Node::setCategoryBitmask(int bitmask) {
			assert(this->physic);

			this->physic->setCategoryBitmask(bitmask);
			this->notify(*(new Aspects::Node::PhysicAspect(this->physic->getPhysic())));
		}

		void Node::setCollisionBitmask(int bitmask) {
			assert(this->physic);

			this->physic->setCollisionBitmask(bitmask);
			this->notify(*(new Aspects::Node::PhysicAspect(this->physic->getPhysic())));
		}

		void Node::setContactTestBitmask(int bitmask) {
			assert(this->physic);

			this->physic->setContactTestBitmask(bitmask);
			this->notify(*(new Aspects::Node::PhysicAspect(this->physic->getPhysic())));
		}

		void Node::setVelocity(cocos2d::Vec2 velocity) {
			assert(&velocity);

			this->physic->setVelocity(velocity);
		}

	}
}