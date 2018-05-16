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
								this->animation = ryunosuke.getCurrentState().jumpAnimation(this->sense);
							}
							else {
								this->animation = ryunosuke.getCurrentState().jumpAnimation(this->character->getSense());
							}
							this->animation->attach(*this);
							this->animation->animate();
						this->characterMutex.unlock();
					}

					void AnimationJumper::update(Characters::Aspects::Characters::Aspect &aspect) {
						aspect.visit(*this);
					}

					void AnimationJumper::setState(States::State &state, Interaction interactionType) {
						this->characterMutex.lock();
						if (interactionType == Interaction::COLLISION) {
							this->animation->detach(*this);
							this->animation->stopAnimation();
							if(this->sense == Sense::RIGHT || this->sense == Sense::LEFT) {
								this->animation = state.stopAnimation(this->sense);
							}
							else {
								this->animation = state.stopAnimation(this->character->getSense());
							}
							this->animation->attach(*this);
							this->animation->animate();
						}
						this->characterMutex.unlock();
					}
				}
			}
		}
	}
}