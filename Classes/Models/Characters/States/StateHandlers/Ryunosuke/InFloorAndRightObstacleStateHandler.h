#ifndef NINJANOMEIYO_MODELS_CHARACTERS_STATES_STATEHANDLERS_RYUNOSUKE_INFLOORANDRIGHTOBSTACLESTATEHANDLER_H
#define NINJANOMEIYO_MODELS_CHARACTERS_STATES_STATEHANDLERS_RYUNOSUKE_INFLOORANDRIGHTOBSTACLESTATEHANDLER_H

#include "../CharacterStateHandler.h"
#include "../../Ryunosuke/InFloorAndRightObstacle.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace States {
				namespace StateHandlers {
					namespace Ryunosuke {

						class InFloorAndRightObstacleStateHandler : public CharacterStateHandler {
						public:
							InFloorAndRightObstacleStateHandler(Characters::Ryunosuke &ryunosuke);
							InFloorAndRightObstacleStateHandler(Characters::Ryunosuke &ryunosuke, StateHandler &next);
							virtual ~InFloorAndRightObstacleStateHandler();

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