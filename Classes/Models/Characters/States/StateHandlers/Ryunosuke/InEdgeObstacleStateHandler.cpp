#include "./InEdgeObstacleStateHandler.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace States {
				namespace StateHandlers {
					namespace Ryunosuke {

						InEdgeObstacleStateHandler::InEdgeObstacleStateHandler(Characters::Ryunosuke &ryunosuke) : CharacterStateHandler(ryunosuke){

						}

						InEdgeObstacleStateHandler::InEdgeObstacleStateHandler(Characters::Ryunosuke &ryunosuke, StateHandler &next) : CharacterStateHandler(ryunosuke, next) {

						}

						InEdgeObstacleStateHandler::~InEdgeObstacleStateHandler() {

						}

						cocos2d::Node* InEdgeObstacleStateHandler::searchEdgeWall(std::pair<std::unordered_multimap<int, cocos2d::Node*>::iterator, std::unordered_multimap<int, cocos2d::Node*>::iterator> edgeWallsIterators,
																					std::pair<std::unordered_multimap<int, cocos2d::Node*>::iterator, std::unordered_multimap<int, cocos2d::Node*>::iterator> edgeFloorsIterators) {
							int numCorrespondences = 0;
							cocos2d::Node* result = nullptr;
							for (auto itWalls = edgeWallsIterators.first; itWalls != edgeWallsIterators.second; ++itWalls) {
								for (auto itFloors = edgeFloorsIterators.first; itFloors != edgeFloorsIterators.second; ++itFloors) {
									if (((cocos2d::Sprite*)itWalls->second)->getPhysicsBody()->getOwnerNode() == ((cocos2d::Sprite*)itFloors->second)->getPhysicsBody()->getOwnerNode()) {
										numCorrespondences++;
										result = itWalls->second;
									}
								}
							}
							if (numCorrespondences != 1) {
								return nullptr;
							}

							return result;
						}
					}
				}
			}
		}
	}
}