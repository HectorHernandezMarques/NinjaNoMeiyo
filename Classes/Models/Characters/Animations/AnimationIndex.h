#ifndef NINJANOMEIYO_MODELS_CHARACTERS_ANIMATIONS_ANIMATIONINDEX
#define NINJANOMEIYO_MODELS_CHARACTERS_ANIMATIONS_ANIMATIONINDEX


namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace Animations {

				enum class AnimationIndex {
					STOPPED,
					MOVING,
					JUMPING,
					JUMPING_ON_WALL,
					CLIMBING,
					CLIMBING_OIL,
					ATTACKING
				};
			}
		}
	}
}

#endif