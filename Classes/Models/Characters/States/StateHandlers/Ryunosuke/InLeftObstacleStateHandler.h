#ifndef NINJANOMEIYO_MODELS_CHARACTERS_STATES_STATEHANDLERS_RYUNOSUKE_INLEFTOBSTACLESTATEHANDLER_H
#define NINJANOMEIYO_MODELS_CHARACTERS_STATES_STATEHANDLERS_RYUNOSUKE_INLEFTOBSTACLESTATEHANDLER_H

#include "../StateHandler.h"
#include "../../Ryunosuke/InLeftObstacle.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace States {
				namespace StateHandlers {
					namespace Ryunosuke {

						class InLeftObstacleStateHandler : public StateHandler {
						public:
							InLeftObstacleStateHandler(Characters::Ryunosuke &ryunosuke);
							InLeftObstacleStateHandler(Characters::Ryunosuke &ryunosuke, StateHandler &next);
							virtual ~InLeftObstacleStateHandler();

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