#include "./Ryunosuke.h"
#include "./CharacterVisitor.h"
#include "./States/Ryunosuke/InFloor.h"
#include "./States/StateHandlers/Ryunosuke/StateHandlerBuilder.h"
#include "../CollisionHandlers/Characters/Ryunosuke/ConcreteCollisionHandlerBuilder.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {

			Ryunosuke::Ryunosuke(cocos2d::Vec2 position) :
				Character(CollisionHandlers::Characters::Ryunosuke::ConcreteCollisionHandlerBuilder::getInstance().getCollisionHandler(),
                          (new States::StateHandlers::Ryunosuke::StateHandlerBuilder(*this))->getStateHandler(),
                          position, cocos2d::Vec2::ANCHOR_MIDDLE, "RyunosukeAttack0D.png", 0.0, cocos2d::Sprite::create(INITIAL_RYUNOSUKE_TEXTURE)->getContentSize(), new Physics::PhysicBox(
                                static_cast<int>(CollisionHandlers::Bitmasks::RYUNOSUKE), cocos2d::Sprite::create(INITIAL_RYUNOSUKE_TEXTURE)->getContentSize()
                        )
                ) {

				assert(&position);

				this->getPhysic().setRotationEnable(false);
				this->getPhysic().setContactTestBitmask(true);
				this->getPhysic().setFriction(0.0);
			}

			Ryunosuke::~Ryunosuke() {

			}

			void Ryunosuke::accept(CharacterVisitor &characterVisitor) {
				characterVisitor.visit(*this);
			}

            void Ryunosuke::reject(CharacterVisitor &characterVisitor) {
                characterVisitor.unvisit(*this);
            }

			void Ryunosuke::setCollisionEventDispatchers() {
				cocos2d::EventListenerPhysicsContact *contactListener = cocos2d::EventListenerPhysicsContact::create();
				contactListener->onContactBegin = CC_CALLBACK_1(NinjaNoMeiyo::Models::Characters::Ryunosuke::onContactBegin, this);
				contactListener->onContactSeparate = CC_CALLBACK_1(NinjaNoMeiyo::Models::Characters::Ryunosuke::onContactSeparate, this);
				this->addEventListenerWithSceneGraphPriority(contactListener);
			}

			bool Ryunosuke::onContactBegin(cocos2d::PhysicsContact &contact) {
				cocos2d::PhysicsBody *a = contact.getShapeA()->getBody();
				cocos2d::PhysicsBody *b = contact.getShapeB()->getBody();

				
				if (a->getCollisionBitmask() == static_cast<int>(CollisionHandlers::Bitmasks::FIXED_OBSTACLE) || b->getCollisionBitmask() == static_cast<int>(CollisionHandlers::Bitmasks::FIXED_OBSTACLE)) {
					return true;
				}

				if (a->getCollisionBitmask() == static_cast<int>(CollisionHandlers::Bitmasks::RYUNOSUKE) || b->getCollisionBitmask() == static_cast<int>(CollisionHandlers::Bitmasks::RYUNOSUKE)) {
					CollisionHandlers::CollisionResult *collisionResult = this->collisionHandler.handle(
						*(a->getCollisionBitmask() != static_cast<int>(CollisionHandlers::Bitmasks::RYUNOSUKE) ?
							a->getLinkedNode() :
							b->getLinkedNode()
							)
					);

					if (collisionResult->getBitmask() != CollisionHandlers::Bitmasks::FIXED_OBSTACLE) {
						this->nodesInContact.insert(std::make_pair<int, cocos2d::Node*>(static_cast<int>(collisionResult->getBitmask()), &collisionResult->getNode()));
						this->notifyCurrentStateIfChanged(Interaction::COLLISION);
					}
				}

				return false;
			}

			void Ryunosuke::onContactSeparate(cocos2d::PhysicsContact &contact) {
				cocos2d::PhysicsBody *a = contact.getShapeA()->getBody();
				cocos2d::PhysicsBody *b = contact.getShapeB()->getBody();

				if (a->getCollisionBitmask() == static_cast<int>(CollisionHandlers::Bitmasks::RYUNOSUKE) || b->getCollisionBitmask() == static_cast<int>(CollisionHandlers::Bitmasks::RYUNOSUKE)) {

					cocos2d::Node *nodeToErase = a->getCollisionBitmask() != static_cast<int>(CollisionHandlers::Bitmasks::RYUNOSUKE) ?
						a->getLinkedNode() :
						b->getLinkedNode();

					for (auto it = this->nodesInContact.begin(); it != this->nodesInContact.end(); ) {
						if (it->second == nodeToErase) {
							it = this->nodesInContact.erase(it);
                            this->notifyCurrentStateIfChanged(Interaction::SEPARATION);
						}
						else {
							it++;
						}
					}
				}
			}

		}
	}
}