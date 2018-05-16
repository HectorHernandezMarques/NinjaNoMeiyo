#ifndef NINJANOMEIYO_MODELS_CHARACTERS_ANIMATIONS_ATTACKINGANIMATION_H
#define NINJANOMEIYO_MODELS_CHARACTERS_ANIMATIONS_ATTACKINGANIMATION_H

#include "./Animation.h"
#include "./Aspects/Animation/AnimationFinishedAspect.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace Animations {

				class AttackingAnimation : public Animation {
				public:
					AttackingAnimation(Character &character, Sense sense);
					virtual ~AttackingAnimation();

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