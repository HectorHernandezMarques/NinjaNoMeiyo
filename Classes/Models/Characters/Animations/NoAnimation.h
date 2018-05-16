#ifndef NINJANOMEIYO_MODELS_CHARACTERS_ANIMATIONS_NOANIMATION_H
#define NINJANOMEIYO_MODELS_CHARACTERS_ANIMATIONS_NOANIMATION_H

#include "./Animation.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace Animations {

				class NoAnimation : public Animation {
				public:
					NoAnimation(Character &character, Sense sense);
					virtual ~NoAnimation();

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