#include "./Mover.h"

namespace NinjaNoMeiyo {
	namespace Controllers {
		namespace Characters {

			Mover::Mover(bool stoppable, Models::Characters::Character &character, Models::Characters::Sense sense) : CharacterCommand(stoppable, character) {

				this->modelVisitor = new NinjaNoMeiyo::Models::Characters::Visitors::Models::ModelMover(sense);
				this->animationVisitor = new NinjaNoMeiyo::Models::Characters::Visitors::Animations::AnimationMover(sense);
			}

			Mover::~Mover() {
			}

		}
	}
}