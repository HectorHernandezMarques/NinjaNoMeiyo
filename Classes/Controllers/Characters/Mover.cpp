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
			}

			Mover::~Mover() {
			}

			void Mover::execute() {
				NinjaNoMeiyo::Models::Characters::Visitors::Models::ModelMover modelMover(this->xVelocity);
				this->character.accept(modelMover);
				NinjaNoMeiyo::Models::Characters::Visitors::Animations::AnimationMover animationMover(this->xVelocity);
				this->character.accept(animationMover);
				this->animationAction = animationMover.getAnimationAction();
			}
		}
	}
}