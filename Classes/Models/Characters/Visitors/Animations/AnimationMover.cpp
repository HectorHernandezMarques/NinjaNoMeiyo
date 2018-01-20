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
						this->animationAction = ryunosuke.getCurrentState().moveAnimation(this->xVelocity);
					}
				}
			}
		}
	}
}