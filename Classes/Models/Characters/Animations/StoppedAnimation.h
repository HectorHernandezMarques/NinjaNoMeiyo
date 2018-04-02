#ifndef NINJANOMEIYO_MODELS_CHARACTERS_ANIMATIONS_STOPPEDANIMATION_H
#define NINJANOMEIYO_MODELS_CHARACTERS_ANIMATIONS_STOPPEDANIMATION_H

#include "./Animation.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace Animations {

				class StoppedAnimation : public Animation {
				public:
					StoppedAnimation(Character &character, Sense sense);
					virtual ~StoppedAnimation();

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