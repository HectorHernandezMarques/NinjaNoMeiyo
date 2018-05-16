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

					Animations::Animation* InRightObstacle::moveAnimation(Sense sense) {
						Animations::Animation *result = nullptr;

						if (sense == Sense::RIGHT) {
							result = new Animations::ClimbingAnimation(this->ryunosuke, sense);
						}
						else {
							result = new Animations::MovingAnimation(this->ryunosuke, sense);
						}

						return result;
					}

					void InRightObstacle::stop(Sense sense) {
						this->ryunosuke.setVelocityLimit(cocos2d::PHYSICS_INFINITY);
						this->ryunosuke.setVelocity(cocos2d::Vec2(0.0, this->ryunosuke.getVelocity().y));
					}

					Animations::Animation* InRightObstacle::stopAnimation(Sense sense) {
						Animations::ClimbingOilAnimation &animation = *new Animations::ClimbingOilAnimation(this->ryunosuke, sense);
						return &animation;
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

					Animations::Animation* InRightObstacle::jumpAnimation(Sense sense) {
						Animations::Animation *result = nullptr;

						if (sense == Sense::RIGHT) {
							result = new Animations::JumpingOnWallAnimation(this->ryunosuke, sense);
						}
						else {
							result = new Animations::JumpingAnimation(this->ryunosuke, sense);
						}

						return result;
					}

					void InRightObstacle::attack(Sense sense) {
						this->ryunosuke.setVelocityLimit(cocos2d::PHYSICS_INFINITY);
						this->ryunosuke.setVelocity(cocos2d::Vec2::ZERO);
					}

					Animations::Animation* InRightObstacle::attackAnimation(Sense sense) {
						Animations::AttackingAnimation &animation = *new Animations::AttackingAnimation(this->ryunosuke, sense);
						return &animation;
					}

				}
			}
		}
	}
}