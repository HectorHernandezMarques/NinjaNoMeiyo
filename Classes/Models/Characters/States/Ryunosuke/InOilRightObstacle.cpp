#include "./InOilRightObstacle.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace States {
				namespace Ryunosuke {

					InOilRightObstacle::InOilRightObstacle(Characters::Ryunosuke &ryunosuke) : State(), ryunosuke(ryunosuke) {
					}

					InOilRightObstacle::~InOilRightObstacle() {
					}

					void InOilRightObstacle::move(Sense sense) {
						if (sense == Sense::RIGHT) {
							this->ryunosuke.setVelocityLimit(cocos2d::PHYSICS_INFINITY);
							this->ryunosuke.setVelocity(cocos2d::Vec2::ZERO);
						}
						else {
							this->ryunosuke.setVelocityLimit(cocos2d::PHYSICS_INFINITY);
							this->ryunosuke.setVelocity(cocos2d::Vec2(static_cast<int>(sense) * this->xVelocityMovement, this->ryunosuke.getVelocity().y));
						}
					}

					Animations::Animation* InOilRightObstacle::moveAnimation(Sense sense) {
						Animations::Animation *result = nullptr;

						if (sense == Sense::RIGHT) {
							result = new Animations::ClimbingOilAnimation(this->ryunosuke, sense);
						}
						else {
							result = new Animations::MovingAnimation(this->ryunosuke, sense);
						}

						return result;
					}

					void InOilRightObstacle::stop(Sense sense) {
						this->ryunosuke.setVelocityLimit(cocos2d::PHYSICS_INFINITY);
						this->ryunosuke.setVelocity(cocos2d::Vec2(0.0, this->ryunosuke.getVelocity().y));
					}

					Animations::Animation* InOilRightObstacle::stopAnimation(Sense sense) {
						Animations::ClimbingOilAnimation &animation = *new Animations::ClimbingOilAnimation(this->ryunosuke, sense);
						return &animation;
					}

					void InOilRightObstacle::jump(Sense sense) {
						if (sense == Sense::RIGHT) {
							this->ryunosuke.setVelocityLimit(cocos2d::PHYSICS_INFINITY);
						}
						else {
							this->ryunosuke.setVelocityLimit(cocos2d::PHYSICS_INFINITY);
							this->ryunosuke.setVelocity(cocos2d::Vec2(static_cast<int>(sense) * this->xVelocityMovement, this->yVelocityJumpWall));
						}
					}

					Animations::Animation* InOilRightObstacle::jumpAnimation(Sense sense) {
						Animations::Animation *result = nullptr;

						if (sense == Sense::RIGHT) {
							result = new Animations::JumpingOnWallAnimation(this->ryunosuke, sense);
						}
						else {
							result = new Animations::JumpingAnimation(this->ryunosuke, sense);
						}

						return result;
					}

					void InOilRightObstacle::attack(Sense sense) {
						this->ryunosuke.setVelocityLimit(cocos2d::PHYSICS_INFINITY);
						this->ryunosuke.setVelocity(cocos2d::Vec2::ZERO);
					}

					Animations::Animation* InOilRightObstacle::attackAnimation(Sense sense) {
						Animations::AttackingAnimation &animation = *new Animations::AttackingAnimation(this->ryunosuke, sense);
						return &animation;
					}

				}
			}
		}
	}
}