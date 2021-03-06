#include "./InRightObstacleStateHandler.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace States {
				namespace StateHandlers {
					namespace Ryunosuke {

						InRightObstacleStateHandler::InRightObstacleStateHandler(Characters::Ryunosuke &ryunosuke) : CharacterStateHandler(ryunosuke){

						}

						InRightObstacleStateHandler::InRightObstacleStateHandler(Characters::Ryunosuke &ryunosuke, StateHandler &next) : CharacterStateHandler(ryunosuke, next) {

						}

						InRightObstacleStateHandler::~InRightObstacleStateHandler() {

						}

						bool InRightObstacleStateHandler::canHandle(std::unordered_multimap<int, cocos2d::Node*> &nodesInContact) {
							bool result = false;
							auto itRightObstacleNodes = nodesInContact.equal_range(static_cast<int>(CollisionHandlers::Bitmasks::RIGHT_OBSTACLE));
							if (itRightObstacleNodes.first != itRightObstacleNodes.second) {
								result = true;
							}

							return result;
						}

						StateResult* InRightObstacleStateHandler::handle(std::unordered_multimap<int, cocos2d::Node*> &nodesInContact) {
							if (this->canHandle(nodesInContact)) {
								return new StateResult(*new States::Ryunosuke::InRightObstacle(static_cast<Characters::Ryunosuke&>(this->character)), StateIndex::IN_RIGHT_OBSTACLE);
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