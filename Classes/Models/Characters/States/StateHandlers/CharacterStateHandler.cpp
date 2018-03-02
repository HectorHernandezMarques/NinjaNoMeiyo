#include "./CharacterStateHandler.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace States {
				namespace StateHandlers {

                    CharacterStateHandler::CharacterStateHandler(Character &character) : StateHandler(), character(character) {
					}

                    CharacterStateHandler::CharacterStateHandler(Character &character, StateHandler &next) : StateHandler(next), character(character) {
					}

                    CharacterStateHandler::~CharacterStateHandler() {
					}

					StateResult* CharacterStateHandler::handle(std::unordered_multimap<int, cocos2d::Node*> &nodesInContact) {
						if (this->hasNext()) {
							return StateHandler::handle(nodesInContact);
						}
						else {
							return new StateResult(*new States::Ryunosuke::UnknownState(static_cast<Characters::Ryunosuke&>(this->character)), StateIndex::UNKNOWN_STATE);
						}
					}
				}
			}
		}
	}
}