#include "./ConcreteCollisionHandler.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace CollisionHandlers {
				namespace Ryunosuke {

					ConcreteCollisionHandler::ConcreteCollisionHandler(Bitmasks bitmaskToHandle) : CollisionHandler(), bitmaskToHandle(bitmaskToHandle) {

					}

					ConcreteCollisionHandler::~ConcreteCollisionHandler() {

					}

					bool ConcreteCollisionHandler::canHandle(cocos2d::Node &node) {
						return node.getPhysicsBody()->getCategoryBitmask() == static_cast<int>(this->bitmaskToHandle);
					}

					CollisionResult* ConcreteCollisionHandler::handle(cocos2d::Node &node) {
						return new CollisionResult(node, this->bitmaskToHandle);
					}

				}
			}
		}
	}
}