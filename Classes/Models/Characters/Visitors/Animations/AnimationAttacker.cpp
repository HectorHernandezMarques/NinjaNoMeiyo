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
							this->animationAction = ryunosuke.getCurrentState().attackAnimation(this->sense);
						this->characterMutex.unlock();
					}

					void AnimationAttacker::update(Aspects::Characters::Aspect &aspect) {
						aspect.visit(*this);
					}

					void AnimationAttacker::setState(States::State &state, Interaction interactionType) {
						this->characterMutex.lock();
							this->character->stopAction(this->animationAction);
							this->animationAction = state.attackAnimation(this->sense);
						this->characterMutex.unlock();
					}
				}
			}
		}
	}
}