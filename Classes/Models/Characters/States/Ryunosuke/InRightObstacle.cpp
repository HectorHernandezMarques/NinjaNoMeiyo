#include "./InRightObstacle.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace States {
				namespace Ryunosuke {

					InRightObstacle::InRightObstacle(Characters::Ryunosuke &ryunosuke) : State(), ryunosuke(ryunosuke) {
					}

					InRightObstacle::~InRightObstacle() {
					}

					void InRightObstacle::move(Sense sense) {
						if (sense == Sense::RIGHT) {
							this->ryunosuke.setVelocityLimit(RYUNOSUKE_WALL_SPEED);
							this->ryunosuke.setVelocity(cocos2d::Vec2::ZERO);
						}
						else {
							this->ryunosuke.setVelocityLimit(cocos2d::PHYSICS_INFINITY);
							this->ryunosuke.setVelocity(cocos2d::Vec2(static_cast<int>(sense) * this->xVelocityMovement, this->ryunosuke.getVelocity().y));
						}
					}

					cocos2d::Action* InRightObstacle::moveAnimation(Sense sense) {
						Animations::Animation *animation = nullptr;
						cocos2d::Action* result = nullptr;

						if (sense == Sense::RIGHT) {
							animation = new Animations::ClimbingAnimation(this->ryunosuke, sense);
							result = animation->animate();
						}
						else {
							animation = new Animations::MovingAnimation(this->ryunosuke, sense);
							result = animation->animate();
						}

						return result;
					}

					void InRightObstacle::stop(Sense sense) {
						this->ryunosuke.setVelocityLimit(cocos2d::PHYSICS_INFINITY);
						this->ryunosuke.setVelocity(cocos2d::Vec2(0.0, this->ryunosuke.getVelocity().y));
					}

					cocos2d::Action* InRightObstacle::stopAnimation(Sense sense) {
						Animations::StoppedAnimation &animation = *new Animations::StoppedAnimation(this->ryunosuke, sense);
						return animation.animate();
					}

					void InRightObstacle::jump(Sense sense) {
						if (sense == Sense::RIGHT) {
							this->ryunosuke.setVelocityLimit(cocos2d::PHYSICS_INFINITY);
							this->ryunosuke.setVelocity(cocos2d::Vec2(0.0, this->yVelocityJumpWall));
						}
						else {
							this->ryunosuke.setVelocityLimit(cocos2d::PHYSICS_INFINITY);
							this->ryunosuke.setVelocity(cocos2d::Vec2(static_cast<int>(sense) * this->xVelocityMovement, this->yVelocityJumpWall));
						}
					}

					cocos2d::Action* InRightObstacle::jumpAnimation(Sense sense) {
						Animations::JumpingAnimation &animation = *new Animations::JumpingAnimation(this->ryunosuke, sense);
						return animation.animate();
					}

					void InRightObstacle::attack(Sense sense) {

					}

					cocos2d::Action* InRightObstacle::attackAnimation(Sense sense) {
						Animations::AttackingAnimation &animation = *new Animations::AttackingAnimation(this->ryunosuke, sense);
						return animation.animate();
					}

				}
			}
		}
	}
}