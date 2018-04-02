#include "./UnknownState.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace States {
				namespace Ryunosuke {

					UnknownState::UnknownState(Characters::Ryunosuke &ryunosuke) : State(), ryunosuke(ryunosuke) {
					}

					UnknownState::~UnknownState() {
					}

					void UnknownState::move(Sense sense) {
					}

					cocos2d::Action* UnknownState::moveAnimation(Sense sense) {
						return nullptr;
					}

					void UnknownState::stop(Sense sense) {
					}

					cocos2d::Action* UnknownState::stopAnimation(Sense sense) {
						return nullptr;
					}

					void UnknownState::jump(Sense sense) {
					}

					cocos2d::Action* UnknownState::jumpAnimation(Sense sense) {
						return nullptr;
					}

					void UnknownState::attack(Sense sense) {

					}

					cocos2d::Action* UnknownState::attackAnimation(Sense sense) {
						return nullptr;
					}
				}
			}
		}
	}
}