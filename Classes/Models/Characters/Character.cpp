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

			void Character::attach(Observers::CharacterObserver &characterObserver) {
				this->characterObservers.insert(&characterObserver);
			}

			void Character::detach(Observers::CharacterObserver &characterObserver) {
				this->characterObservers.erase(&characterObserver);
			}

			void Character::notify(Aspects::Characters::Aspect &aspect) {
				for (auto it = this->characterObservers.begin(); it != this->characterObservers.end(); ++it) {
					(*it)->update(aspect);
				}
			}
		}
	}
}