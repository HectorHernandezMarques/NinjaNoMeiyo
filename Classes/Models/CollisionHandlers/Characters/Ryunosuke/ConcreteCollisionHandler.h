#ifndef NINJANOMEIYO_MODELS_COLLISIONHANDLERS_CHARACTERS_RYUNOSUKE_CONCRETECOLLISIONHANDLER_H
#define NINJANOMEIYO_MODELS_COLLISIONHANDLERS_CHARACTERS_RYUNOSUKE_CONCRETECOLLISIONHANDLER_H

#include "../../CollisionHandler.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace CollisionHandlers {
			namespace Characters {
				namespace Ryunosuke {

					class ConcreteCollisionHandler : public CollisionHandler {
					public:
						ConcreteCollisionHandler(Bitmasks bitmaskToHandle);
						ConcreteCollisionHandler(Bitmasks bitmaskToHandle, CollisionHandler &next);
						virtual ~ConcreteCollisionHandler();

						bool canHandle(cocos2d::Node &node);
						CollisionResult* handle(cocos2d::Node &node);

					private:
						Bitmasks bitmaskToHandle;

					};
				}
			}
		}
	}
}

#endif