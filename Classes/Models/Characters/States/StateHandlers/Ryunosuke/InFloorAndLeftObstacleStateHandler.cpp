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
							auto itEdgeFloorLeftNodes = nodesInContact.equal_range(static_cast<int>(CollisionHandlers::Bitmasks::EDGE_FLOOR_LEFT));
							auto itEdgeLeftObstacleNodes = nodesInContact.equal_range(static_cast<int>(CollisionHandlers::Bitmasks::EDGE_LEFT_OBSTACLE));
							if (itFloorNodes.first != itFloorNodes.second) {
								if (itLeftObstacleNodes.first != itLeftObstacleNodes.second) {
									result = true;
								}
								else if (itEdgeLeftObstacleNodes.first != itEdgeLeftObstacleNodes.second) {
									if ((std::next(itEdgeLeftObstacleNodes.first)) == itEdgeLeftObstacleNodes.second) {
										if (!this->isOverEdgeLeftWall(itEdgeLeftObstacleNodes.first->second)) {
											result = true;
										}
									}
									else {
										result = true;
									}
								}
							}
							else if (itEdgeFloorLeftNodes.first != itEdgeFloorLeftNodes.second) {
								if ((std::next(itEdgeFloorLeftNodes.first)) == itEdgeFloorLeftNodes.second) {
									if (this->isOverEdgeRightFloor(itEdgeFloorLeftNodes.first->second)) {
										if (itLeftObstacleNodes.first != itLeftObstacleNodes.second) {
											result = true;
										}
										else if (itEdgeLeftObstacleNodes.first != itEdgeLeftObstacleNodes.second) {
											if ((std::next(itEdgeLeftObstacleNodes.first)) == itEdgeLeftObstacleNodes.second) {
												if (!this->isOverEdgeLeftWall(itEdgeLeftObstacleNodes.first->second)) {
													result = true;
												}
											}
											else {
												result = true;
											}
										}
									}
								}
								else if (itLeftObstacleNodes.first != itLeftObstacleNodes.second || itEdgeLeftObstacleNodes.first != itEdgeLeftObstacleNodes.second) {
									result = true;
								}
							}

							return result;
						}

						StateResult* InFloorAndLeftObstacleStateHandler::handle(std::unordered_multimap<int, cocos2d::Node*> &nodesInContact) {
							if (this->canHandle(nodesInContact)) {
								return new StateResult(*new States::Ryunosuke::InFloorAndLeftObstacle(static_cast<Characters::Ryunosuke&>(this->character)), StateIndex::IN_FLOOR_AND_LEFT_OBSTACLE);
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