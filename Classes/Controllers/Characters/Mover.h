#ifndef NINJANOMEIYO_CONTROLLERS_CHARACTERS_MOVER_H
#define NINJANOMEIYO_CONTROLLERS_CHARACTERS_MOVER_H

#define RYUNOSUKE_SPEED 750

#include "./CharacterCommand.h"
#include "../Sense.h"
#include "../../Models/Characters/Visitors/Models/ModelMover.h"
#include "../../Models/Characters/Visitors/Animations/AnimationMover.h"

namespace NinjaNoMeiyo {
	namespace Controllers {
		namespace Characters {

			class Mover : public CharacterCommand {
			public:
				Mover(bool stoppable, Models::Characters::Character &character, Sense sense);
				virtual ~Mover();

			private:
				float xVelocity;
			};
		}
	}
}

#endif