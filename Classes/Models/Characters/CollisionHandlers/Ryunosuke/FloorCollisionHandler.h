#ifndef NINJANOMEIYO_MODELS_CHARACTERS_COLLISIONHANDLERS_RYUNOSUKE_FLOORCOLLISIONHANDLERS_H
#define NINJANOMEIYO_MODELS_CHARACTERS_COLLISIONHANDLERS_RYUNOSUKE_FLOORCOLLISIONHANDLERS_H

#include "../CollisionHandler.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace CollisionHandlers {
				namespace Ryunosuke {

					class FloorCollisionHandler : public CollisionHandler {
					public:
						FloorCollisionHandler();
						virtual ~FloorCollisionHandler();

						bool canHandle(cocos2d::Node &node);
						CollisionResult* handle(cocos2d::Node &node);

					};
				}
			}
		}
	}
}

#endif