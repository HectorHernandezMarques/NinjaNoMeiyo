#include "./AnimationStopper.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace Visitors {
				namespace Animations {

					AnimationStopper::AnimationStopper() : AnimationVisitor() {
					}

					AnimationStopper::~AnimationStopper() {
					}

					void AnimationStopper::visit(Ryunosuke &ryunosuke) {
						this->characterMutex.lock();
							CharacterVisitor::visit(ryunosuke);
							this->animationAction = ryunosuke.getCurrentState().stopAnimation(this->character->getSense());
						this->characterMutex.unlock();
					}

					void AnimationStopper::update(Aspects::Characters::Aspect &aspect) {
						aspect.visit(*this);
					}

					void AnimationStopper::setState(States::State &state, Interaction interactionType) {
						this->characterMutex.lock();
							this->character->stopAction(this->animationAction);
							this->animationAction = state.stopAnimation(this->character->getSense());
						this->characterMutex.unlock();
					}
				}
			}
		}
	}
}