#include "./CollisionResult.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace CollisionHandlers {

				CollisionResult::CollisionResult(cocos2d::Node &node, Bitmasks bitmask) : node(node), bitmask(bitmask) {
				}

				CollisionResult::~CollisionResult() {
				}

				cocos2d::Node& CollisionResult::getNode() {
					return this->node;
				}

				Bitmasks CollisionResult::getBitmask() {
					return this->bitmask;
				}

			}
		}
	}
}