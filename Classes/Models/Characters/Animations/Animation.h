#ifndef NINJANOMEIYO_MODELS_CHARACTERS_ANIMATIONS_ANIMATION_H
#define NINJANOMEIYO_MODELS_CHARACTERS_ANIMATIONS_ANIMATION_H

#include "./AnimationIndex.h"
#include "../Character.h"
#include "../Sense.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace Animations {

				class Animation {
				public:
					Animation(Character &ryunosuke, Sense sense, int texturesNumber, float animationDelay, AnimationIndex animationIndex);
					virtual ~Animation();

					cocos2d::Action* animate(Animation &animation);
					virtual cocos2d::Action* animate() = 0;
					virtual void animationFunction() = 0;

					std::string to_string(int num) {
						std::ostringstream ss;
						ss << num;
						return ss.str();
					}

				protected:
					Character &character;
					Sense sense;
					int texturesIndex;
					int texturesNumber;
					float animationDelay;
					AnimationIndex animationIndex;

				private:

				};
			}
		}
	}
}

#endif