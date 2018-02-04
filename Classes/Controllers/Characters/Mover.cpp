#include "./Mover.h"

namespace NinjaNoMeiyo {
	namespace Controllers {
		namespace Characters {

			Mover::Mover(bool stoppable, Models::Characters::Character &character, Sense sense) : CharacterCommand(stoppable, character) {
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

				this->modelVisitor = new NinjaNoMeiyo::Models::Characters::Visitors::Models::ModelMover(this->xVelocity);
				this->animationVisitor = new NinjaNoMeiyo::Models::Characters::Visitors::Animations::AnimationMover(this->xVelocity);
			}

			Mover::~Mover() {
			}

		}
	}
}