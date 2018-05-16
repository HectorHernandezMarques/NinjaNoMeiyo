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
							this->animation = ryunosuke.getCurrentState().moveAnimation(this->sense);
							this->animation->attach(*this);
							this->animation->animate();
						this->characterMutex.unlock();
					}

					void AnimationMover::update(Characters::Aspects::Characters::Aspect &aspect) {
						aspect.visit(*this);
					}

					void AnimationMover::setState(States::State &state, Interaction interactionType) {
						this->characterMutex.lock();
							this->animation->detach(*this);
							this->animation->stopAnimation();
							this->animation = state.moveAnimation(this->sense);
							this->animation->attach(*this);
							this->animation->animate();
						this->characterMutex.unlock();
					}
				}
			}
		}
	}
}