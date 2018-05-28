#ifndef NINJANOMEIYO_CONTROLLERS_CHARACTER_JUMPER_H
#define NINJANOMEIYO_CONTROLLERS_CHARACTER_JUMPER_H

#include "./CharacterCommand.h"
#include "../../Models/Characters/Sense.h"
#include "../../Models/Characters/Visitors/Models/ModelJumper.h"
#include "../../Models/Characters/Visitors/Animations/AnimationJumper.h"

namespace NinjaNoMeiyo {
	namespace Controllers {
		namespace Character {

			class Jumper : public CharacterCommand {
			public:
				Jumper(bool stoppable, Models::Characters::Character &character, Models::Characters::Sense sense);
				virtual ~Jumper();

			};
		}
	}
}

#endif