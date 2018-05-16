#ifndef NINJANOMEIYO_MODELS_ENVIRONMENT_DAMAGER_H
#define NINJANOMEIYO_MODELS_ENVIRONMENT_DAMAGER_H

#include "../Node.h"
#include "../Physics/PhysicBox.h"
#include "../CollisionHandlers/Bitmasks.h"
#include <unordered_set>

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Environment {

			class Damager : public Node {
			public:
				Damager(cocos2d::Vec2 position, cocos2d::Size initialPhysicSize = cocos2d::Size::ZERO);
				virtual ~Damager();

				cocos2d::Size getInitialPhysicSize();

			protected:
				cocos2d::Size initialPhysicSize;

			private:
			};
		}
	}
}

#endif