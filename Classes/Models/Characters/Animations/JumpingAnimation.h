#ifndef NINJANOMEIYO_MODELS_CHARACTERS_ANIMATIONS_JUMPINGANIMATION_H
#define NINJANOMEIYO_MODELS_CHARACTERS_ANIMATIONS_JUMPINGANIMATION_H

#include "./Animation.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace Animations {

				class JumpingAnimation : public Animation {
				public:
					JumpingAnimation(Character &character, Sense sense);
					virtual ~JumpingAnimation();

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