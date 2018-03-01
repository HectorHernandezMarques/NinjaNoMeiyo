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
				}
			}
		}
	}
}