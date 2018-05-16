#ifndef NINJANOMEIYO_MODELS_CHARACTERS_ANIMATIONS_JUMPINGONWALLANIMATION_H
#define NINJANOMEIYO_MODELS_CHARACTERS_ANIMATIONS_JUMPINGONWALLANIMATION_H

#include "./Animation.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace Animations {

				class JumpingOnWallAnimation : public Animation {
				public:
					JumpingOnWallAnimation(Character &character, Sense sense);
					virtual ~JumpingOnWallAnimation();

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