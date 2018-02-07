#include "./FloorCollisionHandler.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace CollisionHandlers {
				namespace Ryunosuke {

					FloorCollisionHandler::FloorCollisionHandler() : CollisionHandler() {

					}

					FloorCollisionHandler::~FloorCollisionHandler() {

					}

					bool FloorCollisionHandler::canHandle(cocos2d::Node &node) {
						return node.getPhysicsBody()->getCategoryBitmask() == Bitmasks::FLOOR;
					}

					CollisionResult* FloorCollisionHandler::handle(cocos2d::Node &node) {
						return new CollisionResult(node, Bitmasks::FLOOR);
					}

				}
			}
		}
	}
}