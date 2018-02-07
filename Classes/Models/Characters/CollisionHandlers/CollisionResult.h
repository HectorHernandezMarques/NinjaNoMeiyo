#ifndef NINJANOMEIYO_MODELS_CHARACTERS_COLLISIONHANDLERS_COLLISIONRESULT_H
#define NINJANOMEIYO_MODELS_CHARACTERS_COLLISIONHANDLERS_COLLISIONRESULT_H

#include "./Bitmasks.h"
#include "cocos2d.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace CollisionHandlers {

				class CollisionResult {
				protected:
					cocos2d::Node &node;
					Bitmasks bitmask;

				public:
					CollisionResult(cocos2d::Node &node, Bitmasks bitmask);
					virtual ~CollisionResult();

					cocos2d::Node& getNode();
					Bitmasks getBitmask();
				};
			}
		}
	}
}

#endif