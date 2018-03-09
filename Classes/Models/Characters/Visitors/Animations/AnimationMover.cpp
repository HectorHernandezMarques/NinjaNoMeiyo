#include "./AnimationMover.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace Visitors {
				namespace Animations {

					AnimationMover::AnimationMover(Sense sense) : AnimationVisitor(), sense(sense) {
					}

					AnimationMover::~AnimationMover() {
					}

					void AnimationMover::visit(Ryunosuke &ryunosuke) {
						this->characterMutex.lock();
							CharacterVisitor::visit(ryunosuke);
							this->animationAction = ryunosuke.getCurrentState().moveAnimation(this->sense);
						this->characterMutex.unlock();
					}

					void AnimationMover::update(Aspects::Characters::Aspect &aspect) {
						aspect.visit(*this);
					}

					void AnimationMover::setState(States::State &state, Interaction interactionType) {
						this->characterMutex.lock();
							this->character->stopAction(this->animationAction);
							this->animationAction = state.moveAnimation(this->sense);
						this->characterMutex.unlock();
					}
				}
			}
		}
	}
}