#include "./NoAnimation.h"
#include "../Character.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace Animations {

				NoAnimation::NoAnimation(Character &character, Sense sense) : Animation(character, sense, 2, 0.35, AnimationIndex::STOPPED) {
					this->animationAction = cocos2d::Sequence::create(cocos2d::CallFunc::create(CC_CALLBACK_0(Animations::NoAnimation::animationFunction, this)),
																										nullptr);
				}

				NoAnimation::~NoAnimation() {

				}

				void NoAnimation::animationFunction() {
				}

			}
		}
	}
}