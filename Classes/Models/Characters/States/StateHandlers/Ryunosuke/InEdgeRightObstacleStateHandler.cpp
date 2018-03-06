#include "./InEdgeRightObstacleStateHandler.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace States {
				namespace StateHandlers {
					namespace Ryunosuke {

						InEdgeRightObstacleStateHandler::InEdgeRightObstacleStateHandler(Characters::Ryunosuke &ryunosuke) : InEdgeObstacleStateHandler(ryunosuke){

						}

						InEdgeRightObstacleStateHandler::InEdgeRightObstacleStateHandler(Characters::Ryunosuke &ryunosuke, StateHandler &next) : InEdgeObstacleStateHandler(ryunosuke, next) {

						}

						InEdgeRightObstacleStateHandler::~InEdgeRightObstacleStateHandler() {

						}

						bool InEdgeRightObstacleStateHandler::canHandle(std::unordered_multimap<int, cocos2d::Node*> &nodesInContact) {
							bool result = false;
							auto itEdgeRightObstacleNodes = nodesInContact.equal_range(static_cast<int>(CollisionHandlers::Bitmasks::EDGE_RIGHT_OBSTACLE));

							if (itEdgeRightObstacleNodes.first != itEdgeRightObstacleNodes.second) {
								if ((std::next(itEdgeRightObstacleNodes.first)) == itEdgeRightObstacleNodes.second) {
									if (!this->isOverEdgeRightWall(itEdgeRightObstacleNodes.first->second)) {
										result = true;
									}
								}
							}
							return result;
						}

						StateResult* InEdgeRightObstacleStateHandler::handle(std::unordered_multimap<int, cocos2d::Node*> &nodesInContact) {
							if (this->canHandle(nodesInContact)) {
								return new StateResult(*new States::Ryunosuke::InEdgeRightObstacle(static_cast<Characters::Ryunosuke&>(this->character)), StateIndex::IN_EDGE_RIGHT_OBSTACLE);
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