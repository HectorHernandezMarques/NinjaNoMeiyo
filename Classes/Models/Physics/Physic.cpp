#include "./Physic.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Physics {

			Physic::Physic(cocos2d::PhysicsBody &physic) : physic(physic) {
				assert(&physic);
			}


			Physic::~Physic() {
			}

			cocos2d::PhysicsBody& Physic::getPhysic() {
				assert(&this->physic);

				return this->physic;
			}

			cocos2d::Vec2 Physic::getVelocity() {
				assert(&this->physic);

				return this->physic.getVelocity();
			}

			void Physic::setDynamic(bool dynamic) {

				this->physic.setDynamic(dynamic);
			}

			void Physic::setCategoryBitmask(int bitmask) {
				assert(&this->physic);

				this->physic.setCategoryBitmask(bitmask);

			}

			void Physic::setCollisionBitmask(int bitmask) {
				assert(&this->physic);

				this->physic.setCollisionBitmask(bitmask);
			}

			void Physic::setContactTestBitmask(int bitmask) {
				assert(&this->physic);

				this->physic.setContactTestBitmask(bitmask);
			}

			void Physic::setRotationEnable(bool enable) {
				assert(&this->physic);

				this->physic.setRotationEnable(enable);
			}

			void Physic::setVelocity(cocos2d::Vec2 velocity) {
				assert(&this->physic);
				assert(&velocity);

				this->physic.setVelocity(velocity);
			}

			void Physic::setFriction(float friction) {
				assert(&this->physic);

				for (auto it = this->physic.getShapes().begin(); it != this->physic.getShapes().end(); ++it) {
					(*it)->setFriction(friction);
				}
			}
		}
	}
}