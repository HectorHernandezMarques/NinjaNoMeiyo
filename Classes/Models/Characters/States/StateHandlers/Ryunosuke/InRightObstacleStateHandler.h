#ifndef NINJANOMEIYO_MODELS_CHARACTERS_STATES_STATEHANDLERS_RYUNOSUKE_INRIGHTOBSTACLESTATEHANDLER_H
#define NINJANOMEIYO_MODELS_CHARACTERS_STATES_STATEHANDLERS_RYUNOSUKE_INRIGHTOBSTACLESTATEHANDLER_H

#include "../StateHandler.h"
#include "../../Ryunosuke/InRightObstacle.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace States {
				namespace StateHandlers {
					namespace Ryunosuke {

						class InRightObstacleStateHandler : public StateHandler {
						public:
							InRightObstacleStateHandler(Characters::Ryunosuke &ryunosuke);
							InRightObstacleStateHandler(Characters::Ryunosuke &ryunosuke, StateHandler &next);
							virtual ~InRightObstacleStateHandler();

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