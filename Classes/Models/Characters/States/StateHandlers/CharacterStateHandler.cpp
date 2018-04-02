#include "./CharacterStateHandler.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace States {
				namespace StateHandlers {

                    CharacterStateHandler::CharacterStateHandler(Character &character) : StateHandler(), character(character), boxSize(Maps::MapBuilder::getInstance().getBoxSize()) {
					}

                    CharacterStateHandler::CharacterStateHandler(Character &character, StateHandler &next) : StateHandler(next), character(character), boxSize(Maps::MapBuilder::getInstance().getBoxSize()) {
					}

                    CharacterStateHandler::~CharacterStateHandler() {
					}

					StateResult* CharacterStateHandler::handle(std::unordered_multimap<int, cocos2d::Node*> &nodesInContact) {
						if (this->hasNext()) {
							return StateHandler::handle(nodesInContact);
						}
						else {
							return new StateResult(*new States::Ryunosuke::UnknownState(static_cast<Characters::Ryunosuke&>(this->character)), StateIndex::UNKNOWN_STATE);
						}
					}

					bool CharacterStateHandler::isOverEdgeRightFloor(cocos2d::Node *node) {
						return fabs(this->getXRightCorner() - (node->getPosition().x + this->boxSize.width / 2)) < fabs(this->getYRightCorner() - (node->getPosition().y - this->boxSize.height));
					}

					bool CharacterStateHandler::isOverEdgeLeftFloor(cocos2d::Node *node) {
						return fabs(this->getXLeftCorner() - (node->getPosition().x - this->boxSize.width / 2)) < fabs(this->getYLeftCorner() - (node->getPosition().y - this->boxSize.height));
					}

					bool CharacterStateHandler::isOverEdgeRightWall(cocos2d::Node *node) {
						return fabs(this->getXRightCorner() - (node->getPosition().x + this->boxSize.width)) < fabs(this->getYRightCorner() - (node->getPosition().y - this->boxSize.height / 2));
					}

					bool CharacterStateHandler::isOverEdgeLeftWall(cocos2d::Node *node) {
						return fabs(this->getXLeftCorner() - (node->getPosition().x - this->boxSize.width)) < fabs(this->getYLeftCorner() - (node->getPosition().y - this->boxSize.height / 2));
					}

					float CharacterStateHandler::getXRightCorner() {
						return this->character.getPosition().x + (this->character.getInitialPhysicSize().width / 2.0);
					}

					float CharacterStateHandler::getYRightCorner() {
						return this->character.getPosition().y - (this->character.getInitialPhysicSize().height / 2.0);
					}

					float CharacterStateHandler::getXLeftCorner() {
						return this->character.getPosition().x - (this->character.getInitialPhysicSize().width / 2.0);
					}

					float CharacterStateHandler::getYLeftCorner() {
						return this->character.getPosition().y - (this->character.getInitialPhysicSize().height / 2.0);
					}

				}
			}
		}
	}
}