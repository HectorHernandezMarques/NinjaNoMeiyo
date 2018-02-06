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
						this->characterMutex.lock();
							this->character = &ryunosuke;
							this->animationAction = ryunosuke.getCurrentState().stopAnimation(this->xVelocity);
						this->characterMutex.unlock();
					}

					void AnimationStopper::update(Aspects::Characters::Aspect &aspect) {
						aspect.visit(*this);
					}

					void AnimationStopper::setState(States::State &state) {
						this->characterMutex.lock();
							this->character->stopAction(this->animationAction);
							this->animationAction = state.stopAnimation(this->xVelocity);
						this->characterMutex.unlock();
					}
				}
			}
		}
	}
}