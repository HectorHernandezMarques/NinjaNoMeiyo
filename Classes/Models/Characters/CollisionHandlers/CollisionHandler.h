#ifndef NINJANOMEIYO_MODELS_CHARACTERS_COLLISIONHANDLERS_COLLISIONHANDLERS_H
#define NINJANOMEIYO_MODELS_CHARACTERS_COLLISIONHANDLERS_COLLISIONHANDLERS_H

#include "cocos2d.h"
#include "./Bitmasks.h"
#include "./CollisionResult.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace CollisionHandlers {

					class CollisionHandler {
					public:
						CollisionHandler();
						virtual ~CollisionHandler();

						virtual bool canHandle(cocos2d::Node &node) = 0;
						virtual CollisionResult* handle(cocos2d::Node &node);
						bool hasNext();

						void setNext(CollisionHandler &collisionHandler);

					private:
						CollisionHandler *next;

					};
				}
			}
		}
	}
}

#endif