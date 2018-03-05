#ifndef NINJANOMEIYO_CONTROLLERS_CHARACTERS_JUMPER_H
#define NINJANOMEIYO_CONTROLLERS_CHARACTERS_JUMPER_H

#include "./CharacterCommand.h"
#include "../Sense.h"
#include "../../Models/Characters/Visitors/Models/ModelJumper.h"
#include "../../Models/Characters/Visitors/Animations/AnimationJumper.h"

namespace NinjaNoMeiyo {
	namespace Controllers {
		namespace Characters {

			class Jumper : public CharacterCommand {
			public:
				Jumper(bool stoppable, Models::Characters::Character &character, Sense sense);
				virtual ~Jumper();

			};
		}
	}
}

#endif