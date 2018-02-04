#include "./AnimationMover.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace Visitors {
				namespace Animations {

					AnimationMover::AnimationMover(float xVelocity) : AnimationVisitor(), xVelocity(xVelocity) {
					}

					AnimationMover::~AnimationMover() {
					}

					void AnimationMover::visit(Ryunosuke &ryunosuke) {
						cocos2d::Action *action = cocos2d::RepeatForever::create(cocos2d::Sequence::create(cocos2d::CallFunc::create(CC_CALLBACK_0(AnimationMover::visitFunction, this, ryunosuke)), nullptr));
						ryunosuke.runAction(action);
						this->action = action;
					}

					void AnimationMover::visitFunction(Ryunosuke &ryunosuke) {
						ryunosuke.stopAction(this->animationAction);
						this->animationAction = ryunosuke.getCurrentState().moveAnimation(this->xVelocity);
					}
				}
			}
		}
	}
}