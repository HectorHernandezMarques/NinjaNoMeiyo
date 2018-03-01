#include "./InFloorAndRightObstacleStateHandler.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace States {
				namespace StateHandlers {
					namespace Ryunosuke {

						InFloorAndRightObstacleStateHandler::InFloorAndRightObstacleStateHandler(Characters::Ryunosuke &ryunosuke) : CharacterStateHandler(ryunosuke){

						}

						InFloorAndRightObstacleStateHandler::InFloorAndRightObstacleStateHandler(Characters::Ryunosuke &ryunosuke, StateHandler &next) : CharacterStateHandler(ryunosuke, next) {

						}

						InFloorAndRightObstacleStateHandler::~InFloorAndRightObstacleStateHandler() {

						}

						bool InFloorAndRightObstacleStateHandler::canHandle(std::unordered_multimap<int, cocos2d::Node*> &nodesInContact) {
							bool result = false;
							auto itRightObstacleNodes = nodesInContact.equal_range(static_cast<int>(CollisionHandlers::Bitmasks::RIGHT_OBSTACLE));
							auto itFloorNodes = nodesInContact.equal_range(static_cast<int>(CollisionHandlers::Bitmasks::FLOOR));
							if (itRightObstacleNodes.first != itRightObstacleNodes.second && itFloorNodes.first != itFloorNodes.second) {
								result = true;
							}

							return result;
						}

						StateResult* InFloorAndRightObstacleStateHandler::handle(std::unordered_multimap<int, cocos2d::Node*> &nodesInContact) {
							if (this->canHandle(nodesInContact)) {
								return new StateResult(*new States::Ryunosuke::InFloorAndRightObstacle(static_cast<Characters::Ryunosuke&>(this->character)), StateIndex::IN_FLOOR_AND_RIGHT_OBSTACLE);
							}
							else {
								return StateHandler::handle(nodesInContact);
							}
						}
					}
				}
			}
		}
	}
}