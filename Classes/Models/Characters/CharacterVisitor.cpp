#include "./CharacterVisitor.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {

			CharacterVisitor::CharacterVisitor() : action(nullptr) {
			}

			CharacterVisitor::~CharacterVisitor() {
			}

			cocos2d::Action* CharacterVisitor::getAction() {
				return this->action;
			}
		}
	}
}