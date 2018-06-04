#ifndef NINJANOMEIYO_MODELS_CHARACTERS_STATES_STATEHANDLERS_ENEMIES_ENEMY_INFLOORSTATEHANDLER_H
#define NINJANOMEIYO_MODELS_CHARACTERS_STATES_STATEHANDLERS_ENEMIES_ENEMY_INFLOORSTATEHANDLER_H

#include "../../CharacterStateHandler.h"
#include "../../../Enemies/Enemy/UnknownState.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace States {
				namespace StateHandlers {
					namespace Enemies {
						namespace Enemy {

							class EnemyStateHandler : public CharacterStateHandler {
							public:
								EnemyStateHandler(Characters::Enemies::Enemy &enemy);
								EnemyStateHandler(Characters::Enemies::Enemy &enemy, StateHandler &next);
								virtual ~EnemyStateHandler();

								bool canHandle(std::unordered_multimap<int, cocos2d::Node*> &nodesInContact);
								StateResult* handle(std::unordered_multimap<int, cocos2d::Node*> &nodesInContact);

							};
						}
					}
				}
			}
		}
	}
}

#endif