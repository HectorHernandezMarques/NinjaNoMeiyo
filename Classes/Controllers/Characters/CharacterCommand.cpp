#include "./CharacterCommand.h"

namespace NinjaNoMeiyo {
	namespace Controllers {
		namespace Characters {

			CharacterCommand::CharacterCommand(bool stoppable, Models::Characters::Character &character) : Command(stoppable), character(character), modelVisitor(nullptr), animationVisitor(nullptr) {
			}

			CharacterCommand::~CharacterCommand() {
			}

			void CharacterCommand::stop() {
				assert(this->modelVisitor);
				assert(this->animationVisitor);

				this->character.stopAction(this->modelVisitor->getAction());
				this->character.stopAction(this->animationVisitor->getAction());
				this->character.stopAction(this->animationVisitor->getAnimationAction());
			}

			void CharacterCommand::execute() {
				assert(this->modelVisitor);
				assert(this->animationVisitor);

				this->character.accept(*this->animationVisitor);
				this->character.accept(*this->modelVisitor);
			}
		}
	}
}