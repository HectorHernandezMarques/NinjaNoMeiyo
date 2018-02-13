#include "./CharacterVisitor.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {

			CharacterVisitor::CharacterVisitor() {
			}

			CharacterVisitor::~CharacterVisitor() {
			}

			void CharacterVisitor::visit(Ryunosuke &ryunosuke) {
				ryunosuke.attach(*this);
			}

			void CharacterVisitor::unvisit(Ryunosuke &ryunosuke) {
				ryunosuke.detach(*this);
			}
		}
	}
}