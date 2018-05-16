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
							this->animation = ryunosuke.getCurrentState().stopAnimation(this->character->getSense());
							this->animation->attach(*this);
							this->animation->animate();
						this->characterMutex.unlock();
					}

					void AnimationStopper::update(Characters::Aspects::Characters::Aspect &aspect) {
						aspect.visit(*this);
					}

					void AnimationStopper::setState(States::State &state, Interaction interactionType) {
						this->characterMutex.lock();
							this->animation->detach(*this);
							this->animation->stopAnimation();
							this->animation = state.stopAnimation(this->character->getSense());
							this->animation->attach(*this);
							this->animation->animate();
						this->characterMutex.unlock();
					}
				}
			}
		}
	}
}