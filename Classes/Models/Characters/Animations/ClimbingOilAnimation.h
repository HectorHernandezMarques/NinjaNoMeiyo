#ifndef NINJANOMEIYO_MODELS_CHARACTERS_ANIMATIONS_CLIMBINGOILANIMATION_H
#define NINJANOMEIYO_MODELS_CHARACTERS_ANIMATIONS_CLIMBINGOILANIMATION_H

#include "./Animation.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace Animations {

				class ClimbingOilAnimation : public Animation {
				public:
					ClimbingOilAnimation(Character &character, Sense sense);
					virtual ~ClimbingOilAnimation();

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