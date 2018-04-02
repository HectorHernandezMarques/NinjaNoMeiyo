#ifndef NINJANOMEIYO_MODELS_CHARACTERS_ANIMATIONS_MOVINGANIMATION_H
#define NINJANOMEIYO_MODELS_CHARACTERS_ANIMATIONS_MOVINGANIMATION_H

#include "./Animation.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace Animations {

				class MovingAnimation : public Animation {
				public:
					MovingAnimation(Character &character, Sense sense);
					virtual ~MovingAnimation();

					cocos2d::Action* animate();
					void animationFunction();

				protected:

				private:

				};
			}
		}
	}
}

#endif