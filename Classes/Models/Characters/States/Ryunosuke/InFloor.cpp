#include "./InFloor.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace States {
				namespace Ryunosuke {

					InFloor::InFloor(Characters::Ryunosuke &ryunosuke) : State(), ryunosuke(ryunosuke) {
					}

					InFloor::~InFloor() {
					}

					void InFloor::move(Sense sense) {
						this->ryunosuke.setVelocityLimit(cocos2d::PHYSICS_INFINITY);
						this->ryunosuke.setVelocity(cocos2d::Vec2(static_cast<int>(sense) * this->xVelocityMovement, 0.0));
					}

					cocos2d::Action* InFloor::moveAnimation(Sense sense) {
						Animations::MovingAnimation &animation = *new Animations::MovingAnimation(this->ryunosuke, sense);
						return animation.animate();
					}

					void InFloor::stop(Sense sense) {
						this->ryunosuke.setVelocityLimit(cocos2d::PHYSICS_INFINITY);
						this->ryunosuke.setVelocity(cocos2d::Vec2::ZERO);
					}

					cocos2d::Action* InFloor::stopAnimation(Sense sense) {
						Animations::StoppedAnimation &animation = *new Animations::StoppedAnimation(this->ryunosuke, sense);
						return animation.animate();
					}

					void InFloor::jump(Sense sense) {
						this->ryunosuke.setVelocityLimit(cocos2d::PHYSICS_INFINITY);
						this->ryunosuke.setVelocity(cocos2d::Vec2(static_cast<int>(sense) * this->xVelocityMovement, this->yVelocityJumpFloor));
					}

					cocos2d::Action* InFloor::jumpAnimation(Sense sense) {
						Animations::JumpingAnimation &animation = *new Animations::JumpingAnimation(this->ryunosuke, sense);
						return animation.animate();
					}

					void InFloor::attack(Sense sense) {

					}

					cocos2d::Action* InFloor::attackAnimation(Sense sense) {
						Animations::AttackingAnimation &animation = *new Animations::AttackingAnimation(this->ryunosuke, sense);
						return animation.animate();
					}

				}
			}
		}
	}
}