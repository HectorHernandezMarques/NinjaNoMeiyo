#include "./ClimbingOilAnimation.h"
#include "../Character.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace Animations {

				ClimbingOilAnimation::ClimbingOilAnimation(Character &character, Sense sense) : Animation(character, sense, 2, 0.15, AnimationIndex::CLIMBING_OIL) {
					this->animationAction = cocos2d::RepeatForever::create(cocos2d::Sequence::create(cocos2d::CallFunc::create(CC_CALLBACK_0(Animations::ClimbingOilAnimation::animationFunction, this)),
																										cocos2d::DelayTime::create(this->animationDelay),
																										nullptr));
				}

				ClimbingOilAnimation::~ClimbingOilAnimation() {

				}

				void ClimbingOilAnimation::animationFunction() {
					std::string textureName;
					if (this->sense == Sense::RIGHT) {
						textureName.append("RyunosukeClimbOil");
						textureName.append(this->to_string(this->texturesIndex++%this->texturesNumber));
						textureName.append("D.png");
					}
					else if (this->sense == Sense::LEFT) {
						textureName.append("RyunosukeClimbOil");
						textureName.append(this->to_string(this->texturesIndex++%this->texturesNumber));
						textureName.append("I.png");
					}
					this->character.setTexture(textureName);
				}
			}
		}
	}
}