#ifndef NINJANOMEIYO_MODELS_CHARACTERS_COLLISIONHANDLERS_COLLISIONHANDLERS_H
#define NINJANOMEIYO_MODELS_CHARACTERS_COLLISIONHANDLERS_COLLISIONHANDLERS_H

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace CollisionHandlers {

					class CollisionHandler {
					protected:
						int animationIndex;

					public:
						State();
						virtual ~State();
					};
				}
			}
		}
	}
}

#endif