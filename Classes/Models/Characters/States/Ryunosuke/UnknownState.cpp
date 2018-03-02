#include "./UnknownState.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace States {
				namespace Ryunosuke {

					UnknownState::UnknownState(Characters::Ryunosuke &ryunosuke) : State(), ryunosuke(ryunosuke) {
					}

					UnknownState::~UnknownState() {
					}

					void UnknownState::move(float xVelocity) {
					}

					cocos2d::Action* UnknownState::moveAnimation(float xVelocity) {
						cocos2d::Action *action = cocos2d::RepeatForever::create(cocos2d::Sequence::create(cocos2d::CallFunc::create(CC_CALLBACK_0(UnknownState::moveAnimationFunction, this, xVelocity)), cocos2d::DelayTime::create(MOVE_ANIMATION_DELAY), nullptr));
						ryunosuke.runAction(action);
						return action;
					}

					cocos2d::Action* UnknownState::stopAnimation(float xVelocity) {
						cocos2d::Action *action = cocos2d::RepeatForever::create(cocos2d::Sequence::create(cocos2d::CallFunc::create(CC_CALLBACK_0(UnknownState::stopAnimationFunction, this, xVelocity)), cocos2d::DelayTime::create(MOVE_ANIMATION_DELAY), nullptr));
						ryunosuke.runAction(action);
						return action;
					}

					void UnknownState::stop(float xVelocity) {
					}

					void UnknownState::moveAnimationFunction(float xVelocity) {
					}

					void UnknownState::stopAnimationFunction(float xVelocity) {
					}
				}
			}
		}
	}
}