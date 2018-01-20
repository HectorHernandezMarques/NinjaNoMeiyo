#include "./Stopper.h"

namespace NinjaNoMeiyo {
	namespace Controllers {
		namespace Characters {

			Stopper::Stopper(bool stoppable, Models::Characters::Character &character, Sense sense) : CharacterCommand(stoppable, character) {
				switch (sense) {
				case Controllers::Sense::LEFT:
					this->xVelocity = -RYUNOSUKE_SPEED;
					break;

				case Controllers::Sense::RIGHT:
					this->xVelocity = RYUNOSUKE_SPEED;
					break;

				default:
					assert(false);
				}
			}

			Stopper::~Stopper() {
			}

			void Stopper::execute() {
				NinjaNoMeiyo::Models::Characters::Visitors::Models::ModelStopper modelStopper(this->xVelocity);
				this->character.accept(modelStopper);
				NinjaNoMeiyo::Models::Characters::Visitors::Animations::AnimationStopper animationStopper(this->xVelocity);
				this->character.accept(animationStopper);
				this->animationAction = animationStopper.getAnimationAction();
			}
		}
	}
}