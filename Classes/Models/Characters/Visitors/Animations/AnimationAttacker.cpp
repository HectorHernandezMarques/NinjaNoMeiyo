#include "./AnimationAttacker.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace Visitors {
				namespace Animations {

					AnimationAttacker::AnimationAttacker(Sense sense) : AnimationVisitor(), sense(sense) {
					}

					AnimationAttacker::~AnimationAttacker() {
					}

					void AnimationAttacker::visit(Ryunosuke &ryunosuke) {
						this->characterMutex.lock();
							CharacterVisitor::visit(ryunosuke);
							this->animation = ryunosuke.getCurrentState().attackAnimation(this->sense);
							this->animation->attach(*this);
							this->animation->animate();
						this->characterMutex.unlock();
					}

					void AnimationAttacker::update(Characters::Aspects::Characters::Aspect &aspect) {
						aspect.visit(*this);
					}

					void AnimationAttacker::setState(States::State &state, Interaction interactionType) {
						this->characterMutex.lock();
							this->animation->detach(*this);
							this->animation->stopAnimation();
							this->animation = state.attackAnimation(this->sense);
							this->animation->attach(*this);
							this->animation->animate();
						this->characterMutex.unlock();
					}
				}
			}
		}
	}
}