#include "./MovingAnimation.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace Animations {

				MovingAnimation::MovingAnimation(Character &character, Sense sense) : Animation(character, sense, 3, 0.15, AnimationIndex::MOVING) {
				}

				MovingAnimation::~MovingAnimation() {
				}

				cocos2d::Action* MovingAnimation::animate() {
					cocos2d::Action *action = cocos2d::RepeatForever::create(cocos2d::Sequence::create(cocos2d::CallFunc::create(CC_CALLBACK_0(Animations::MovingAnimation::animationFunction, this)), cocos2d::DelayTime::create(this->animationDelay), nullptr));
					this->character.runAction(action);
					return action;
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