#include "./Attacker.h"

namespace NinjaNoMeiyo {
	namespace Controllers {
		namespace Characters {

			Attacker::Attacker(bool stoppable, Models::Characters::Character &character, Models::Characters::Sense sense) : CharacterCommand(stoppable, character) {

				this->modelVisitor = new NinjaNoMeiyo::Models::Characters::Visitors::Models::ModelAttacker(sense);
				this->animationVisitor = new NinjaNoMeiyo::Models::Characters::Visitors::Animations::AnimationAttacker(sense);
			}

			Attacker::~Attacker() {
			}

		}
	}
}