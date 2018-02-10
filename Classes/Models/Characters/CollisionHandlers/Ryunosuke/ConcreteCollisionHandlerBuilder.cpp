#include "./ConcreteCollisionHandlerBuilder.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace CollisionHandlers {
				namespace Ryunosuke {

					ConcreteCollisionHandlerBuilder *ConcreteCollisionHandlerBuilder::instance = new ConcreteCollisionHandlerBuilder();

					ConcreteCollisionHandlerBuilder::ConcreteCollisionHandlerBuilder() : collisionHandler(*new ConcreteCollisionHandler(Bitmasks::FIXED_OBSTACLE)) {
						this->collisionHandler.setNext(*new ConcreteCollisionHandler(Bitmasks::FLOOR));
						this->collisionHandler.setNext(*new ConcreteCollisionHandler(Bitmasks::RIGHT_OBSTACLE));
						this->collisionHandler.setNext(*new ConcreteCollisionHandler(Bitmasks::LEFT_OBSTACLE));
						this->collisionHandler.setNext(*new ConcreteCollisionHandler(Bitmasks::EDGE_FLOOR_RIGHT));
						this->collisionHandler.setNext(*new ConcreteCollisionHandler(Bitmasks::EDGE_FLOOR_LEFT));
						this->collisionHandler.setNext(*new ConcreteCollisionHandler(Bitmasks::EDGE_RIGHT_OBSTACLE));
						this->collisionHandler.setNext(*new ConcreteCollisionHandler(Bitmasks::EDGE_LEFT_OBSTACLE));
						this->collisionHandler.setNext(*new ConcreteCollisionHandler(Bitmasks::OIL_RIGHT_OBSTACLE));
						this->collisionHandler.setNext(*new ConcreteCollisionHandler(Bitmasks::OIL_LEFT_OBSTACLE));
					}

					ConcreteCollisionHandlerBuilder::~ConcreteCollisionHandlerBuilder() {

					}

					ConcreteCollisionHandlerBuilder& ConcreteCollisionHandlerBuilder::getInstance() {
						return *ConcreteCollisionHandlerBuilder::instance;
					}

					CollisionHandler& ConcreteCollisionHandlerBuilder::getCollisionHandler() {
						return this->collisionHandler;
					}

				}
			}
		}
	}
}