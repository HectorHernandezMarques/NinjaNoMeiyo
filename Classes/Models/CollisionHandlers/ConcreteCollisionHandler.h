#ifndef NINJANOMEIYO_MODELS_COLLISIONHANDLERS_CONCRETECOLLISIONHANDLER_H
#define NINJANOMEIYO_MODELS_COLLISIONHANDLERS_CONCRETECOLLISIONHANDLER_H

#include "./CollisionHandler.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace CollisionHandlers {

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

#endif