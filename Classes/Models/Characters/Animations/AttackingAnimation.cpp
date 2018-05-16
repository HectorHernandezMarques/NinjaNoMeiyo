#include "./AttackingAnimation.h"
#include "../Character.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace Animations {

				AttackingAnimation::AttackingAnimation(Character &character, Sense sense) : Animation(character, sense, 2, 0.10, AnimationIndex::STOPPED) {
					this->animationAction = cocos2d::Sequence::create(cocos2d::CallFunc::create(CC_CALLBACK_0(Animations::AttackingAnimation::animationFunction, this)),
																		cocos2d::DelayTime::create(this->animationDelay),
																		cocos2d::CallFunc::create(CC_CALLBACK_0(Animations::AttackingAnimation::animationFunction, this)),
																		cocos2d::DelayTime::create(this->animationDelay),
																		cocos2d::CallFunc::create(CC_CALLBACK_0(Animations::AttackingAnimation::notify, this, *new Aspects::Animation::AnimationFinishedAspect())),
																		nullptr);
				}

				AttackingAnimation::~AttackingAnimation() {
				}

				void AttackingAnimation::animationFunction() {
					std::string textureName;
					if (this->sense == Sense::RIGHT) {
						textureName.append("RyunosukeAttack");
						textureName.append(this->to_string(this->texturesIndex++%this->texturesNumber));
						textureName.append("D.png");
					}
					else if (this->sense == Sense::LEFT) {
						textureName.append("RyunosukeAttack");
						textureName.append(this->to_string(this->texturesIndex++%this->texturesNumber));
						textureName.append("I.png");
					}
					this->character.setTexture(textureName);
				}

			}
		}
	}
}