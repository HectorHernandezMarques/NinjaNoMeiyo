#include "./InFloorStateHandler.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace States {
				namespace StateHandlers {
					namespace Ryunosuke {

						InFloorStateHandler::InFloorStateHandler(Characters::Ryunosuke &ryunosuke) : CharacterStateHandler(ryunosuke){

						}

						InFloorStateHandler::InFloorStateHandler(Characters::Ryunosuke &ryunosuke, StateHandler &next) : CharacterStateHandler(ryunosuke, next) {

						}

						InFloorStateHandler::~InFloorStateHandler() {

						}

						bool InFloorStateHandler::canHandle(std::unordered_multimap<int, cocos2d::Node*> &nodesInContact) {
							return true;
						}

						StateResult* InFloorStateHandler::handle(std::unordered_multimap<int, cocos2d::Node*> &nodesInContact) {
							if (this->canHandle(nodesInContact)) {
								return new StateResult(*new States::Ryunosuke::InFloor(static_cast<Characters::Ryunosuke&>(this->character)), StateIndex::IN_FLOOR);
							}
							else {
								return StateHandler::handle(nodesInContact);
							}
						}
					}
				}
			}
		}
	}
}