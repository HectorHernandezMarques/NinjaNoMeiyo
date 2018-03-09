#ifndef NINJANOMEIYO_CONTROLLERS_CHARACTERS_STOPPER_H
#define NINJANOMEIYO_CONTROLLERS_CHARACTERS_STOPPER_H

#include "./CharacterCommand.h"
#include "../../Models/Characters/Visitors/Models/ModelStopper.h"
#include "../../Models/Characters/Visitors/Animations/AnimationStopper.h"

namespace NinjaNoMeiyo {
	namespace Controllers {
		namespace Characters {

			class Stopper : public CharacterCommand {
			public:
				Stopper(bool stoppable, Models::Characters::Character &character);
				virtual ~Stopper();

			};
		}
	}
}

#endif