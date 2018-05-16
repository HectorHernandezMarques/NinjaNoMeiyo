#include "./CharacterCommand.h"
#include "../../Models/Characters/Visitors/Animations/AnimationVisitor.h"

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

				this->character.reject(*this->modelVisitor);
				this->character.reject(*this->animationVisitor);
			}

			void CharacterCommand::execute() {
				assert(this->modelVisitor);
				assert(this->animationVisitor);

				this->character.accept(*this->modelVisitor);
				this->character.accept(*this->animationVisitor);
			}

			void CharacterCommand::update(Models::Characters::Visitors::Animations::Aspects::AnimationVisitor::Aspect &aspect) {
				aspect.visit(*this);
			}
		}
	}
}