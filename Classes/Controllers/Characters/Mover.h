#ifndef NINJANOMEIYO_CONTROLLERS_CHARACTERS_MOVER_H
#define NINJANOMEIYO_CONTROLLERS_CHARACTERS_MOVER_H

#include "./CharacterCommand.h"
#include "../../Models/Characters/Sense.h"
#include "../../Models/Characters/Visitors/Models/ModelMover.h"
#include "../../Models/Characters/Visitors/Animations/AnimationMover.h"

namespace NinjaNoMeiyo {
	namespace Controllers {
		namespace Characters {

			class Mover : public CharacterCommand {
			public:
				Mover(bool stoppable, Models::Characters::Character &character, Models::Characters::Sense sense);
				virtual ~Mover();

			};
		}
	}
}

#endif