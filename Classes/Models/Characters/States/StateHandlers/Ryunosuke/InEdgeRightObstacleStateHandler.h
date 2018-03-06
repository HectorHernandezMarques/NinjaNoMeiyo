#ifndef NINJANOMEIYO_MODELS_CHARACTERS_STATES_STATEHANDLERS_RYUNOSUKE_INEDGERIGHTOBSTACLESTATEHANDLER_H
#define NINJANOMEIYO_MODELS_CHARACTERS_STATES_STATEHANDLERS_RYUNOSUKE_INEDGERIGHTOBSTACLESTATEHANDLER_H

#include "./InEdgeObstacleStateHandler.h"
#include "../../Ryunosuke/InEdgeRightObstacle.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace States {
				namespace StateHandlers {
					namespace Ryunosuke {

						class InEdgeRightObstacleStateHandler : public InEdgeObstacleStateHandler {
						public:
							InEdgeRightObstacleStateHandler(Characters::Ryunosuke &ryunosuke);
							InEdgeRightObstacleStateHandler(Characters::Ryunosuke &ryunosuke, StateHandler &next);
							virtual ~InEdgeRightObstacleStateHandler();

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