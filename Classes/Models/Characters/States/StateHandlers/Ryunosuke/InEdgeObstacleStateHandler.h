#ifndef NINJANOMEIYO_MODELS_CHARACTERS_STATES_STATEHANDLERS_RYUNOSUKE_INEDGEOBSTACLESTATEHANDLER_H
#define NINJANOMEIYO_MODELS_CHARACTERS_STATES_STATEHANDLERS_RYUNOSUKE_INEDGEOBSTACLESTATEHANDLER_H

#include "../CharacterStateHandler.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace States {
				namespace StateHandlers {
					namespace Ryunosuke {

						class InEdgeObstacleStateHandler : public CharacterStateHandler {
						public:
							InEdgeObstacleStateHandler(Characters::Ryunosuke &ryunosuke);
							InEdgeObstacleStateHandler(Characters::Ryunosuke &ryunosuke, StateHandler &next);
							virtual ~InEdgeObstacleStateHandler();

						protected:
							cocos2d::Node* searchEdgeWall(std::pair<std::unordered_multimap<int, cocos2d::Node*>::iterator, std::unordered_multimap<int, cocos2d::Node*>::iterator> edgeWallsIterators,
																						std::pair<std::unordered_multimap<int, cocos2d::Node*>::iterator, std::unordered_multimap<int, cocos2d::Node*>::iterator> edgeFloorsIterators);

						};
					}
				}
			}
		}
	}
}

#endif