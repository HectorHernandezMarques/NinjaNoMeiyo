#include "./CollisionHandler.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace CollisionHandlers {

			CollisionHandler::CollisionHandler() : next(nullptr) {
			}

			CollisionHandler::CollisionHandler(CollisionHandler &next) : next(&next) {
			}

			CollisionHandler::~CollisionHandler() {
			}

			CollisionResult* CollisionHandler::handle(cocos2d::Node &node) {
				if (this->hasNext()) {
					return this->next->handle(node);
				}
				else {
					return new CollisionResult(node, Bitmasks::UNKNOWN_BITMASK);
				}
			}

			bool CollisionHandler::hasNext() {
				return this->next != nullptr;
			}

			void CollisionHandler::setNext(CollisionHandler &collisionHandler) {
				this->next = &collisionHandler;
			}
		}
	}
}