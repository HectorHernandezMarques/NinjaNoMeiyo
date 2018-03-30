#ifndef NINJANOMEIYO_CONTROLLERS_CHARACTERS_ATTACKER_H
#define NINJANOMEIYO_CONTROLLERS_CHARACTERS_ATTACKER_H

#include "./CharacterCommand.h"
#include "../../Models/Characters/Sense.h"
#include "../../Models/Characters/Visitors/Models/ModelAttacker.h"
#include "../../Models/Characters/Visitors/Animations/AnimationAttacker.h"

namespace NinjaNoMeiyo {
	namespace Controllers {
		namespace Characters {

			class Attacker : public CharacterCommand {
			public:
				Attacker(bool stoppable, Models::Characters::Character &character, Models::Characters::Sense sense);
				virtual ~Attacker();

			};
		}
	}
}

#endif