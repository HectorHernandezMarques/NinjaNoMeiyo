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
							auto itEdgeLeftObstacleNodes = nodesInContact.equal_range(static_cast<int>(CollisionHandlers::Bitmasks::EDGE_LEFT_OBSTACLE));

							if (itEdgeLeftObstacleNodes.first != itEdgeLeftObstacleNodes.second) {
								if ((std::next(itEdgeLeftObstacleNodes.first)) == itEdgeLeftObstacleNodes.second) {
									if (!this->isOverEdgeLeftWall(itEdgeLeftObstacleNodes.first->second)) {
										result = true;
									}
								}
							}
							return result;
						}

						StateResult* InEdgeLeftObstacleStateHandler::handle(std::unordered_multimap<int, cocos2d::Node*> &nodesInContact) {
							if (this->canHandle(nodesInContact)) {
								return new StateResult(*new States::Ryunosuke::InEdgeLeftObstacle(static_cast<Characters::Ryunosuke&>(this->character)), StateIndex::IN_EDGE_LEFT_OBSTACLE);
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