#include "./CharacterVisitor.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {

			CharacterVisitor::CharacterVisitor() : action(nullptr) {
			}

			CharacterVisitor::~CharacterVisitor() {
			}

			void CharacterVisitor::visit(Ryunosuke &ryunosuke) {
				ryunosuke.attach(*this);
			}

			cocos2d::Action* CharacterVisitor::getAction() {
				return this->action;
			}
		}
	}
}