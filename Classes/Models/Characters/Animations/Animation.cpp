#include "./Animation.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace Animations {

				Animation::Animation(Character &character, Sense sense, int texturesNumber, float animationDelay, AnimationIndex animationIndex) :
					character(character), sense(sense), texturesIndex(0), texturesNumber(texturesNumber), animationDelay(animationDelay), animationIndex(animationIndex) {
				}

				Animation::~Animation() {
				}

				cocos2d::Action* Animation::animate(Animation &animation) {
					cocos2d::Action* result = nullptr;
					if (this->animationIndex != animation.animationIndex || this->sense != animation.sense) {
						result = this->animate();
					}

					return result;
				}
			}
		}
	}
}