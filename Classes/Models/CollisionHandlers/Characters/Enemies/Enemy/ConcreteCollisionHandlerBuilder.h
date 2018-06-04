#ifndef NINJANOMEIYO_MODELS_COLLISIONHANDLERS_CHARACTERS_ENEMIES_ENEMY_CONCRETECOLLISIONHANDLERBUILDER_H
#define NINJANOMEIYO_MODELS_COLLISIONHANDLERS_CHARACTERS_ENEMIES_ENEMY_CONCRETECOLLISIONHANDLERBUILDER_H

#include "../../../ConcreteCollisionHandler.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace CollisionHandlers {
			namespace Characters {
				namespace Enemies {
					namespace Enemy {

						class ConcreteCollisionHandlerBuilder {
						public:
							virtual ~ConcreteCollisionHandlerBuilder();
							static ConcreteCollisionHandlerBuilder& getInstance();

							CollisionHandler& getCollisionHandler();

						private:
							CollisionHandler *collisionHandler;

							ConcreteCollisionHandlerBuilder();
							static ConcreteCollisionHandlerBuilder *instance;

						};
					}
				}
			}
		}
	}
}

#endif