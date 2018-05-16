#ifndef NINJANOMEIYO_MODELS_CHARACTERS_ANIMATIONS_ANIMATION_H
#define NINJANOMEIYO_MODELS_CHARACTERS_ANIMATIONS_ANIMATION_H

#include <unordered_set>
#include "./AnimationIndex.h"
#include "../Sense.h"
#include "./Aspects/Animation/Aspect.h"
#include "./Observers/AnimationObserver.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			class Character;
		}
	}
}


namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace Animations {

				class Animation {
				public:
					Animation(Character &character, Sense sense, int texturesNumber, float animationDelay, AnimationIndex animationIndex);
					virtual ~Animation();

					void animate();
					void stopAnimation();
					cocos2d::Action* animate(Animation &animation);
					cocos2d::Action* getAnimationAction();
					virtual void animationFunction() = 0;
					void attach(Observers::AnimationObserver &animationObserver);
					void detach(Observers::AnimationObserver &animationObserver);
					void notify(Aspects::Animation::Aspect &aspect);

					std::string to_string(int num) {
						std::ostringstream ss;
						ss << num;
						return ss.str();
					}

				protected:
					Character &character;
					cocos2d::Action* animationAction;
					Sense sense;
					int texturesIndex;
					int texturesNumber;
					float animationDelay;
					AnimationIndex animationIndex;

				private:
					std::unordered_set<Observers::AnimationObserver*> animationObservers;

				};
			}
		}
	}
}

#endif