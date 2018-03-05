#include "./InFloorAndRightObstacleStateHandler.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace States {
				namespace StateHandlers {
					namespace Ryunosuke {

						InFloorAndRightObstacleStateHandler::InFloorAndRightObstacleStateHandler(Characters::Ryunosuke &ryunosuke) : CharacterStateHandler(ryunosuke) {

						}

						InFloorAndRightObstacleStateHandler::InFloorAndRightObstacleStateHandler(Characters::Ryunosuke &ryunosuke, StateHandler &next) : CharacterStateHandler(ryunosuke, next) {

						}

						InFloorAndRightObstacleStateHandler::~InFloorAndRightObstacleStateHandler() {

						}

						bool InFloorAndRightObstacleStateHandler::canHandle(std::unordered_multimap<int, cocos2d::Node*> &nodesInContact) {
							bool result = false;
							auto itRightObstacleNodes = nodesInContact.equal_range(static_cast<int>(CollisionHandlers::Bitmasks::RIGHT_OBSTACLE));
							auto itFloorNodes = nodesInContact.equal_range(static_cast<int>(CollisionHandlers::Bitmasks::FLOOR));
							auto itEdgeFloorRightNodes = nodesInContact.equal_range(static_cast<int>(CollisionHandlers::Bitmasks::EDGE_FLOOR_RIGHT));
							auto itEdgeRightObstacleNodes = nodesInContact.equal_range(static_cast<int>(CollisionHandlers::Bitmasks::EDGE_RIGHT_OBSTACLE));

							if (itFloorNodes.first != itFloorNodes.second) {
								if (itRightObstacleNodes.first != itRightObstacleNodes.second) {
									result = true;
								}
								else if (itEdgeRightObstacleNodes.first != itEdgeRightObstacleNodes.second) {
									if ((std::next(itEdgeRightObstacleNodes.first)) == itEdgeRightObstacleNodes.second) {
										if (!this->isOverEdgeLeftWall(itEdgeRightObstacleNodes.first->second)) {
											result = true;
										}
									}
									else {
										result = true;
									}
								}
							}
							else if (itEdgeFloorRightNodes.first != itEdgeFloorRightNodes.second) {
								if ((std::next(itEdgeFloorRightNodes.first)) == itEdgeFloorRightNodes.second) {
									if (this->isOverEdgeRightFloor(itEdgeFloorRightNodes.first->second)) {
										if (itRightObstacleNodes.first != itRightObstacleNodes.second) {
											result = true;
										}
										else if (itEdgeRightObstacleNodes.first != itEdgeRightObstacleNodes.second) {
											if ((std::next(itEdgeRightObstacleNodes.first)) == itEdgeRightObstacleNodes.second) {
												if (!this->isOverEdgeLeftWall(itEdgeRightObstacleNodes.first->second)) {
													result = true;
												}
											}
											else {
												result = true;
											}
										}
									}
								}
								else if (itRightObstacleNodes.first != itRightObstacleNodes.second || itEdgeRightObstacleNodes.first != itEdgeRightObstacleNodes.second) {
									result = true;
								}
							}

							return result;
						}

						StateResult* InFloorAndRightObstacleStateHandler::handle(std::unordered_multimap<int, cocos2d::Node*> &nodesInContact) {
							if (this->canHandle(nodesInContact)) {
								return new StateResult(*new States::Ryunosuke::InFloorAndRightObstacle(static_cast<Characters::Ryunosuke&>(this->character)), StateIndex::IN_FLOOR_AND_RIGHT_OBSTACLE);
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