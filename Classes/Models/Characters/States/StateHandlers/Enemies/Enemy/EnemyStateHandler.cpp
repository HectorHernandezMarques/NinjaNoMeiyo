#include "./EnemyStateHandler.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace States {
				namespace StateHandlers {
					namespace Enemies {
						namespace Enemy {

							EnemyStateHandler::EnemyStateHandler(Characters::Enemies::Enemy &enemy) : CharacterStateHandler(enemy) {

							}

							EnemyStateHandler::EnemyStateHandler(Characters::Enemies::Enemy &enemy, StateHandler &next) : CharacterStateHandler(enemy, next) {

							}

							EnemyStateHandler::~EnemyStateHandler() {

							}

							bool EnemyStateHandler::canHandle(std::unordered_multimap<int, cocos2d::Node*> &nodesInContact) {
								return true;
							}

							StateResult* EnemyStateHandler::handle(std::unordered_multimap<int, cocos2d::Node*> &nodesInContact) {
								if (this->hasNext()) {
									return StateHandler::handle(nodesInContact);
								}
								else {
									return new StateResult(*new States::Enemies::Enemy::UnknownState(static_cast<Characters::Enemies::Enemy&>(this->character)), StateIndex::UNKNOWN_STATE);
								}
							}
						}
					}
				}
			}
		}
	}
}