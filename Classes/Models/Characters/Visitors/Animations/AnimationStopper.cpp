#include "./AnimationStopper.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace Visitors {
				namespace Animations {

					AnimationStopper::AnimationStopper(float xVelocity) : AnimationVisitor(), xVelocity(xVelocity) {
					}

					AnimationStopper::~AnimationStopper() {
					}

					void AnimationStopper::visit(Ryunosuke &ryunosuke) {
						cocos2d::Action *action = cocos2d::Sequence::create(cocos2d::CallFunc::create(CC_CALLBACK_0(AnimationStopper::visitFunction, this, ryunosuke)), cocos2d::DelayTime::create(3.0), nullptr);
						ryunosuke.runAction(action);
						this->action = action;
					}

					void AnimationStopper::visitFunction(Ryunosuke &ryunosuke) {
						this->animationAction = ryunosuke.getCurrentState().stopAnimation(this->xVelocity);
					}
				}
			}
		}
	}
}