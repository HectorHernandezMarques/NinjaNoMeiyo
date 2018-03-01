#include "./InLeftObstacleStateHandler.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace States {
				namespace StateHandlers {
					namespace Ryunosuke {

						InLeftObstacleStateHandler::InLeftObstacleStateHandler(Characters::Ryunosuke &ryunosuke) : CharacterStateHandler(ryunosuke){

						}

						InLeftObstacleStateHandler::InLeftObstacleStateHandler(Characters::Ryunosuke &ryunosuke, StateHandler &next) : CharacterStateHandler(ryunosuke, next) {

						}

						InLeftObstacleStateHandler::~InLeftObstacleStateHandler() {

						}

						bool InLeftObstacleStateHandler::canHandle(std::unordered_multimap<int, cocos2d::Node*> &nodesInContact) {
							bool result = false;
							auto itLeftObstacleNodes = nodesInContact.equal_range(static_cast<int>(CollisionHandlers::Bitmasks::LEFT_OBSTACLE));
							if (itLeftObstacleNodes.first != itLeftObstacleNodes.second) {
								result = true;
							}

							return result;
						}

						StateResult* InLeftObstacleStateHandler::handle(std::unordered_multimap<int, cocos2d::Node*> &nodesInContact) {
							if (this->canHandle(nodesInContact)) {
								return new StateResult(*new States::Ryunosuke::InLeftObstacle(static_cast<Characters::Ryunosuke&>(this->character)), StateIndex::IN_LEFT_OBSTACLE);
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