#include "./AttackingAnimation.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace Animations {

				AttackingAnimation::AttackingAnimation(Character &character, Sense sense) : Animation(character, sense, 1, 0.35, AnimationIndex::STOPPED) {
				}

				AttackingAnimation::~AttackingAnimation() {
				}

				cocos2d::Action* AttackingAnimation::animate() {
					cocos2d::Action *action = cocos2d::RepeatForever::create(cocos2d::Sequence::create(cocos2d::CallFunc::create(CC_CALLBACK_0(Animations::AttackingAnimation::animationFunction, this)), cocos2d::DelayTime::create(this->animationDelay), nullptr));
					this->character.runAction(action);
					return action;
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