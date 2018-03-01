#ifndef NINJANOMEIYO_MODELS_CHARACTERS_STATES_STATEHANDLERS_RYUNOSUKE_INFLOORANDLEFTOBSTACLESTATEHANDLER_H
#define NINJANOMEIYO_MODELS_CHARACTERS_STATES_STATEHANDLERS_RYUNOSUKE_INFLOORANDLEFTOBSTACLESTATEHANDLER_H

#include "../CharacterStateHandler.h"
#include "../../Ryunosuke/InFloorAndLeftObstacle.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace States {
				namespace StateHandlers {
					namespace Ryunosuke {

						class InFloorAndLeftObstacleStateHandler : public CharacterStateHandler {
						public:
							InFloorAndLeftObstacleStateHandler(Characters::Ryunosuke &ryunosuke);
							InFloorAndLeftObstacleStateHandler(Characters::Ryunosuke &ryunosuke, StateHandler &next);
							virtual ~InFloorAndLeftObstacleStateHandler();

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