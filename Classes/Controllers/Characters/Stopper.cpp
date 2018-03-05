#include "./Stopper.h"

namespace NinjaNoMeiyo {
	namespace Controllers {
		namespace Characters {

			Stopper::Stopper(bool stoppable, Models::Characters::Character &character, Sense sense) : CharacterCommand(stoppable, character) {

				this->modelVisitor = new NinjaNoMeiyo::Models::Characters::Visitors::Models::ModelStopper(sense);
				this->animationVisitor = new NinjaNoMeiyo::Models::Characters::Visitors::Animations::AnimationStopper(sense);
			}

			Stopper::~Stopper() {
			}

		}
	}
}