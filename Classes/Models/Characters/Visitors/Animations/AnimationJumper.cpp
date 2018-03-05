#include "./AnimationJumper.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace Visitors {
				namespace Animations {

					AnimationJumper::AnimationJumper(Controllers::Sense sense) : AnimationVisitor(sense) {
					}

					AnimationJumper::~AnimationJumper() {
					}

					void AnimationJumper::visit(Ryunosuke &ryunosuke) {
						this->characterMutex.lock();
							CharacterVisitor::visit(ryunosuke);
							this->character = &ryunosuke;
							this->animationAction = ryunosuke.getCurrentState().jumpAnimation(this->sense);
						this->characterMutex.unlock();
					}

					void AnimationJumper::update(Aspects::Characters::Aspect &aspect) {
						aspect.visit(*this);
					}

					void AnimationJumper::setState(States::State &state, Interaction interactionType) {
						this->characterMutex.lock();
						if (interactionType == Interaction::COLLISION) {
							this->character->stopAction(this->animationAction);
							this->animationAction = state.stopAnimation(this->sense);
						}
						this->characterMutex.unlock();
					}
				}
			}
		}
	}
}