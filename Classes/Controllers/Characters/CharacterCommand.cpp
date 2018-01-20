#include "./CharacterCommand.h"

namespace NinjaNoMeiyo {
	namespace Controllers {
		namespace Characters {

			CharacterCommand::CharacterCommand(bool stoppable, Models::Characters::Character &character) : Command(stoppable), character(character){
			}

			CharacterCommand::~CharacterCommand() {
			}

			void CharacterCommand::stop() {
				this->character.stopAction(this->animationAction);
			}
		}
	}
}