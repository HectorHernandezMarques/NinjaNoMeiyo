#include "./CharacterVisitor.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {

			CharacterVisitor::CharacterVisitor() : character(nullptr){
			}

			CharacterVisitor::~CharacterVisitor() {
			}

			void CharacterVisitor::visit(Ryunosuke &ryunosuke) {
				ryunosuke.attach(*this);
				this->character = &ryunosuke;
			}

			void CharacterVisitor::unvisit(Ryunosuke &ryunosuke) {
				ryunosuke.detach(*this);
				this->character = nullptr;
			}
		}
	}
}