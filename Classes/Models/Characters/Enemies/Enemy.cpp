#include "./Enemy.h"
#include "../CharacterVisitor.h"
#include "../States/Enemies/Enemy/UnknownState.h"
#include "../States/StateHandlers/Enemies/Enemy/StateHandlerBuilder.h"
#include "../../CollisionHandlers/Characters/Enemies/Enemy/ConcreteCollisionHandlerBuilder.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace Enemies {

				Enemy::Enemy(cocos2d::Vec2 position) :
					Character(CollisionHandlers::Characters::Enemies::Enemy::ConcreteCollisionHandlerBuilder::getInstance().getCollisionHandler(),
					(new States::StateHandlers::Enemies::Enemy::StateHandlerBuilder(*this))->getStateHandler(),
						position, cocos2d::Vec2::ANCHOR_MIDDLE, INITIAL_ENEMY_TEXTURE, 0.0, cocos2d::Sprite::create(INITIAL_ENEMY_TEXTURE)->getContentSize(), new Physics::PhysicBox(
							static_cast<int>(CollisionHandlers::Bitmasks::ENEMY), cocos2d::Sprite::create(INITIAL_ENEMY_TEXTURE)->getContentSize()
						)
					) {

					assert(&position);

					this->getPhysic().setRotationEnable(false);
					this->getPhysic().setContactTestBitmask(true);
					this->getPhysic().setFriction(0.0);
					//this->getPhysic().setDynamic(false);
				}

				Enemy::~Enemy() {

				}

				void Enemy::accept(CharacterVisitor &characterVisitor) {
					//characterVisitor.visit(*this);
				}

				void Enemy::reject(CharacterVisitor &characterVisitor) {
					//characterVisitor.unvisit(*this);
				}

				void Enemy::setCollisionEventDispatchers() {
					cocos2d::EventListenerPhysicsContact *contactListener = cocos2d::EventListenerPhysicsContact::create();
					contactListener->onContactBegin = CC_CALLBACK_1(NinjaNoMeiyo::Models::Characters::Enemies::Enemy::onContactBegin, this);
					contactListener->onContactSeparate = CC_CALLBACK_1(NinjaNoMeiyo::Models::Characters::Enemies::Enemy::onContactSeparate, this);
					this->addEventListenerWithSceneGraphPriority(contactListener);
				}

				bool Enemy::onContactBegin(cocos2d::PhysicsContact &contact) {
					cocos2d::PhysicsBody *a = contact.getShapeA()->getBody();
					cocos2d::PhysicsBody *b = contact.getShapeB()->getBody();

					if (a->getCollisionBitmask() == static_cast<int>(CollisionHandlers::Bitmasks::ENEMY) || b->getCollisionBitmask() == static_cast<int>(CollisionHandlers::Bitmasks::ENEMY)) {
						CollisionHandlers::CollisionResult *collisionResult = this->collisionHandler.handle(
							*(a->getCollisionBitmask() != static_cast<int>(CollisionHandlers::Bitmasks::ENEMY) ?
								a->getLinkedNode() :
								b->getLinkedNode()
								)
						);

						if (collisionResult->getBitmask() != CollisionHandlers::Bitmasks::FIXED_OBSTACLE) {
							this->nodesInContact.insert(std::make_pair<int, cocos2d::Node*>(static_cast<int>(collisionResult->getBitmask()), &collisionResult->getNode()));
							this->notifyCurrentStateIfChanged(Interaction::COLLISION);
							if (collisionResult->getBitmask() == CollisionHandlers::Bitmasks::DAMAGER) {
								this->setTexture(this->getTexture() == INITIAL_ENEMY_TEXTURE ? "EnemyInjured.png" : INITIAL_ENEMY_TEXTURE);
							}
						}
					}

					return false;
				}

				void Enemy::onContactSeparate(cocos2d::PhysicsContact &contact) {
					cocos2d::PhysicsBody *a = contact.getShapeA()->getBody();
					cocos2d::PhysicsBody *b = contact.getShapeB()->getBody();

					if (a->getCollisionBitmask() == static_cast<int>(CollisionHandlers::Bitmasks::ENEMY) || b->getCollisionBitmask() == static_cast<int>(CollisionHandlers::Bitmasks::ENEMY)) {

						cocos2d::Node *nodeToErase = a->getCollisionBitmask() != static_cast<int>(CollisionHandlers::Bitmasks::ENEMY) ?
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
}