#include "./Ryunosuke.h"
#include "./CharacterVisitor.h"
#include "./States/Ryunosuke/Floor.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {

			Ryunosuke::Ryunosuke(cocos2d::Vec2 position, cocos2d::Vec2 anchorPoint) :
				Character(position, anchorPoint, INITIAL_RYUNOSUKE_TEXTURE, 0.0, new Physics::PhysicBox(
					static_cast<int>(CollisionHandlers::Bitmasks::RYUNOSUKE), cocos2d::Sprite::create(INITIAL_RYUNOSUKE_TEXTURE)->getContentSize())
				),
				collisionHandler(CollisionHandlers::Ryunosuke::ConcreteCollisionHandlerBuilder::getInstance().getCollisionHandler()) {

				assert(&position);
				assert(&anchorPoint);

				this->getPhysic().setRotationEnable(false);
				this->getPhysic().setContactTestBitmask(true);
				this->getPhysic().setFriction(0.0);
			}

			Ryunosuke::~Ryunosuke() {
			}

			void Ryunosuke::accept(CharacterVisitor &characterVisitor) {
				characterVisitor.visit(*this);
			}

			States::State& Ryunosuke::getCurrentState() {
				return *new States::Ryunosuke::Floor(*this);
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

				bool result = false;

				if (a->getCollisionBitmask() == static_cast<int>(CollisionHandlers::Bitmasks::RYUNOSUKE) || b->getCollisionBitmask() == static_cast<int>(CollisionHandlers::Bitmasks::RYUNOSUKE)) {
					CollisionHandlers::CollisionResult *collisionResult = this->collisionHandler.handle(
						*(a->getCollisionBitmask() != static_cast<int>(CollisionHandlers::Bitmasks::RYUNOSUKE) ?
							a->getLinkedNode() :
							b->getLinkedNode()
						)
					);

					if (collisionResult->getBitmask() == CollisionHandlers::Bitmasks::FIXED_OBSTACLE) {
						CCLOG("FIXED_OBSTACLE");
						result = true;
					}
					else {
						CCLOG("NON_FIXED_OBSTACLE: %d", collisionResult->getBitmask());
						//TODO SAVE RESULT ON SOMEHOW COLLECTION
					}
				}

				return result;
			}

			bool Ryunosuke::onContactSeparate(cocos2d::PhysicsContact &contact) {
				//TODO REMOVE RESULTS UPTHERE ADDED
			}

		}
	}
}