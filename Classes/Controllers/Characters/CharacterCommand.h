#ifndef NINJANOMEIYO_CONTROLLERS_CHARACTERS_CHARACTERCOMMAND_H
#define NINJANOMEIYO_CONTROLLERS_CHARACTERS_CHARACTERCOMMAND_H

#include "../Command.h"
#include "../../Models/Characters/Character.h"
namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace Visitors {
				namespace Animations {

					class AnimationVisitor;
				}
			}
		}
	}
}

namespace NinjaNoMeiyo {
	namespace Controllers {
		namespace Characters {

			class CharacterCommand : public Command {
			public:
				CharacterCommand(bool stoppable, Models::Characters::Character &character);
				virtual ~CharacterCommand();

				virtual void execute();
				virtual void stop();
				void update(Models::Characters::Visitors::Animations::Aspects::AnimationVisitor::Aspect &aspect);

			protected:
				Models::Characters::Character &character;
				NinjaNoMeiyo::Models::Characters::CharacterVisitor *modelVisitor;
				NinjaNoMeiyo::Models::Characters::Visitors::Animations::AnimationVisitor *animationVisitor;
			};
		}
	}
}

#endif