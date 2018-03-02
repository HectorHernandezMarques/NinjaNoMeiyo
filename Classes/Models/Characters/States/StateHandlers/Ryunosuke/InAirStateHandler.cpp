#include "./InAirStateHandler.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace States {
				namespace StateHandlers {
					namespace Ryunosuke {

						InAirStateHandler::InAirStateHandler(Characters::Ryunosuke &ryunosuke) : CharacterStateHandler(ryunosuke){

						}

						InAirStateHandler::InAirStateHandler(Characters::Ryunosuke &ryunosuke, StateHandler &next) : CharacterStateHandler(ryunosuke, next) {

						}

						InAirStateHandler::~InAirStateHandler() {

						}

						bool InAirStateHandler::canHandle(std::unordered_multimap<int, cocos2d::Node*> &nodesInContact) {
							bool result = false;
							if (!nodesInContact.size()) {
								result = true;
							}

							return result;
						}

						StateResult* InAirStateHandler::handle(std::unordered_multimap<int, cocos2d::Node*> &nodesInContact) {
							if (this->canHandle(nodesInContact)) {
								return new StateResult(*new States::Ryunosuke::InAir(static_cast<Characters::Ryunosuke&>(this->character)), StateIndex::IN_AIR);
							}
							else {
								return CharacterStateHandler::handle(nodesInContact);
							}
						}
					}
				}
			}
		}
	}
}