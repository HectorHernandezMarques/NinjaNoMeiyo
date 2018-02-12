#include "./InRightObstacleStateHandler.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace States {
				namespace StateHandlers {
					namespace Ryunosuke {

						InRightObstacleStateHandler::InRightObstacleStateHandler(Characters::Ryunosuke &ryunosuke) : StateHandler(ryunosuke){

						}

						InRightObstacleStateHandler::InRightObstacleStateHandler(Characters::Ryunosuke &ryunosuke, StateHandler &next) : StateHandler(ryunosuke, next) {

						}

						InRightObstacleStateHandler::~InRightObstacleStateHandler() {

						}

						bool InRightObstacleStateHandler::canHandle(std::unordered_multimap<int, cocos2d::Node*> &nodesInContact) {
							auto it = nodesInContact.equal_range(static_cast<int>(CollisionHandlers::Bitmasks::RIGHT_OBSTACLE));
							if (it.first != it.second) {
								return true;
							}
							return false;
						}

						StateResult* InRightObstacleStateHandler::handle(std::unordered_multimap<int, cocos2d::Node*> &nodesInContact) {
							if (this->canHandle(nodesInContact)) {
								return new StateResult(*new States::Ryunosuke::InRightObstacle(static_cast<Characters::Ryunosuke&>(this->character)), StateIndex::IN_RIGHT_OBSTACLE);
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