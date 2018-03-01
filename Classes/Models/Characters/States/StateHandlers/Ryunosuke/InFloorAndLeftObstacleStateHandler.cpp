#include "./InFloorAndLeftObstacleStateHandler.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace States {
				namespace StateHandlers {
					namespace Ryunosuke {

						InFloorAndLeftObstacleStateHandler::InFloorAndLeftObstacleStateHandler(Characters::Ryunosuke &ryunosuke) : CharacterStateHandler(ryunosuke){

						}

						InFloorAndLeftObstacleStateHandler::InFloorAndLeftObstacleStateHandler(Characters::Ryunosuke &ryunosuke, StateHandler &next) : CharacterStateHandler(ryunosuke, next) {

						}

						InFloorAndLeftObstacleStateHandler::~InFloorAndLeftObstacleStateHandler() {

						}

						bool InFloorAndLeftObstacleStateHandler::canHandle(std::unordered_multimap<int, cocos2d::Node*> &nodesInContact) {
							bool result = false;
							auto itLeftObstacleNodes = nodesInContact.equal_range(static_cast<int>(CollisionHandlers::Bitmasks::LEFT_OBSTACLE));
							auto itFloorNodes = nodesInContact.equal_range(static_cast<int>(CollisionHandlers::Bitmasks::FLOOR));
							if (itLeftObstacleNodes.first != itLeftObstacleNodes.second && itFloorNodes.first != itFloorNodes.second) {
								result = true;
							}

							return result;
						}

						StateResult* InFloorAndLeftObstacleStateHandler::handle(std::unordered_multimap<int, cocos2d::Node*> &nodesInContact) {
							if (this->canHandle(nodesInContact)) {
								return new StateResult(*new States::Ryunosuke::InFloorAndLeftObstacle(static_cast<Characters::Ryunosuke&>(this->character)), StateIndex::IN_FLOOR_AND_LEFT_OBSTACLE);
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