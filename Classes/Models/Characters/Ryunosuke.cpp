#include "./Ryunosuke.h"
#include "./CharacterVisitor.h"
#include "./States/Ryunosuke/Floor.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {

			Ryunosuke::Ryunosuke(cocos2d::Vec2 position, cocos2d::Vec2 anchorPoint) :
					Character(position, anchorPoint, INITIAL_RYUNOSUKE_TEXTURE, 0.0, new Physics::PhysicBox(3, cocos2d::Sprite::create(INITIAL_RYUNOSUKE_TEXTURE)->getContentSize())) {

				assert(&position);
				assert(&anchorPoint);

				this->getPhysic().setRotationEnable(false);
				this->getPhysic().setFriction(0.0);
			}

			Ryunosuke::~Ryunosuke() {
			}

			void Ryunosuke::accept(CharacterVisitor &characterVisitor) {
				characterVisitor.visit(*this);
			}

			States::State& Ryunosuke::getCurrentState() {
				return *new States::Ryunosuke::Floor(*this);
			}

		}
	}
}