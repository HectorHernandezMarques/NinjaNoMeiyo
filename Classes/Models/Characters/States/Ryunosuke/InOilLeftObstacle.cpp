#include "./InOilLeftObstacle.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace States {
				namespace Ryunosuke {

					InOilLeftObstacle::InOilLeftObstacle(Characters::Ryunosuke &ryunosuke) : State(), ryunosuke(ryunosuke) {
					}

					InOilLeftObstacle::~InOilLeftObstacle() {
					}

					void InOilLeftObstacle::move(Sense sense) {
						if (sense == Sense::RIGHT) {
							this->ryunosuke.setVelocityLimit(cocos2d::PHYSICS_INFINITY);
							this->ryunosuke.setVelocity(cocos2d::Vec2(static_cast<int>(sense) * this->xVelocityMovement, this->ryunosuke.getVelocity().y));
						}
						else {
							this->ryunosuke.setVelocityLimit(cocos2d::PHYSICS_INFINITY);
							this->ryunosuke.setVelocity(cocos2d::Vec2::ZERO);
						}
					}

					Animations::Animation* InOilLeftObstacle::moveAnimation(Sense sense) {
						Animations::Animation *result = nullptr;

						if (sense == Sense::RIGHT) {
							result = new Animations::MovingAnimation(this->ryunosuke, sense);
						}
						else {
							result = new Animations::ClimbingOilAnimation(this->ryunosuke, sense);
						}

						return result;
					}

					void InOilLeftObstacle::stop(Sense sense) {
						this->ryunosuke.setVelocityLimit(cocos2d::PHYSICS_INFINITY);
						this->ryunosuke.setVelocity(cocos2d::Vec2(0.0, this->ryunosuke.getVelocity().y));
					}

					Animations::Animation* InOilLeftObstacle::stopAnimation(Sense sense) {
						Animations::ClimbingOilAnimation &animation = *new Animations::ClimbingOilAnimation(this->ryunosuke, sense);
						return &animation;
					}

					void InOilLeftObstacle::jump(Sense sense) {
						if (sense == Sense::RIGHT) {
							this->ryunosuke.setVelocityLimit(cocos2d::PHYSICS_INFINITY);
							this->ryunosuke.setVelocity(cocos2d::Vec2(static_cast<int>(sense) * this->xVelocityMovement, this->yVelocityJumpWall));
						}
						else {
							this->ryunosuke.setVelocityLimit(cocos2d::PHYSICS_INFINITY);
						}
					}

					Animations::Animation* InOilLeftObstacle::jumpAnimation(Sense sense) {
						Animations::Animation *result = nullptr;

						if (sense == Sense::RIGHT) {
							result = new Animations::JumpingAnimation(this->ryunosuke, sense);
						}
						else {
							result = new Animations::JumpingOnWallAnimation(this->ryunosuke, sense);
						}

						return result;
					}

					void InOilLeftObstacle::attack(Sense sense) {
						this->ryunosuke.setVelocityLimit(cocos2d::PHYSICS_INFINITY);
						this->ryunosuke.setVelocity(cocos2d::Vec2::ZERO);
					}

					Animations::Animation* InOilLeftObstacle::attackAnimation(Sense sense) {
						Animations::AttackingAnimation &animation = *new Animations::AttackingAnimation(this->ryunosuke, sense);
						return &animation;
					}

				}
			}
		}
	}
}