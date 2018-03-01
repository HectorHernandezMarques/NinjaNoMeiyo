#include "./InOilLeftObstacleStateHandler.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace States {
				namespace StateHandlers {
					namespace Ryunosuke {

						InOilLeftObstacleStateHandler::InOilLeftObstacleStateHandler(Characters::Ryunosuke &ryunosuke) : CharacterStateHandler(ryunosuke){

						}

						InOilLeftObstacleStateHandler::InOilLeftObstacleStateHandler(Characters::Ryunosuke &ryunosuke, StateHandler &next) : CharacterStateHandler(ryunosuke, next) {

						}

						InOilLeftObstacleStateHandler::~InOilLeftObstacleStateHandler() {

						}

						bool InOilLeftObstacleStateHandler::canHandle(std::unordered_multimap<int, cocos2d::Node*> &nodesInContact) {
							bool result = false;
							auto itLeftObstacleNodes = nodesInContact.equal_range(static_cast<int>(CollisionHandlers::Bitmasks::LEFT_OBSTACLE));
							auto itOilLeftObstacleNodes = nodesInContact.equal_range(static_cast<int>(CollisionHandlers::Bitmasks::OIL_LEFT_OBSTACLE));
							auto itEdgeLeftObstacleNodes = nodesInContact.equal_range(static_cast<int>(CollisionHandlers::Bitmasks::EDGE_LEFT_OBSTACLE));
							if (itLeftObstacleNodes.first == itLeftObstacleNodes.second) {
								if (itOilLeftObstacleNodes.first != itOilLeftObstacleNodes.second || itEdgeLeftObstacleNodes.first != itEdgeLeftObstacleNodes.second) {
									result = true;
								}
							}

							return result;
						}

						StateResult* InOilLeftObstacleStateHandler::handle(std::unordered_multimap<int, cocos2d::Node*> &nodesInContact) {
							if (this->canHandle(nodesInContact)) {
								return new StateResult(*new States::Ryunosuke::InOilLeftObstacle(static_cast<Characters::Ryunosuke&>(this->character)), StateIndex::IN_OIL_LEFT_OBSTACLE);
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