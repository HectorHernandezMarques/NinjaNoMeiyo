#ifndef NINJANOMEIYO_MODELS_CHARACTERS_STATES_STATEHANDLERS_RYUNOSUKE_INEDGELEFTOBSTACLESTATEHANDLER_H
#define NINJANOMEIYO_MODELS_CHARACTERS_STATES_STATEHANDLERS_RYUNOSUKE_INEDGELEFTOBSTACLESTATEHANDLER_H

#include "./InEdgeObstacleStateHandler.h"
#include "../../Ryunosuke/InOilLeftObstacle.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace States {
				namespace StateHandlers {
					namespace Ryunosuke {

						class InEdgeLeftObstacleStateHandler : public InEdgeObstacleStateHandler {
						public:
							InEdgeLeftObstacleStateHandler(Characters::Ryunosuke &ryunosuke);
							InEdgeLeftObstacleStateHandler(Characters::Ryunosuke &ryunosuke, StateHandler &next);
							virtual ~InEdgeLeftObstacleStateHandler();

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