#ifndef NINJANOMEIYO_MODELS_CHARACTERS_STATES_STATEHANDLERS_RYUNOSUKE_INAIRSTATEHANDLER_H
#define NINJANOMEIYO_MODELS_CHARACTERS_STATES_STATEHANDLERS_RYUNOSUKE_INAIRSTATEHANDLER_H

#include "../CharacterStateHandler.h"
#include "../../Ryunosuke/InAir.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace States {
				namespace StateHandlers {
					namespace Ryunosuke {

						class InAirStateHandler : public CharacterStateHandler {
						public:
							InAirStateHandler(Characters::Ryunosuke &ryunosuke);
							InAirStateHandler(Characters::Ryunosuke &ryunosuke, StateHandler &next);
							virtual ~InAirStateHandler();

							bool canHandle(std::unordered_multimap<int, cocos2d::Node*> &nodesInContact);
							StateResult* handle(std::unordered_multimap<int, cocos2d::Node*> &nodesInContact);

						};
					}
				}
			}
		}
	}
}

#endif