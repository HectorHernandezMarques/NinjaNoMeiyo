#include "./Character.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {

			Character::Character(cocos2d::Vec2 position, cocos2d::Vec2 anchorPoint, std::string texture, float rotation, Physics::Physic *physic) :
					Node(position, anchorPoint, texture, rotation, physic) {

				assert(&position);
				assert(&anchorPoint);

				this->getPhysic().setRotationEnable(false);
			}

			Character::~Character() {
			}

		}
	}
}