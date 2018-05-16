#include "./InLeftObstacle.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace States {
				namespace Ryunosuke {

					InLeftObstacle::InLeftObstacle(Characters::Ryunosuke &ryunosuke) : State(), ryunosuke(ryunosuke) {
					}

					InLeftObstacle::~InLeftObstacle() {
					}

					void InLeftObstacle::move(Sense sense) {
						if (sense == Sense::RIGHT) {
							this->ryunosuke.setVelocityLimit(cocos2d::PHYSICS_INFINITY);
							this->ryunosuke.setVelocity(cocos2d::Vec2(static_cast<int>(sense) * this->xVelocityMovement, this->ryunosuke.getVelocity().y));
						}
						else {
							this->ryunosuke.setVelocityLimit(RYUNOSUKE_WALL_SPEED);
							this->ryunosuke.setVelocity(cocos2d::Vec2::ZERO);
						}
					}

					Animations::Animation* InLeftObstacle::moveAnimation(Sense sense) {
						Animations::Animation *result = nullptr;

						if (sense == Sense::RIGHT) {
							result = new Animations::MovingAnimation(this->ryunosuke, sense);
						}
						else {
							result = new Animations::ClimbingAnimation(this->ryunosuke, sense);
						}

						return result;
					}

					void InLeftObstacle::stop(Sense sense) {
						this->ryunosuke.setVelocityLimit(cocos2d::PHYSICS_INFINITY);
						this->ryunosuke.setVelocity(cocos2d::Vec2(0.0, this->ryunosuke.getVelocity().y));
					}

					Animations::Animation* InLeftObstacle::stopAnimation(Sense sense) {
						Animations::ClimbingOilAnimation &animation = *new Animations::ClimbingOilAnimation(this->ryunosuke, sense);
						return &animation;
					}

					void InLeftObstacle::jump(Sense sense) {
						if (sense == Sense::RIGHT) {
							this->ryunosuke.setVelocityLimit(cocos2d::PHYSICS_INFINITY);
							this->ryunosuke.setVelocity(cocos2d::Vec2(static_cast<int>(sense) * this->xVelocityMovement, this->yVelocityJumpWall));
						}
						else {
							this->ryunosuke.setVelocityLimit(cocos2d::PHYSICS_INFINITY);
							this->ryunosuke.setVelocity(cocos2d::Vec2(0.0, this->yVelocityJumpWall));
						}
					}

					Animations::Animation* InLeftObstacle::jumpAnimation(Sense sense) {
						Animations::Animation *result = nullptr;

						if (sense == Sense::RIGHT) {
							result = new Animations::JumpingAnimation(this->ryunosuke, sense);
						}
						else {
							result = new Animations::JumpingOnWallAnimation(this->ryunosuke, sense);
						}

						return result;
					}

					void InLeftObstacle::attack(Sense sense) {
						this->ryunosuke.setVelocityLimit(cocos2d::PHYSICS_INFINITY);
						this->ryunosuke.setVelocity(cocos2d::Vec2::ZERO);
					}

					Animations::Animation* InLeftObstacle::attackAnimation(Sense sense) {
						Animations::AttackingAnimation &animation = *new Animations::AttackingAnimation(this->ryunosuke, sense);
						return &animation;
					}

				}
			}
		}
	}
}