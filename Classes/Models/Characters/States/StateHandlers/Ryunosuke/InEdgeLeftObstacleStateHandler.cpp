#include "./InEdgeLeftObstacleStateHandler.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace States {
				namespace StateHandlers {
					namespace Ryunosuke {

						InEdgeLeftObstacleStateHandler::InEdgeLeftObstacleStateHandler(Characters::Ryunosuke &ryunosuke) : InEdgeObstacleStateHandler(ryunosuke){

						}

						InEdgeLeftObstacleStateHandler::InEdgeLeftObstacleStateHandler(Characters::Ryunosuke &ryunosuke, StateHandler &next) : InEdgeObstacleStateHandler(ryunosuke, next) {

						}

						InEdgeLeftObstacleStateHandler::~InEdgeLeftObstacleStateHandler() {

						}

						bool InEdgeLeftObstacleStateHandler::canHandle(std::unordered_multimap<int, cocos2d::Node*> &nodesInContact) {
							bool result = false;
							if (this->searchEdgeWall(nodesInContact.equal_range(static_cast<int>(CollisionHandlers::Bitmasks::EDGE_RIGHT_OBSTACLE)),
														nodesInContact.equal_range(static_cast<int>(CollisionHandlers::Bitmasks::EDGE_FLOOR_RIGHT)))) {
								result = true;
							}

							return result;
						}

						StateResult* InEdgeLeftObstacleStateHandler::handle(std::unordered_multimap<int, cocos2d::Node*> &nodesInContact) {
							if (this->canHandle(nodesInContact)) {
								cocos2d::Node *edgeWall = this->searchEdgeWall(nodesInContact.equal_range(static_cast<int>(CollisionHandlers::Bitmasks::EDGE_RIGHT_OBSTACLE)),
									nodesInContact.equal_range(static_cast<int>(CollisionHandlers::Bitmasks::EDGE_FLOOR_RIGHT)));

								return new StateResult(*new States::Ryunosuke::InOilLeftObstacle(static_cast<Characters::Ryunosuke&>(this->character)), StateIndex::IN_OIL_LEFT_OBSTACLE);
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