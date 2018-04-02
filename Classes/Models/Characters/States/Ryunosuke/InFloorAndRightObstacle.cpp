#include "./InFloorAndRightObstacle.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace States {
				namespace Ryunosuke {

					InFloorAndRightObstacle::InFloorAndRightObstacle(Characters::Ryunosuke &ryunosuke) : State(), ryunosuke(ryunosuke) {
					}

					InFloorAndRightObstacle::~InFloorAndRightObstacle() {
					}

					void InFloorAndRightObstacle::move(Sense sense) {
						if (sense == Sense::RIGHT) {
							this->ryunosuke.setVelocityLimit(cocos2d::PHYSICS_INFINITY);
							this->ryunosuke.setVelocity(cocos2d::Vec2::ZERO);
						}
						else {
							this->ryunosuke.setVelocityLimit(cocos2d::PHYSICS_INFINITY);
							this->ryunosuke.setVelocity(cocos2d::Vec2(static_cast<int>(sense) * this->xVelocityMovement, this->ryunosuke.getVelocity().y));
						}
					}

					cocos2d::Action* InFloorAndRightObstacle::moveAnimation(Sense sense) {
						Animations::MovingAnimation &animation = *new Animations::MovingAnimation(this->ryunosuke, sense);
						return animation.animate();
					}

					void InFloorAndRightObstacle::stop(Sense sense) {
						this->ryunosuke.setVelocityLimit(cocos2d::PHYSICS_INFINITY);
						this->ryunosuke.setVelocity(cocos2d::Vec2::ZERO);
					}

					cocos2d::Action* InFloorAndRightObstacle::stopAnimation(Sense sense) {
						Animations::StoppedAnimation &animation = *new Animations::StoppedAnimation(this->ryunosuke, sense);
						return animation.animate();
					}

					void InFloorAndRightObstacle::jump(Sense sense) {
						if (sense == Sense::RIGHT) {
							this->ryunosuke.setVelocityLimit(cocos2d::PHYSICS_INFINITY);
							this->ryunosuke.setVelocity(cocos2d::Vec2(0.0, this->yVelocityJumpWall));
						}
						else {
							this->ryunosuke.setVelocityLimit(cocos2d::PHYSICS_INFINITY);
							this->ryunosuke.setVelocity(cocos2d::Vec2(static_cast<int>(sense) * this->xVelocityMovement, this->yVelocityJumpFloor));
						}
					}

					cocos2d::Action* InFloorAndRightObstacle::jumpAnimation(Sense sense) {
						Animations::JumpingAnimation &animation = *new Animations::JumpingAnimation(this->ryunosuke, sense);
						return animation.animate();
					}

					void InFloorAndRightObstacle::attack(Sense sense) {

					}

					cocos2d::Action* InFloorAndRightObstacle::attackAnimation(Sense sense) {
						Animations::AttackingAnimation &animation = *new Animations::AttackingAnimation(this->ryunosuke, sense);
						return animation.animate();
					}
				}
			}
		}
	}
}