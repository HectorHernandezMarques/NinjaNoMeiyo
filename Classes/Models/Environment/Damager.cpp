#include "./Damager.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Environment {

			Damager::Damager(cocos2d::Vec2 position, cocos2d::Size initialPhysicSize) :
					Node(position, cocos2d::Vec2::ANCHOR_MIDDLE, "", 0.0, new Physics::PhysicBox(
						static_cast<int>(CollisionHandlers::Bitmasks::RYUNOSUKE), initialPhysicSize)),
					initialPhysicSize(initialPhysicSize)
				{
				assert(&position);

				this->getPhysic().setRotationEnable(false);
			}

			Damager::~Damager() {
			}

			cocos2d::Size Damager::getInitialPhysicSize() {
				return this->initialPhysicSize;
			}

		}
	}
}