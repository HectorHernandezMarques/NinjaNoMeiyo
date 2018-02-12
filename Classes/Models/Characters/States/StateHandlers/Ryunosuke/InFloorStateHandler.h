#ifndef NINJANOMEIYO_MODELS_CHARACTERS_STATES_STATEHANDLERS_RYUNOSUKE_INFLOORSTATEHANDLER_H
#define NINJANOMEIYO_MODELS_CHARACTERS_STATES_STATEHANDLERS_RYUNOSUKE_INFLOORSTATEHANDLER_H

#include "../StateHandler.h"
#include "../../Ryunosuke/InFloor.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace States {
				namespace StateHandlers {
					namespace Ryunosuke {

						class InFloorStateHandler : public StateHandler {
						public:
							InFloorStateHandler(Characters::Ryunosuke &ryunosuke);
							InFloorStateHandler(Characters::Ryunosuke &ryunosuke, StateHandler &next);
							virtual ~InFloorStateHandler();

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