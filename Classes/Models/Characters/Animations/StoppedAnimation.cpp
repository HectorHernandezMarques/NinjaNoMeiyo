#include "./StoppedAnimation.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace Animations {

				StoppedAnimation::StoppedAnimation(Character &character, Sense sense) : Animation(character, sense, 2, 0.35, AnimationIndex::STOPPED) {
				}

				StoppedAnimation::~StoppedAnimation() {
				}

				cocos2d::Action* StoppedAnimation::animate() {
					cocos2d::Action *action = cocos2d::RepeatForever::create(cocos2d::Sequence::create(cocos2d::CallFunc::create(CC_CALLBACK_0(Animations::StoppedAnimation::animationFunction, this)), cocos2d::DelayTime::create(this->animationDelay), nullptr));
					this->character.runAction(action);
					return action;
				}

				void StoppedAnimation::animationFunction() {
					std::string textureName;
					if (this->sense == Sense::RIGHT) {
						textureName.append("RyunosukeStop");
						textureName.append(this->to_string(this->texturesIndex++%this->texturesNumber));
						textureName.append("D.png");
					}
					else if (this->sense == Sense::LEFT) {
						textureName.append("RyunosukeStop");
						textureName.append(this->to_string(this->texturesIndex++%this->texturesNumber));
						textureName.append("I.png");
					}
					this->character.setTexture(textureName);
				}

			}
		}
	}
}