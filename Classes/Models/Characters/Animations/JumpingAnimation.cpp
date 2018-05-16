#include "./JumpingAnimation.h"
#include "../Character.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace Animations {

				JumpingAnimation::JumpingAnimation(Character &character, Sense sense) : Animation(character, sense, 1, 0.15, AnimationIndex::JUMPING) {
					this->animationAction = cocos2d::RepeatForever::create(cocos2d::Sequence::create(cocos2d::CallFunc::create(CC_CALLBACK_0(Animations::JumpingAnimation::animationFunction, this)),
																										cocos2d::DelayTime::create(this->animationDelay),
																										nullptr));
				}

				JumpingAnimation::~JumpingAnimation() {

				}

				void JumpingAnimation::animationFunction() {
					std::string textureName;
					if (this->sense == Sense::RIGHT) {
						textureName.append("RyunosukeJump");
						textureName.append(this->to_string(this->texturesIndex++%this->texturesNumber));
						textureName.append("D.png");
					}
					else if (this->sense == Sense::LEFT) {
						textureName.append("RyunosukeJump");
						textureName.append(this->to_string(this->texturesIndex++%this->texturesNumber));
						textureName.append("I.png");
					}
					this->character.setTexture(textureName);
				}
			}
		}
	}
}