#ifndef NINJANOMEIYO_CONTROLLERS_CHARACTERS_STOPPER_H
#define NINJANOMEIYO_CONTROLLERS_CHARACTERS_STOPPER_H

#define RYUNOSUKE_SPEED 750

#include "./CharacterCommand.h"
#include "../Sense.h"
#include "../../Models/Characters/Visitors/Models/ModelStopper.h"
#include "../../Models/Characters/Visitors/Animations/AnimationStopper.h"

namespace NinjaNoMeiyo {
	namespace Controllers {
		namespace Characters {

			class Stopper : public CharacterCommand {
			public:
				Stopper(bool stoppable, Models::Characters::Character &character, Sense sense);
				virtual ~Stopper();

				void execute();

			private:
				float xVelocity;
			};
		}
	}
}

#endif