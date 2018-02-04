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

				this->modelVisitor = new NinjaNoMeiyo::Models::Characters::Visitors::Models::ModelStopper(this->xVelocity);
				this->animationVisitor = new NinjaNoMeiyo::Models::Characters::Visitors::Animations::AnimationStopper(this->xVelocity);
			}

			Stopper::~Stopper() {
			}

		}
	}
}