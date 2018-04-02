#ifndef NINJANOMEIYO_MODELS_CHARACTERS_ANIMATIONS_CLIMBINGANIMATION_H
#define NINJANOMEIYO_MODELS_CHARACTERS_ANIMATIONS_CLIMBINGANIMATION_H

#include "./Animation.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace Animations {

				class ClimbingAnimation : public Animation {
				public:
					ClimbingAnimation(Character &character, Sense sense);
					virtual ~ClimbingAnimation();

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