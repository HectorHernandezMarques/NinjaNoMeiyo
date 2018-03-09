#include "./AnimationJumper.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace Visitors {
				namespace Animations {

					AnimationJumper::AnimationJumper(Sense sense) : AnimationVisitor(), sense(sense) {
					}

					AnimationJumper::~AnimationJumper() {
					}

					void AnimationJumper::visit(Ryunosuke &ryunosuke) {
						this->characterMutex.lock();
							CharacterVisitor::visit(ryunosuke);
							if(this->sense == Sense::RIGHT || this->sense == Sense::LEFT) {
								this->animationAction = ryunosuke.getCurrentState().jumpAnimation(this->sense);
							}
							else {
								this->animationAction = ryunosuke.getCurrentState().jumpAnimation(this->character->getSense());
							}
						this->characterMutex.unlock();
					}

					void AnimationJumper::update(Aspects::Characters::Aspect &aspect) {
						aspect.visit(*this);
					}

					void AnimationJumper::setState(States::State &state, Interaction interactionType) {
						this->characterMutex.lock();
						if (interactionType == Interaction::COLLISION) {
							this->character->stopAction(this->animationAction);
							if(this->sense == Sense::RIGHT || this->sense == Sense::LEFT) {
								this->animationAction = state.jumpAnimation(this->sense);
							}
							else {
								this->animationAction = state.stopAnimation(this->character->getSense());
							}
						}
						this->characterMutex.unlock();
					}
				}
			}
		}
	}
}