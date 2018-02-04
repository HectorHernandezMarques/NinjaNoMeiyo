#include "./AnimationVisitor.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace Visitors {
				namespace Animations {

					AnimationVisitor::AnimationVisitor() : CharacterVisitor(), animationAction(nullptr) {
					}

					AnimationVisitor::~AnimationVisitor() {
					}

					cocos2d::Action* AnimationVisitor::getAnimationAction() {
						return this->animationAction;
					}
				}
			}
		}
	}
}