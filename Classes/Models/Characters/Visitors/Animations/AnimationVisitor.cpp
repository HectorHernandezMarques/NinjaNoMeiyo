#include "./AnimationVisitor.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace Visitors {
				namespace Animations {

					AnimationVisitor::AnimationVisitor() : CharacterVisitor(), characterMutex(), character(nullptr), animationAction(nullptr) {
					}

					AnimationVisitor::~AnimationVisitor() {
					}

					void AnimationVisitor::unvisit(Ryunosuke &ryunosuke) {
						CharacterVisitor::unvisit(ryunosuke);
						ryunosuke.stopAction(this->animationAction);
					}

					cocos2d::Action* AnimationVisitor::getAnimationAction() {
						return this->animationAction;
					}
				}
			}
		}
	}
}