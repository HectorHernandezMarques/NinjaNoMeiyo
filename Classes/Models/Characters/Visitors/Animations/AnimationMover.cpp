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
						this->characterMutex.lock();
							CharacterVisitor::visit(ryunosuke);
							this->character = &ryunosuke;
							this->animationAction = ryunosuke.getCurrentState().moveAnimation(this->xVelocity);
						this->characterMutex.unlock();
					}

					void AnimationMover::update(Aspects::Characters::Aspect &aspect) {
						aspect.visit(*this);
					}

					void AnimationMover::setState(States::State &state) {
						this->characterMutex.lock();
							this->character->stopAction(this->animationAction);
							this->animationAction = state.moveAnimation(this->xVelocity);
						this->characterMutex.unlock();
					}
				}
			}
		}
	}
}