#include "./InOilRightObstacleStateHandler.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace States {
				namespace StateHandlers {
					namespace Ryunosuke {

						InOilRightObstacleStateHandler::InOilRightObstacleStateHandler(Characters::Ryunosuke &ryunosuke) : CharacterStateHandler(ryunosuke){

						}

						InOilRightObstacleStateHandler::InOilRightObstacleStateHandler(Characters::Ryunosuke &ryunosuke, StateHandler &next) : CharacterStateHandler(ryunosuke, next) {

						}

						InOilRightObstacleStateHandler::~InOilRightObstacleStateHandler() {

						}

						bool InOilRightObstacleStateHandler::canHandle(std::unordered_multimap<int, cocos2d::Node*> &nodesInContact) {
							bool result = false;
							auto itRightObstacleNodes = nodesInContact.equal_range(static_cast<int>(CollisionHandlers::Bitmasks::RIGHT_OBSTACLE));
							auto itOilRightObstacleNodes = nodesInContact.equal_range(static_cast<int>(CollisionHandlers::Bitmasks::OIL_RIGHT_OBSTACLE));
							auto itEdgeRightObstacleNodes = nodesInContact.equal_range(static_cast<int>(CollisionHandlers::Bitmasks::EDGE_RIGHT_OBSTACLE));
							if (itRightObstacleNodes.first == itRightObstacleNodes.second) {
								if (itOilRightObstacleNodes.first != itOilRightObstacleNodes.second ||
                                        itEdgeRightObstacleNodes.first != itEdgeRightObstacleNodes.second) {
									result = true;
								}
							}

							return result;
						}

						StateResult* InOilRightObstacleStateHandler::handle(std::unordered_multimap<int, cocos2d::Node*> &nodesInContact) {
							if (this->canHandle(nodesInContact)) {
								return new StateResult(*new States::Ryunosuke::InOilRightObstacle(static_cast<Characters::Ryunosuke&>(this->character)), StateIndex::IN_OIL_RIGHT_OBSTACLE);
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