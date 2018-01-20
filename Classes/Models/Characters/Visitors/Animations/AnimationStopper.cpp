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
						this->animationAction = ryunosuke.getCurrentState().stopAnimation(this->xVelocity);
					}
				}
			}
		}
	}
}