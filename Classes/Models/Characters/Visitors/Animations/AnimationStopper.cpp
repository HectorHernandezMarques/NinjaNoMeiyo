#include "./AnimationStopper.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace Visitors {
				namespace Animations {

					AnimationStopper::AnimationStopper(Controllers::Sense sense) : AnimationVisitor(sense) {
					}

					AnimationStopper::~AnimationStopper() {
					}

					void AnimationStopper::visit(Ryunosuke &ryunosuke) {
						this->characterMutex.lock();
							CharacterVisitor::visit(ryunosuke);
							this->character = &ryunosuke;
							this->animationAction = ryunosuke.getCurrentState().stopAnimation(this->sense);
						this->characterMutex.unlock();
					}

					void AnimationStopper::update(Aspects::Characters::Aspect &aspect) {
						aspect.visit(*this);
					}

					void AnimationStopper::setState(States::State &state) {
						this->characterMutex.lock();
							this->character->stopAction(this->animationAction);
							this->animationAction = state.stopAnimation(this->sense);
						this->characterMutex.unlock();
					}
				}
			}
		}
	}
}