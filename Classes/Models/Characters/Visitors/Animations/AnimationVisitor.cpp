#include "./AnimationVisitor.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace Visitors {
				namespace Animations {

					AnimationVisitor::AnimationVisitor(Controllers::Sense sense) : CharacterVisitor(), characterMutex(), character(nullptr), animationAction(nullptr), sense(sense) {
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