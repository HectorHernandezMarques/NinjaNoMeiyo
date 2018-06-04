#ifndef NINJANOMEIYO_CONTROLLERS_CHARACTER_ATTACKER_H
#define NINJANOMEIYO_CONTROLLERS_CHARACTER_ATTACKER_H

#include "./CharacterCommand.h"
#include "../../Models/Characters/Sense.h"
#include "../../Models/Characters/Visitors/Models/ModelAttacker.h"
#include "../../Models/Characters/Visitors/Animations/AnimationAttacker.h"
#include "../../Models/Environment/Damager.h"

namespace NinjaNoMeiyo {
	namespace Controllers {
		namespace Character {

			class Attacker : public CharacterCommand {
			public:
				Attacker(bool stoppable, Models::Characters::Character &character, Models::Characters::Sense sense);
				virtual ~Attacker();

				void execute();
				void stop();

			private:
				Models::Environment::Damager *damager;
				Views::Node *damagerView;
				
			};
		}
	}
}

#endif