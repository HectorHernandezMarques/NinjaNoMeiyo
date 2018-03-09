#include "./Jumper.h"

namespace NinjaNoMeiyo {
	namespace Controllers {
		namespace Characters {

			Jumper::Jumper(bool stoppable, Models::Characters::Character &character, Models::Characters::Sense sense) : CharacterCommand(stoppable, character) {

				this->modelVisitor = new NinjaNoMeiyo::Models::Characters::Visitors::Models::ModelJumper(sense);
				this->animationVisitor = new NinjaNoMeiyo::Models::Characters::Visitors::Animations::AnimationJumper(sense);
			}

			Jumper::~Jumper() {
			}

		}
	}
}