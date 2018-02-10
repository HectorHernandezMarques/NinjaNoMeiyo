#include "./PhysicBox.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Physics {

			PhysicBox::PhysicBox(int bitmask, cocos2d::Size size) : size(size), Physic(this->init(bitmask, size)) {
			}

			PhysicBox::~PhysicBox() {
			}

			cocos2d::PhysicsBody& PhysicBox::init(int bitmask, cocos2d::Size &size) {
				cocos2d::PhysicsBody &result = *cocos2d::PhysicsBody::createBox(size);
				result.setCategoryBitmask(bitmask);
				//result.setContactTestBitmask(true);
				return result;
			}
		}
	}
}