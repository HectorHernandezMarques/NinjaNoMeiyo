#ifndef NINJANOMEIYO_MODELS_CHARACTERS_STATES_STATEHANDLERS_ENEMIES_ENEMY_STATEHANDLERBUILDER_H
#define NINJANOMEIYO_MODELS_CHARACTERS_STATES_STATEHANDLERS_ENEMIES_ENEMY_STATEHANDLERBUILDER_H

#include "../../../../Enemies/Enemy.h"
#include "./EnemyStateHandler.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace States {
				namespace StateHandlers {
					namespace Enemies {
						namespace Enemy {

							class StateHandlerBuilder {
							public:
								StateHandlerBuilder(Characters::Enemies::Enemy &enemy);
								virtual ~StateHandlerBuilder();

								StateHandler& getStateHandler();

							private:
								StateHandler *stateHandler;

							};
						}
					}
				}
			}
		}
	}
}

#endif