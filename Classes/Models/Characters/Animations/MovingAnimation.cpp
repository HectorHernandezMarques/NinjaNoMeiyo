#include "./MovingAnimation.h"
#include "../Character.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace Animations {

				MovingAnimation::MovingAnimation(Character &character, Sense sense) : Animation(character, sense, 3, 0.15, AnimationIndex::MOVING) {
					this->animationAction = cocos2d::RepeatForever::create(cocos2d::Sequence::create(cocos2d::CallFunc::create(CC_CALLBACK_0(Animations::MovingAnimation::animationFunction, this)),
																										cocos2d::DelayTime::create(this->animationDelay),
																										nullptr));
				}

				MovingAnimation::~MovingAnimation() {

				}

				void MovingAnimation::animationFunction() {
					std::string textureName;
					if (this->sense == Sense::RIGHT) {
						textureName.append("RyunosukeMove");
						textureName.append(this->to_string(this->texturesIndex++%this->texturesNumber));
						textureName.append("D.png");
					}
					else if (this->sense == Sense::LEFT) {
						textureName.append("RyunosukeMove");
						textureName.append(this->to_string(this->texturesIndex++%this->texturesNumber));
						textureName.append("I.png");
					}
					this->character.setTexture(textureName);
				}
			}
		}
	}
}