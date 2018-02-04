#ifndef NINJANOMEIYO_CONTROLLERS_CHARACTERS_CHARACTERCOMMAND_H
#define NINJANOMEIYO_CONTROLLERS_CHARACTERS_CHARACTERCOMMAND_H

#include "../Command.h"
#include "../../Models/Characters/Character.h"
#include "../../Models/Characters/Visitors/Animations/AnimationVisitor.h"

namespace NinjaNoMeiyo {
	namespace Controllers {
		namespace Characters {

			class CharacterCommand : public Command {
			public:
				CharacterCommand(bool stoppable, Models::Characters::Character &character);
				virtual ~CharacterCommand();

				void execute();
				void stop();

			protected:
				Models::Characters::Character &character;
				NinjaNoMeiyo::Models::Characters::CharacterVisitor *modelVisitor;
				NinjaNoMeiyo::Models::Characters::Visitors::Animations::AnimationVisitor *animationVisitor;
			};
		}
	}
}

#endif