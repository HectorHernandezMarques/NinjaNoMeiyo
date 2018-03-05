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

					void UnknownState::move(Controllers::Sense sense) {
					}

					cocos2d::Action* UnknownState::moveAnimation(Controllers::Sense sense) {
						cocos2d::Action *action = cocos2d::RepeatForever::create(cocos2d::Sequence::create(cocos2d::CallFunc::create(CC_CALLBACK_0(UnknownState::moveAnimationFunction, this, sense)), cocos2d::DelayTime::create(MOVE_ANIMATION_DELAY), nullptr));
						this->ryunosuke.runAction(action);
						return action;
					}

					void UnknownState::stop(Controllers::Sense sense) {
					}

					cocos2d::Action* UnknownState::stopAnimation(Controllers::Sense sense) {
						cocos2d::Action *action = cocos2d::RepeatForever::create(cocos2d::Sequence::create(cocos2d::CallFunc::create(CC_CALLBACK_0(UnknownState::stopAnimationFunction, this, sense)), cocos2d::DelayTime::create(MOVE_ANIMATION_DELAY), nullptr));
						this->ryunosuke.runAction(action);
						return action;
					}

					void UnknownState::jump(Controllers::Sense sense) {
					}

					cocos2d::Action* UnknownState::jumpAnimation(Controllers::Sense sense) {
						cocos2d::Action *action = cocos2d::RepeatForever::create(cocos2d::Sequence::create(cocos2d::CallFunc::create(CC_CALLBACK_0(UnknownState::jumpAnimationFunction, this, sense)), cocos2d::DelayTime::create(MOVE_ANIMATION_DELAY), nullptr));
						this->ryunosuke.runAction(action);
						return action;
					}

					void UnknownState::moveAnimationFunction(Controllers::Sense sense) {
					}

					void UnknownState::stopAnimationFunction(Controllers::Sense sense) {
					}

					void UnknownState::jumpAnimationFunction(Controllers::Sense sense) {
					}
				}
			}
		}
	}
}