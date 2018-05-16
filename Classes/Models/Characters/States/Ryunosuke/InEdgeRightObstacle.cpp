#include "./InEdgeRightObstacle.h"

namespace NinjaNoMeiyo {
	namespace Models {
		namespace Characters {
			namespace States {
				namespace Ryunosuke {

					InEdgeRightObstacle::InEdgeRightObstacle(Characters::Ryunosuke &ryunosuke) : State(), ryunosuke(ryunosuke) {
					}

					InEdgeRightObstacle::~InEdgeRightObstacle() {
					}

					void InEdgeRightObstacle::move(Sense sense) {
						if (sense == Sense::RIGHT) {
							this->ryunosuke.setVelocityLimit(cocos2d::PHYSICS_INFINITY);
							this->ryunosuke.setVelocity(cocos2d::Vec2::ZERO);
						}
						else {
							this->ryunosuke.setVelocityLimit(cocos2d::PHYSICS_INFINITY);
							this->ryunosuke.setVelocity(cocos2d::Vec2(static_cast<int>(sense) * this->xVelocityMovement, this->ryunosuke.getVelocity().y));
						}
					}

					Animations::Animation* InEdgeRightObstacle::moveAnimation(Sense sense) {
						Animations::Animation *result = nullptr;

						if (sense == Sense::RIGHT) {
							result = new Animations::ClimbingOilAnimation(this->ryunosuke, sense);
						}
						else {
							result = new Animations::MovingAnimation(this->ryunosuke, sense);
						}

						return result;
					}

					void InEdgeRightObstacle::stop(Sense sense) {
						this->ryunosuke.setVelocityLimit(cocos2d::PHYSICS_INFINITY);
						this->ryunosuke.setVelocity(cocos2d::Vec2(0.0, this->ryunosuke.getVelocity().y));
					}

					Animations::Animation* InEdgeRightObstacle::stopAnimation(Sense sense) {
						Animations::ClimbingOilAnimation &animation = *new Animations::ClimbingOilAnimation(this->ryunosuke, sense);
						return &animation;
					}

					void InEdgeRightObstacle::jump(Sense sense) {
						if (sense == Sense::RIGHT) {
							this->ryunosuke.setVelocityLimit(cocos2d::PHYSICS_INFINITY);
							this->ryunosuke.setVelocity(cocos2d::Vec2(0.0, this->yVelocityJumpWall));
						}
						else {
							this->ryunosuke.setVelocityLimit(cocos2d::PHYSICS_INFINITY);
							this->ryunosuke.setVelocity(cocos2d::Vec2(static_cast<int>(sense) * this->xVelocityMovement, this->yVelocityJumpWall));
						}
					}

					Animations::Animation* InEdgeRightObstacle::jumpAnimation(Sense sense) {
						Animations::Animation *result = nullptr;

						if (sense == Sense::RIGHT) {
							result = new Animations::JumpingOnWallAnimation(this->ryunosuke, sense);
						}
						else {
							result = new Animations::JumpingAnimation(this->ryunosuke, sense);
						}

						return result;
					}

					void InEdgeRightObstacle::attack(Sense sense) {
						this->ryunosuke.setVelocityLimit(cocos2d::PHYSICS_INFINITY);
						this->ryunosuke.setVelocity(cocos2d::Vec2::ZERO);
					}

					Animations::Animation* InEdgeRightObstacle::attackAnimation(Sense sense) {
						Animations::AttackingAnimation &animation = *new Animations::AttackingAnimation(this->ryunosuke, sense);
						return &animation;
					}
				}
			}
		}
	}
}