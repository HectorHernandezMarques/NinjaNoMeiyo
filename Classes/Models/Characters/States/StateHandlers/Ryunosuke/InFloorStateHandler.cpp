#include "./InFloorStateHandler.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace States {
				namespace StateHandlers {
					namespace Ryunosuke {

						InFloorStateHandler::InFloorStateHandler(Characters::Ryunosuke &ryunosuke) : CharacterStateHandler(ryunosuke) {

						}

						InFloorStateHandler::InFloorStateHandler(Characters::Ryunosuke &ryunosuke, StateHandler &next) : CharacterStateHandler(ryunosuke, next) {

						}

						InFloorStateHandler::~InFloorStateHandler() {

						}

						bool InFloorStateHandler::canHandle(std::unordered_multimap<int, cocos2d::Node*> &nodesInContact) {
							bool result = false;
							auto itFloorNodes = nodesInContact.equal_range(static_cast<int>(CollisionHandlers::Bitmasks::FLOOR));
							auto itEdgeFloorLeftNodes = nodesInContact.equal_range(static_cast<int>(CollisionHandlers::Bitmasks::EDGE_FLOOR_LEFT));
							auto itEdgeFloorRightNodes = nodesInContact.equal_range(static_cast<int>(CollisionHandlers::Bitmasks::EDGE_FLOOR_RIGHT));
							if (itFloorNodes.first != itFloorNodes.second) {
								result = true;
							}
							else if (itEdgeFloorRightNodes.first != itEdgeFloorRightNodes.second) {
								if ((std::next(itEdgeFloorRightNodes.first)) == itEdgeFloorRightNodes.second) {
									if (this->isOverEdgeRightFloor(itEdgeFloorRightNodes.first->second)) {
										result = true;
									}
								}
								else {
									result = true;
								}
							}
							else if (itEdgeFloorLeftNodes.first != itEdgeFloorLeftNodes.second) {
								if ((std::next(itEdgeFloorLeftNodes.first)) == itEdgeFloorLeftNodes.second) {
									if (this->isOverEdgeLeftFloor(itEdgeFloorLeftNodes.first->second)) {
										result = true;
									}
								}
								else {
									result = true;
								}
							}

							return result;
						}

						StateResult* InFloorStateHandler::handle(std::unordered_multimap<int, cocos2d::Node*> &nodesInContact) {
							if (this->canHandle(nodesInContact)) {
								return new StateResult(*new States::Ryunosuke::InFloor(static_cast<Characters::Ryunosuke&>(this->character)), StateIndex::IN_FLOOR);
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